#!/usr/bin/env python
import rospy
from std_msgs.msg import Bool
from geometry_msgs.msg import  WrenchStamped
from enums.nodes import Nodes
from enums.topics import Topics
# Intial values for torque and force variables
class Collision:
    def __init__(self,forceCollisionLimit,tourqeCollisionLimit) -> None:
        rospy.init_node(Nodes.COLLISION_DETECTION.value)
        rospy.Subscriber(Topics.START_COLLISION_DETECTED.value,Bool, startCollisionCallback)
        rospy.Subscriber(Topics.ForceSensorWrench.value,WrenchStamped, ftCallback)
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
