import rospy
import sys
import copy
import rospy
from moveit_commander import *
import geometry_msgs.msg
import tf2_geometry_msgs
import tf2_ros
import tf.transformations
import math
from std_msgs.msg import Bool,Float64MultiArray, MultiArrayLayout, MultiArrayDimension,String,Int32
import json
import torch
import numpy as np
import cv2
import numpy as np

sys.path.append("/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/yolov7")
from CentralNode.msg import node_response
from enums.response_status import Response
from enums.nodes import Nodes
from enums.operations import OPERATIONS
from enums.topics import Topics

from models.experimental import attempt_load
from utils.datasets import LoadImages, letterbox
from utils.torch_utils import TracedModel,select_device
from utils.general import  non_max_suppression, scale_coords

#camera imports:
import pyrealsense2 as rs
import open3d as o3d
import numpy as np
import time

# importing robot helper for coordinates view transformation 
sys.path.append("/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/resources/src/helper")
from helper.robot_helper import RobotControl, frames_transformations
import numpy as np
import tf.transformations
#Robot Control imports

class PerceptionNode():
    
    def __init__(self, width=1280, height=720,useTemporalFilter=True,useHoleFilling=False) -> None:
        # self.perceptionNode = rospy.init_node("Perception") # Need to change this to the enum values 
        self.perceptionPublisher = rospy.Publisher(Topics.SCREW_LIST.value, node_response, queue_size=50) # Need to change this to the enum values
        self.nodeToOperateListener = rospy.Subscriber(Topics.NODE_TO_OPERATE.value,Int32,self.nodeToOperateCallback)
       
        #CAD related parameters
        self.start_position=[0.3162318772410906, 0.00527568967887596, 0.37, -3.1415189863509134, 0.007510451851129454, 1.7006139777966402e-05]
        self.xErr=0.00
        self.yErr=0.013
        self.zErr=-0.02

        self.Controller=RobotControl(node_name="Perception",group_name="ScrewIn")
        self.framesTransformer=frames_transformations()
        self.rate = rospy.Rate(200)
        #camera viewing dimensions
        self.Width = width
        self.Height = height
        self.operate = False
        self.model = None


        #configuring filters usage
        self.useTemporalFilter=useTemporalFilter
        self.useHoleFilling=useHoleFilling

    def nodeToOperateCallback(self,data):
        if data==1:
            self.operate = True
        else: 
            self.operate = False
    def loadModel(self, location="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/Perception/src/epoch_480.pt"): 
        #load model 
        intialModel = attempt_load(location, "cpu")
        self.model = TracedModel(intialModel, "cpu", 640)

    def InitializeCamera(self):
        # Configure camera streams
        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.config.enable_stream(rs.stream.color, 1280, 720, rs.format.bgr8, 10)
        self.config.enable_stream(rs.stream.depth, 848, 480, rs.format.z16, 6)
        self.pipeline.start(self.config)

        self.aligned_stream = rs.align(rs.stream.color) # alignment between color and depth
        self.point_cloud = rs.pointcloud()

        ## Configure Camera Filters:
        
        self.temporalFilter = rs.temporal_filter()
        self.holeFillingFilter = rs.hole_filling_filter()
        

    def imagePreprocess(self):
        frames = self.pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()
        
        self.color_image = np.asanyarray(color_frame.get_data())
        
        frames = self.aligned_stream.process(frames)
        depth_frame = frames.get_depth_frame()

        ## depth enhancement using temporal filtering and hole filling
        if self.useTemporalFilter:
            depth_frame = self.temporalFilter.process(depth_frame)
        if self.useHoleFilling:
            depth_frame = self.holeFillingFilter.process(depth_frame)
        ####
        df = np.asarray(depth_frame.get_data()) # Not used ?
        points = self.point_cloud.calculate(depth_frame)
        verts = np.asanyarray(points.get_vertices()).view(np.float32).reshape(-1, self.Width, 3)  # xyz

        image = self.color_image
        #preprocesses the image and makes the image size a multiple of the stride size,resizes the image
        image = letterbox(image)[0]

        #transpose from cv2 bgr to rgb
        image = image[:, :, ::-1].transpose(2, 0, 1)
        image = np.ascontiguousarray(image)
        image = torch.from_numpy(image).float()
        image /= 255.0
        image.unsqueeze(0)
        image = image[None,:,:,:]

        return image, verts
    
    def modelInference(self, image):
        with torch.no_grad():   # Calculating gradients would cause a GPU memory leak
            output = self.model(image, False)[0]

        pred = non_max_suppression(output)
       
        predresults = pred[0]
        #predresults format: (xtl,ytl,xbr,ybr,conf,class)
        predresults[:, :4] = scale_coords(image.shape[2:], predresults[:, :4], self.color_image.shape).round()

        return predresults
    
    def pixelToSpace(self, predresults, verts ,debug=False):
        screwlist=[]
        # print('predresults are')
        # print(predresults)
        for predresult in predresults:
            # Blue color in BGR
            color = (255, 0, 0)
            # print('predres value is {}'.format(predresult))
            centerx = int((predresult[0] + predresult[2])) // 2
            centery = int((predresult[1] + predresult[3])) // 2
            # print('center val is  {},{}',centerx,centery)
            xyz_position = verts[centery][centerx]
            xyz_position = [float(xyz_position[0]), float(xyz_position[1]), float(xyz_position[2])]
            # print(xyz_position[2])
            screwlist.append(xyz_position)
            rc = cv2.rectangle(self.color_image, (int(predresult[0]), int(predresult[1])), (int(predresult[2]), int(predresult[3])), color, 2) # Not used ?

        if debug:
            cv2.imshow('myimg', self.color_image)
            cv2.waitKey(1)

        return screwlist
    
 
    def camToWorldPositions(self, x, y ,z, verbose=False):
        
        self.framesTransformer.put_frame_static_frame(parent_frame_name="camera_link",child_frame_name="static",frame_coordinate=[x,y,z,3.14141457586858, -1.5697755396280457, 0.0009377635141111193])
        relative_transformations = self.framesTransformer.transform(parent_id="base_link", child_frame_id='static')#chid id might be wrong
        
        
        return relative_transformations
    
    def publishReadings(self, Data):
        my_msg = node_response()
        my_msg.nodeId=OPERATIONS.index(Nodes.VISION)
        my_msg.status=Response.SUCCESSFULL.value
        my_msg.extraMessage = json.dumps(Data)
        self.perceptionPublisher.publish(my_msg)

    def launchNode(self):
        self.loadModel()
        self.InitializeCamera()

        while not rospy.is_shutdown():
            if self.operate:
                ## Camera Readings
                ImageData, verts = self.imagePreprocess()
                ## Model inference on image data
                predictions = self.modelInference(ImageData)
                ## Get Positions in the space of camera
                screwPositionsToCamera = self.pixelToSpace(predictions, verts,debug=True)
                ## Get Positions relative to the base link
                screwPositions = list()
                
                for screwPosition in screwPositionsToCamera:
                    alignedScrewPosition = self.swap(screwPosition)
                    screwPositions.append(self.camToWorldPositions(alignedScrewPosition[0], alignedScrewPosition[1], alignedScrewPosition[2]))
                # Publish readings
                
                print('positions are')
                print(screwPositions)
            else:

                screwlist=self.scan(3)        
                screwlist=self.identifyScrewsNoRepetitions(screwlist)
                screwlist=self.resolve_dimensional_errors(screwlist)
                print('******************************')
                print('final screw list is :')
                print(screwlist)
                print('******************************')

                for pose in screwlist:
                    print(pose)
                    # self.Controller.go_to_pose_goal_cartesian(pose,0.1,0.1,Replanning=True ,WaitFlag=False)
                self.publishReadings(screwlist)
                self.rate.sleep()
                break
    def scan(self, scantimes) -> list:
        self.Controller.go_to_pose_goal_cartesian(self.start_position,0.1,0.1,Replanning=False,WaitFlag=True)
        pose = self.Controller.get_pose()
        #limits and steps
        limit = 0.1
        xlimit = 0.30
        step = (2 * limit) / scantimes
        xstep = 0.05
        waypoints = []
        limit = -limit
        y = limit
        x = xlimit
        # generate waypoints for scanning
        second_diagonal=[]
        for i in range(scantimes):
            newpose = pose.copy()  # Create a copy of the pose list
            newpose[1] = round(y,2)
            newpose[0] = round(x,3)
            newposey=newpose.copy()
            newposey[1] = round(-y,2)
            second_diagonal.append(newposey)
            print('pose generated before is {}'.format(newpose))
            waypoints.append(newpose)
            print('pose generated after is {}'.format(newpose))
            y+= step
            x+= xstep
        waypoints.extend(second_diagonal)
        # predictions from each pose will be in format of list of lists of predictions for poses
        predictions = []
        for pose in waypoints:
            # for each pose make a predictions list 
            screwPositions = []
            # move to the desired pose
            self.Controller.go_to_pose_goal_cartesian(pose,1,0.5,Replanning=False,WaitFlag=True)
            # capture the image and its point cloud
            image, verts = self.imagePreprocess()
            # take the model inference output of the image
            localpredictions=self.modelInference(image)
            # get positions relative to camera
            screwPositionsToCamera = self.pixelToSpace(localpredictions, verts,debug=True)
            # for each screw in predections
            for screwPosition in screwPositionsToCamera:
                # swap axis according to the cad frame
                alignedScrewPosition = self.swap(screwPosition)
                # determine the world position of the given screw
                screwPositions.append(self.camToWorldPositions(alignedScrewPosition[0], alignedScrewPosition[1], alignedScrewPosition[2]))
            # add pose predictions to global list
            predictions.append(screwPositions)
            
        return predictions
    
    def resolve_dimensional_errors(self,screwlist):
        newlist=[]
        for pose in screwlist:
            pose=list(pose)
            pose[0]+=self.xErr
            pose[1]+=self.yErr
            pose[2]+=self.zErr
            pose[0]=pose[0]#round(pose[0],4)
            pose[1]=pose[1]#round(pose[1],4)
            pose[2]=pose[2]#round(pose[2],4)
            newlist.append(pose)
        return newlist
    def identifyScrewsNoRepetitions2(self,predictions: list,tolerance=0.02) -> list:
       
        unique_screws = []
        for prediction_list in predictions:
            
            for element in prediction_list:
                x, y, z = element[:3]
                found = False
                for i in range(len(unique_screws)):
                    screw = unique_screws[i]
                    index = -1
                    if (screw[0]*x>0 and screw[1]*y>0) and (abs(screw[0] - x) <= tolerance and abs(screw[1] - y) <= tolerance):
                        found = True
                        index = i
                        break
                if found:
                    
                    average_x = (screw[0] + x) / 2
                    average_y = (screw[1] + y) / 2
                    average_z = (screw[2] + z) / 2
                    average_pose=[average_x,average_y,average_z]
                    # adding angles
                    average_pose.extend(screw[3:])
                    if index != -1:
                        unique_screws.pop(index)
                    unique_screws.append(average_pose)
                else:
                    unique_screws.append(element)
        
        return unique_screws

    def identifyScrewsNoRepetitions(self, poseList, thershold=0.02):

        globalList = poseList[0]
        map = {}

        for i in range (1,len(poseList)):
            screwList = poseList[i]
            newList = []

            for j in range(len(screwList)):
                matched = False

                for index, point in enumerate(globalList):
                    if (self.calculateDistance(point,screwList[j]) < thershold ):
                        matched = True
                        if index in map:
                            map[index].append((i,j))
                        else:
                            map[index] = [(i,j)]
                        break
                if not matched:  
                    newList.append(screwList[j])
            globalList.extend(newList)
        data = []
        for index, item in enumerate(globalList):
            if index in map:
                avX, avY, avZ = item[0:3]
                for copy in map[index]:
                    x,y,z = poseList[copy[0]][copy[1]][0:3]
                    avX += x
                    avY += y
                    avZ += z
                avX /= len(map[index]) + 1
                avY /= len(map[index]) + 1
                avZ /= len(map[index]) + 1
                temp = [avX,avY,avZ]
                temp.extend(item[3:])
                data.append(temp)
            else :
                data.append(item)
        return data
    def calculateDistance(self, pos1, pos2):

        x1, y1, z1 =  pos1[0:3]

        x2, y2, z2 =  pos2[0:3]

        return math.sqrt((x1-x2)**2 + (y1-y2)**2 + (z1-z2)**2)

    def swap(self,position:list):
        # align realsense axis to camera link axis 
        return[position[2],-position[0],-position[1]]
    def flatten_list(screwList):
        return np.ndarray.flatten(screwList).tolist()
perception=PerceptionNode()
print('going')
poses=[[[-0.3891096361720125, -0.14140713919044348, 0.2658808782237093, -3.124602683849082, -0.03132426481035682, 0.07162559637905236]], [[0.3918651429926565, -0.14010437566336098, 0.2661601810433043, -3.1245015720859857, -0.031367289757117625, 0.07170965843847281]], [], [[0.39608204451047097, -0.13901984749554222, 0.2647303779937681, -3.1245849122485696, -0.03135253569258669, 0.07163470980541461]], [], [], []]
# print('before filtering:')
# for pose in poses:
#     print(pose)
# print('filtered positions are:')
# print(perception.identifyScrewsNoRepetitions(poses))
print('robot pose now is' )
# print(perception.Controller.get_pose())
# perception.launchNode()

perception.Controller.go_to_pose_goal_cartesian(perception.start_position)
for pose in [[0.34711396910828807, 0.10621894401154695, 0.22885591235556224, -3.1234219376433163, -0.019679874207329185, 0.07187405654710521], [0.40780587973352156, 0.01093116080164376, 0.23322380448934996, -3.1234508738028617, -0.019749587089634583, 0.07186512207527078], [0.4797201531101193, 0.11281772950247299, 0.22395172103126423, -3.123443542718829, -0.01972674249810746, 0.07185099583728045], [0.4940959682266605, -0.1782892343819768, 0.12268609233677506, -3.123422181507349, -0.01964091502558812, 0.07185900665258996]]:
    perception.Controller.go_to_pose_goal_cartesian(pose,velocity=0.1,acceleration=0.1,WaitFlag=True)
    time.sleep(0.5)
    curpos=perception.Controller.get_pose()
    curpos[2]+=0.02
    perception.Controller.go_to_pose_goal_cartesian(curpos,velocity=0.1,acceleration=0.1,WaitFlag=True)
# perception.Controller.go_to_pose_goal_cartesian(perception.start_position,1)
# time.sleep(4)
# perception.Controller.go_to_pose_goal_cartesian([0.4237, -0.0047, 0.2493+perception.zErr, -3.1232772777964883, -0.019748814102031206, 0.0718451779134633],1)
# pose=poses[0][0].copy()
# print('final pose is')
# print(pose)
# pose[0]=0.4467591172735064+0.006#(0.3891096361720125+0.3918651429926565+0.39608204451047097)/3
# pose[1]=-0.006646629530442587+0.013#(-0.14140713919044348+-0.14010437566336098+-0.13901984749554222)/3
# pose[2]=0.26666028665252534-0.018
# perception.Controller.go_to_pose_goal_cartesian(pose,0.1,0.1)




########

