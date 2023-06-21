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
from robot_helper import RobotControl, frames_transformations
import numpy as np
import tf.transformations

#Robot Control imports

class PerceptionNode():
    
    def __init__(self, width=1280, height=720) -> None:
        # self.perceptionNode = rospy.init_node("Perception") # Need to change this to the enum values 
        self.perceptionPublisher = rospy.Publisher('ListOfScrews', Float64MultiArray, queue_size=50) # Need to change this to the enum values
        self.nodeToOperateListener = rospy.Subscriber("NodeToOperate",Int32,self.nodeToOperateCallback)
       
        #CAD related parameters
        self.start_position=[0.3162318772410906, 0.00527568967887596, 0.41920871874099996, -3.1415189863509134, 0.007510451851129454, 1.7006139777966402e-05]
        self.xErr=0.006
        self.yErr=0.013
        self.zErr=-0.018

        self.Controller=RobotControl(node_name="Perception",group_name="ScrewIn")
        self.framesTransformer=frames_transformations()
        self.rate = rospy.Rate(200)
        #camera viewing dimensions
        self.Width = width
        self.Height = height
        self.operate = False
        self.model = None
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
        # depth_frame = self.temporalFilter.process(depth_frame)
        # depth_frame = self.holeFillingFilter.process(depth_frame)
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
        my_msg = Float64MultiArray()
        my_msg.data = Data
        self.perceptionPublisher.publish(my_msg)

    def launchNode(self):
        self.loadModel()
        self.InitializeCamera()

        while not rospy.is_shutdown():
            if self.operate:
                ## Camera Readings
                ImageData, verts = self.imagePreprocess()
                # print('image data is ')
                # print(ImageData)
                # print('verts are ')
                # print(verts)
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
                self.publishReadings(screwlist)
                self.rate.sleep()
                break
    def scan(self, scantimes) -> list:
        self.Controller.go_to_pose_goal_cartesian(self.start_position,0.1,0.1,Replanning=False,WaitFlag=True)
        pose = self.Controller.get_pose()
        #limits and steps
        limit = 0.20
        xlimit = 0.20
        step = (2 * limit) / scantimes
        xstep = 0.05
        waypoints = []
        limit = -limit
        y = limit
        x = xlimit
        # generate waypoints for scanning
        for i in range(scantimes):
            newpose = pose.copy()  # Create a copy of the pose list
            newpose[1] = round(y,2)
            newpose[0] = round(x,3)
            print('pose generated before is {}'.format(newpose))
            waypoints.append(newpose)
            print('pose generated after is {}'.format(newpose))
            y+= step
            x+= xstep
        # predictions from each pose will be in format of list of lists of predictions for poses
        predictions = []
        for pose in waypoints:
            # for each pose make a predictions list 
            screwPositions = []
            # move to the desired pose
            self.Controller.go_to_pose_goal_cartesian(pose,0.1,0.1,Replanning=False,WaitFlag=True)
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
        for pose in screwlist:
            pose=list(pose)
            pose[0]+=self.xErr
            pose[1]+=self.yErr
            pose[2]+=self.zErr
        return screwlist
    def identifyScrewsNoRepetitions(self,predictions: list,tolerance=0.02) -> list:
       
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
print(perception.Controller.get_pose())
# perception.launchNode()
perception.Controller.go_to_pose_goal_cartesian([0.453595495268664+perception.xErr, -0.08863000495787196+perception.yErr, 0.2484750388757343+perception.zErr, -3.1232772777964883, -0.019748814102031206, 0.0718451779134633])
# pose=poses[0][0].copy()
# print('final pose is')
# print(pose)
# pose[0]=0.4467591172735064+0.006#(0.3891096361720125+0.3918651429926565+0.39608204451047097)/3
# pose[1]=-0.006646629530442587+0.013#(-0.14140713919044348+-0.14010437566336098+-0.13901984749554222)/3
# pose[2]=0.26666028665252534-0.018
# perception.Controller.go_to_pose_goal_cartesian(pose,0.1,0.1)

