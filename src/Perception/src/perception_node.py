import rospy
import sys
import copy
import rospy
from moveit_commander import *
import geometry_msgs.msg
import tf2_ros
import tf.transformations
import math
from std_msgs.msg import Bool,Float64MultiArray, MultiArrayLayout, MultiArrayDimension,String
import json
import torch

#from PIL import Image
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


#load model 

model = attempt_load("/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/Perception/src/epoch_480.pt","cpu")
model = TracedModel(model,"cpu",640)

#print(model)




perceptionNode=rospy.init_node("Perception")
perceptionPublisher=rospy.Publisher('ListOfScrews' ,String,queue_size=50)
rate=rospy.Rate(50)
# Configure camera streams
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.color, 1280, 720, rs.format.bgr8, 30)
config.enable_stream(rs.stream.depth, 848, 480, rs.format.z16, 30)
pipeline.start(config)
#camera viewing dimensions
W=1280
H=720
colors_hash={}
aligned_stream = rs.align(rs.stream.color) # alignment between color and depth
point_cloud = rs.pointcloud()
## Configure Camera Filters:
temporalFilter=rs.temporal_filter()
holeFillingFilter=rs.hole_filling_filter()
while not rospy.is_shutdown():
   
    screwlist=[]
    ## Camera Readings
    frames = pipeline.wait_for_frames()
    color_frame = frames.get_color_frame()
    
    color_image = np.asanyarray(color_frame.get_data())
    
    frames = aligned_stream.process(frames)
    depth_frame = frames.get_depth_frame()
    ## depth enhancement
    depth_frame=temporalFilter.process(depth_frame)
    depth_frame=holeFillingFilter.process(depth_frame)
    ####
    df = np.asarray(depth_frame.get_data())
    points = point_cloud.calculate(depth_frame)
    verts = np.asanyarray(points.get_vertices()).view(np.float32).reshape(-1, W, 3)  # xyz

    ### Model inference on RGB
    
    img0 =color_image#cv2.imread("/content/gdrive/MyDrive/YOLO_V7/Test_images/test2.jpeg")
    #preprocesses the image and makes the image size a multiple of the stride size,resizes the image
    img = letterbox(img0)[0]
  
    #transpose from cv2 bgr to rgb
    img = img[:, :, ::-1].transpose(2, 0, 1)
    img = np.ascontiguousarray(img)
    img = torch.from_numpy(img).float()
    img /= 255.0
    img.unsqueeze(0)
    img = img[None,:,:,:]
    
    

    with torch.no_grad():   # Calculating gradients would cause a GPU memory leak
        output = model(img,False)[0]

    pred = non_max_suppression(output)
    #print(pred[0].shape)
    predresults = pred[0]
    #predresults format: (xtl,ytl,xbr,ybr,conf,class)
    predresults[:, :4] = scale_coords(img.shape[2:], predresults[:, :4], img0.shape).round()
    
   

    ## pixel to world coordinates transformation

    #print('shape of verts is {}',verts.shape)
    for predresult in predresults:
        list()
        # Blue color in BGR
        color = (255, 0, 0)
        #print('predres value is {}'.format(predresult))
        centerx = int((predresult[0]+predresult[2]))//2
        centery = int((predresult[1]+predresult[3]))//2
        print('center val is  {},{}',centerx,centery)
        xyz_position = verts[centery][centerx]
        xyz_position = [float(xyz_position[0]),float(xyz_position[1]),float(xyz_position[2])]
        #print(xyz_position)
        screwlist.append(xyz_position)
        rc=cv2.rectangle(color_image,(int(predresult[0]),int(predresult[1])),(int(predresult[2]),int(predresult[3])),color,2)
    cv2.imshow('myimg',color_image)
    cv2.waitKey(1)
    

    ## converting detections to rosmsg

    ## Todo : Modify this line correctly to publish the list
    ##screwlist=Float32MultiArray(screwlist)
    
    ##publishing the screwlist
    my_msg = String()
    my_msg.data = json.dumps(screwlist)
    
    
    perceptionPublisher.publish(my_msg)


    rate.sleep()
