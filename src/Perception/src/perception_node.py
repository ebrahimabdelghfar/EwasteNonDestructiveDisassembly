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
        #self.perceptionNode = rospy.init_node("Perception") # Need to change this to the enum values 
        self.perceptionPublisher = rospy.Publisher('ListOfScrews', String, queue_size=50) # Need to change this to the enum values
        self.nodeToOperateListener = rospy.Subscriber("NodeToOperate",Int32,self.nodeToOperateCallback)
       
        

        self.Controller=RobotControl(node_name="Perception",group_name="NoTool")
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
        self.config.enable_stream(rs.stream.color, 1280, 720, rs.format.bgr8, 6)
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
        depth_frame = self.temporalFilter.process(depth_frame)
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
        # apply transformations and rotations wrt robot
        # translations=relative_transformations[:3]
        
        # rotations = relative_transformations[3:]
        # cam_matrix = np.array([x,y,z,1])
        
        # homogeneous_matrix = tf.transformations.compose_matrix(translate=translations,angles=rotations)
        
       
        # worldpose = np.matmul(homogeneous_matrix,cam_matrix)
        
        return relative_transformations
    
    def publishReadings(self, Data):
        my_msg = String()
        my_msg.data = json.dumps(Data)
        self.perceptionPublisher.publish(my_msg)

    def launchNode(self):
        # self.loadModel()
        # self.InitializeCamera()

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
                mylst=self.scan(5)        
                print('scanning output is ')
                print(mylst)
                self.rate.sleep()
                break
    def scan(self, scantimes) -> list:
        pose = self.Controller.get_pose()
        limit = 0.20
        step = (2 * limit) / scantimes
        waypoints = []

        limit = -limit
        x = limit
        # y = pose[1] + limit

        for i in range(scantimes):
            newpose = pose.copy()  # Create a copy of the pose list
            newpose[0] = x
            # newpose[1] = y
            print('pose generated before is {}'.format(newpose))
            waypoints.append(newpose)
            print('pose generated after is {}'.format(newpose))
            x += step
            # y += step
            print('new x and y are {}, {}'.format(x, y))

        predictions = []
        print('waypoints are:')
        print(waypoints)

        
        # self.Controller.go_by_joint_angle(joint_goal_list=[0,0,0,0,0,0],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)

        for pose in waypoints:
            screwPositions=list()
            # print('pose is ') 
            # print(pose)
            # self.Controller.go_to_pose_goal_cartesian(pose,1,0.2,Replanning=True,WaitFlag=False)
            image, verts = self.imagePreprocess()
            predictions=self.modelInference(image)
            screwPositionsToCamera = self.pixelToSpace(predictions, verts,debug=True)
            for screwPosition in screwPositionsToCamera:
                screwPositions.append(self.camToWorldPositions(screwPosition[0], screwPosition[1], screwPosition[2])[:3])
        
        return predictions
    
    def identifyScrewsNoRepetitions(self,predictions: list,tolerance=0.01) -> list:
        result = []
        unique_screws = []
        for prediction_list in predictions:
            
            for element in prediction_list:
                x, y, z = element[:3]
                found = False
                for i in range(len(unique_screws)):
                    screw = unique_screws[i]
                    index = -1
                    if abs(screw[0] - x) <= tolerance and abs(screw[1] - y) <= tolerance:
                        found = True
                        index = i
                        break
                if found:
                    print('found')
                    print(unique_screws[index])
                    average_x = (screw[0] + x) / 2
                    average_y = (screw[1] + y) / 2
                    average_z = (screw[2] + z) / 2
                    if index != -1:
                        unique_screws.pop(index)
                    unique_screws.append((average_x, average_y, average_z))
                else:
                    unique_screws.append(element)
        
        return unique_screws

    def swap(self,position:list):
        # align realsense axis to camera link axis 
        return[position[2],-position[0],-position[1]]
perception=PerceptionNode()
#xyzpose=perception.Controller.get_pose()[:3]
#perception.Controller.go_to_pose_goal_cartesian([xyzpose[0]+0.5,xyzpose[1]+0.5,xyzpose[2],0,0,0])
perception.launchNode()
# pose=[0.3415449901080874, 0.08756450183511326, 0.2540691819881634, -3.1289211366304626, -0.09482885806231008, 0.07191366388360511]
# pose=[0.468965394266172, -0.11892876800415482, 0.2631456616785275, -3.1289607005477835, -0.09484716686890036, 0.07206694957528902]
#perception.Controller.go_to_pose_goal_cartesian(pose)
