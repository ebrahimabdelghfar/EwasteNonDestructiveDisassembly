import rospy
import sys
import copy
import rospy
from moveit_commander import *
import geometry_msgs.msg
import tf2_ros
import tf.transformations
import math
from std_msgs.msg import Bool,Float32MultiArray, MultiArrayLayout, MultiArrayDimension

import torch

#camera imports:
import pyrealsense2 as rs
import open3d as o3d
import numpy as np
import cv2
import time


#model= torch.load('/epoch_480.pt')
perceptionNode=rospy.init_node("Perception")
perceptionPublisher=rospy.Publisher('screwlist' ,Float32MultiArray,queue_size=50)
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

    ## pixel to world coordinates transformation

    for screw in screwlist:
        ## assuming we got the center x,y
        #screw=verts[screw[0],screw[1]]
        pass


    

    ## converting detections to rosmsg

    ## Todo : Modify this line correctly to publish the list
    ##screwlist=Float32MultiArray(screwlist)
    
    ##publishing the screwlist

    
    #perceptionPublisher.publish(screwlist)


    rate.sleep()
