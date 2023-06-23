#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from std_msgs.msg import Int64
from std_msgs.msg import Bool
# Replace with the appropriate message type for your topic
from std_msgs.msg import Float32

from geometry_msgs.msg import Wrench, WrenchStamped
from enums.nodes import Nodes
from enums.topics import Topics
# Intial values for torque and force variables
fx = 0
fy = 0
fz = 0
tx = 0
ty = 0
tz = 0

# Collision Detection Start flag
startCollisionDetection_Flag = 0

# Variables to be plotted
x_data = []
y_data = []

# .data for publishing
False_data = Bool()
True_data = Bool()
True_data.data = True
False_data.data = False

# Measured limits for force and torque
forceCollisionLimit = 14
torqueCollisionLimit = 0.5

# Force sensor reading and plotting
def ftCallback(ftSensor_incomingReading):
    global fx, fy, fz, tx, ty, tz
    # Update sensor readings
    # get the forces
    fx = ftSensor_incomingReading.wrench.force.x
    fy = ftSensor_incomingReading.wrench.force.y
    fz = ftSensor_incomingReading.wrench.force.z

    # get the torques
    tx = ftSensor_incomingReading.wrench.torque.x
    ty = ftSensor_incomingReading.wrench.torque.y
    tz = ftSensor_incomingReading.wrench.torque.z

    # Varaibles appending for plotting
    x_data.append(rospy.Time.now().to_sec())
    y_data.append(tz)

# Checking and publishing collision detection flag
def detectCollisions():
    global forceCollisionLimit, torqueCollisionLimit, False_data, True_data
    # Limits checking
    if (fx or fy or fz) > forceCollisionLimit:
        collisionDetectedPub.publish(True_data)
        rospy.loginfo("Force collision detected")
    else:
        collisionDetectedPub.publish(False_data)
        # rospy.loginfo("No force collision detected")
    # rospy.sleep(1)    
        
    if (tx or ty or tz) > torqueCollisionLimit:
        collisionDetectedPub.publish(True_data)
        rospy.loginfo("Torque collision detected")
    else:
        collisionDetectedPub.publish(False_data)
        # rospy.loginfo("No torque collision detected")
    # rospy.sleep(1)
    
# Collision detection enable flag 
def startCollisionCallback(startCollisionDetection_data):
    global startCollisionDetection_Flag
    
    # assigning .data to gobal varaible startCollisionDetection_Flag
    startCollisionDetection_Flag = startCollisionDetection_data.data
    # rospy.loginfo(startCollisionDetection_Flag)


if __name__ == '__main__':
    try:
        rospy.init_node('collisionDetection', anonymous=True)
        collisionDetectedPub = rospy.Publisher(Topics.COLLISION_DETECTED.value, Bool, queue_size=1)
        rospy.Subscriber(Topics.START_COLLISION_DETECTION.value,Bool, startCollisionCallback)
        rospy.Subscriber(Topics.ForceSensorWrench.value,WrenchStamped, ftCallback)
        while not rospy.is_shutdown():

            # plt.figure()
            # plt.plot(x_data, y_data)
            # plt.xlabel('Time')  # Customize the x-axis label
            # plt.ylabel('Data')  # Customize the y-axis label
            # plt.title('Topic Graph')  # Customize the plot title
            # plt.ylim((-20, 20))
            # plt.show()

            # Checking the collision detection enable flag 
            if startCollisionDetection_Flag is True:
                detectCollisions()
            # else:
            #     rospy.loginfo("Collision detection flag NOT enabled")

    except rospy.ROSInterruptException:
        pass
