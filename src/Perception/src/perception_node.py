import rospy
import sys
import copy
import rospy
from moveit_commander import *
import geometry_msgs.msg
import tf2_ros
import tf.transformations
import math
from std_msgs.msg import Bool,Float64MultiArray, MultiArrayLayout, MultiArrayDimension,String,Int32
import json
import torch

import cv2
import numpy as np
sys.path.append("../yolov7/")
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
sys.path.append("/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/control/src/")
from robot_helper import RobotControl, frames_transformations
import numpy as np
import tf.transformations

#Robot Control imports

class PerceptionNode():
    
    def __init__(self, width=1280, height=720, useCuda="cpu") -> None:
        #self.perceptionNode = rospy.init_node("Perception") # Need to change this to the enum values 
        self.perceptionPublisher = rospy.Publisher('ListOfScrews', String, queue_size=50) # Need to change this to the enum values
        self.nodeToOperateListener = rospy.Subscriber("NodeToOperate",Int32,self.nodeToOperateCallback)
       

        self.Controller = RobotControl(node_name="Perception",group_name="NoTool")
        self.framesTransformer=frames_transformations()
        self.rate = rospy.Rate(200)
        #camera viewing dimensions
        self.Width = width
        self.Height = height
        self.operate = True
        self.model = None
        self.useCuda = useCuda

    def nodeToOperateCallback(self,data):
        if data == 1:
            self.operate = True
        else: 
            self.operate = False
    

    def loadModel(self, location="/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/Perception/src/epoch_480.pt"):
        cuda =  "cpu" if self.useCuda == "cpu" else 0
        device = "cpu" if self.useCuda == "cpu" else select_device("0")
        
        #load model 
        intialModel = attempt_load(location, device)
        self.model = TracedModel(intialModel, cuda, 640)

        if cuda == "cpu":
            self.model.half()

    def InitializeCamera(self):
        # Configure camera streams
        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.config.enable_stream(rs.stream.color, 1280, 720, rs.format.bgr8, 30)
        self.config.enable_stream(rs.stream.depth, 848, 480, rs.format.z16, 30)
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

        if self.useCuda == "cpu":
            image = torch.from_numpy(image).float()
        else:
            img = torch.from_numpy(img).to(0).half()
            
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
        print('predresults are')
        print(predresults)
        for predresult in predresults:
            # Blue color in BGR
            color = (255, 0, 0)
            print('predres value is {}'.format(predresult))
            centerx = int((predresult[0] + predresult[2])) // 2
            centery = int((predresult[1] + predresult[3])) // 2
            print('center val is  {},{}',centerx,centery)
            xyz_position = verts[centery][centerx]
            xyz_position = [float(xyz_position[0]), float(xyz_position[1]), float(xyz_position[2])]
            print(xyz_position[2])
            screwlist.append(xyz_position)
            rc = cv2.rectangle(self.color_image, (int(predresult[0]), int(predresult[1])), (int(predresult[2]), int(predresult[3])), color, 2) # Not used ?

        if debug:
            cv2.imshow('myimg', self.color_image)
            cv2.waitKey(1)

        return screwlist
    


    def camToWorldPositions(self, x, y ,z, verbose=False):
        
        static_frame = self.framesTransformer.put_frame_static_frame(parent_frame_name='camera_link', child_frame_name="static")
        relative_transformations = self.framesTransformer.transform(parent_id="base_link", child_frame_id='static')#chid id might be wrong
        # apply transformations and rotations wrt robot
        translations=relative_transformations[:3]
        
        rotations = relative_transformations[3:]
        cam_matrix = np.array([x,y,z,1])
        
        homogeneous_matrix = tf.transformations.compose_matrix(translate=translations,angles=rotations)
       
        worldpose = np.matmul(homogeneous_matrix,cam_matrix)
        
        return worldpose
    
    def publishReadings(self, Data):
        my_msg = String()
        my_msg.data = json.dumps(Data)
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

                # for screwPosition in screwPositionsToCamera:
                #     screwPositions.append(self.camToWorldPositions(screwPosition[0], screwPosition[1], screwPosition[2])[:3])

                ## Publish readings
                
                self.publishReadings(screwPositionsToCamera)

                self.rate.sleep()
    def scan(self,poses)->list:
        predictions=list()
        for pose in poses:
            screwPositions=list()
            self.Controller.go_to_pose_goal_cartesian(pose,1,0.2)
            image, verts = self.imagePreprocess()
            predictions=self.modelInference(image)
            screwPositionsToCamera = self.pixelToSpace(predictions, verts,debug=True)
            for screwPosition in screwPositionsToCamera:
                screwPositions.append(self.camToWorldPositions(screwPosition[0], screwPosition[1], screwPosition[2])[:3])
        
        return predictions
    
    def identifyScrewsNoRepetions(self, predictions: list) -> list:
        result = []
        for prediction_list in predictions:
            unique_screws = []
            for element in prediction_list:
                x, y, z = element
                found = False
                for screw in unique_screws:
                    if abs(screw[0]-x)<=0.01 and abs(screw[0]-x)<=0.01: 
                        found = True
                        break
                if found:
                    average_x = (screw[0] + x) / 2
                    average_y = (screw[1] + y) / 2
                    average_z = (screw[2] + z) / 2
                    unique_screws.append((average_x, average_y, average_z))
                else:
                    unique_screws.append(element)
            for unique_screw in unique_screws:
                result.append(unique_screw)
        return result

perception=PerceptionNode()
xyzpose=perception.Controller.get_pose()[:3]
perception.Controller.go_to_pose_goal_cartesian([xyzpose[0]+0.5,xyzpose[1]+0.5,xyzpose[2],0,0,0])
perception.launchNode()