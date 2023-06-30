#!/usr/bin/env python3
# license removed for brevity
import rospy
from std_msgs.msg import Bool
from geometry_msgs.msg import  WrenchStamped
from enums.nodes import Nodes
from enums.topics import Topics

from helper.robot_helper import *


robotCollision = RobotControl(group_name_1="manipulator")

# Intial values for torque and force variables
class Collision:
    def __init__(self,forceCollisionLimit,tourqeCollisionLimit) -> None:
        rospy.init_node(Nodes.COLLISION_DETECTION.value)
        rospy.Subscriber(Topics.START_COLLISION_DETECTED.value,Bool, self.startCollisionCallback)
        rospy.Subscriber(Topics.ForceSensorWrench.value,WrenchStamped, self.ftCallback)

        self.collisionDetectedPub = rospy.Publisher(Topics.COLLISION_DETECTED.value, Bool, queue_size=1)
        self.fx = 0
        self.fy = 0
        self.fz = 0
        self.tx = 0
        self.ty = 0
        self.tz = 0
        # Collision Detection Start flag
        self.startCollisionDetection_Flag = 0
        # Measured limits for force and torque
        self.forceCollisionLimit = forceCollisionLimit
        self.torqueCollisionLimit = tourqeCollisionLimit
        # .data for publishing
        self.False_data = Bool()
        self.True_data = Bool()
        self.True_data.data = True
        self.False_data.data = False
        pass

    # Force sensor reading and plotting
    def ftCallback(self,ftSensor_incomingReading:WrenchStamped):
        # Update sensor readings
        # get the forces
        self.fx = ftSensor_incomingReading.wrench.force.x
        self.fy = ftSensor_incomingReading.wrench.force.y
        self.fz = ftSensor_incomingReading.wrench.force.z
    
        # get the torques
        self.tx = ftSensor_incomingReading.wrench.torque.x
        self.ty = ftSensor_incomingReading.wrench.torque.y
        self.tz = ftSensor_incomingReading.wrench.torque.z

    # Checking and publishing collision detection flag
    def detectCollisions(self):
        
        # Limits checking
        if (self.fx or self.fy or self.fz) > self.forceCollisionLimit:
            self.collisionDetectedPub.publish(self.True_data)
            robotCollision.Stop()
            rospy.loginfo("Force collision detected")
        else:
            self.collisionDetectedPub.publish(self.False_data)
            # rospy.loginfo("No force collision detected")
        # rospy.sleep(1)    
            
        if (self.tx or self.ty or self.tz) > self.torqueCollisionLimit:
            self.collisionDetectedPub.publish(self.True_data)
            rospy.loginfo("Torque collision detected")
        else:
            self.collisionDetectedPub.publish(self.False_data)
            # rospy.loginfo("No torque collision detected")
        # rospy.sleep(1)
        
    # Collision detection enable flag 
    def startCollisionCallback(self,startCollisionDetection_data):
        # assigning .data to gobal varaible startCollisionDetection_Flag
        self.startCollisionDetection_Flag = startCollisionDetection_data.data
        # rospy.loginfo(startCollisionDetection_Flag)
    def main(self):
        while not rospy.is_shutdown():
            # Checking the collision detection enable flag 
            if self.startCollisionDetection_Flag is True:
                self.detectCollisions()

if __name__ == '__main__':
    safety = Collision(forceCollisionLimit=10,tourqeCollisionLimit=10)
    safety.main()