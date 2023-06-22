#!/usr/bin/env python3
import rospy
import numpy as np
import matplotlib.pyplot as plt
import math
from std_msgs.msg import Int64,Int32,Bool,String
from enums.nodes import Nodes
from enums.topics import Topics
from helper.robot_helper import *

group_name_2:str="Millingin"
millingControl = RobotControl(node_name=Nodes.MILLING.value,group_name=group_name_2)
TransformationCalculator = frames_transformations()

#raduis of screw head
screwRadius=0.01
millingRadius= screwRadius + 0.005


# Resolution of milling circle steps
# 10 degrees each step
circleResolution=10 

# zMilling Depth of cut
# 4mm head of screw + 3mm depth = 7 mm
zMillingDepth = 0.007


# .data for publishing
False_data = Bool()
True_data = Bool()
True_data.data = True
False_data.data = False

# Global variable that contains the .data for the start flag
startMilling_Flag = False


def startMilling_Callback(startMilling):
    rospy.loginfo("entered startMilling_Callback")
    global startMilling_Flag
    startMilling_Flag = startMilling.data
    if startMilling_Flag is True:
        rospy.loginfo("startMilling is True")
        
    else:
        rospy.loginfo("Didn't enter checkReadings")


        
        
def millingPath():
    global millingRadius, zMillingDepth, circleResolution
    
     #go beside the screw with a distance (radius)
    centerPose = millingControl.get_pose()
    print(centerPose)
   
    TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                             centerPose[0]+millingRadius, centerPose[1], centerPose[2], centerPose[3], centerPose[4], centerPose[5]])
    pose = TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
    millingControl.go_to_pose_goal_cartesian(
            pose, 1, 1, Replanning=True,wating=False)
    
    # Start milling
    millingMotorPub.publish(1)
    
    # Go down while cutting through the surface
    TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                  centerPose[0]+millingRadius, centerPose[1], centerPose[2] + zMillingDepth, centerPose[3], centerPose[4], centerPose[5]])
    pose = TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
    millingControl.go_to_pose_goal_cartesian(
            pose, 1, 1, Replanning=True,wating=False)
    
    # move in a circular path 
    pose = millingControl.get_pose()
    circularWaypoints = []
    for i in range(0, 360, circleResolution):
            # Calculate the x and y coordinates of the object
            x = centerPose[0] + millingRadius * math.cos(math.radians(i))
            y = centerPose[1] + millingRadius * math.sin(math.radians(i))
            circularWaypoints.append([x,y,pose[2],pose[3],pose[4],pose[5]])
            
    millingControl.go_to_pose_goal_cartesian_waypoints(circularWaypoints,velocity=0.1,acceleration=0.1,list_type=True,waitFlag=False)
    
    # Go up while cutting through the surface
    TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                  centerPose[0]+millingRadius, centerPose[1], centerPose[2] , centerPose[3], centerPose[4], centerPose[5]])
    pose = TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
    millingControl.go_to_pose_goal_cartesian(
            pose, 1, 1, Replanning=True,wating=False)

if __name__ == '__main__':
    try:
        
        unscrewingPub = rospy.Publisher(Topics.FINISHED_MILLING.value, Bool, queue_size=1)
        millingMotorPub = rospy.Publisher(Topics.MillingDriverMOTOR_COMMAND.value, Int32, queue_size=1)
        rospy.Subscriber(Topics.START_MILLING.value, Bool, startMilling_Callback)
        
        # rate = rospy.Rate(10)  # 10hz
        while not rospy.is_shutdown():
            # if startMilling_Flag is True:
            if True:
                millingPath()
           
            # rate.sleep()
        
    except rospy.ROSInterruptException:
        pass
