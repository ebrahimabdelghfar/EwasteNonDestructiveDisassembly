#!/usr/bin/env python3
import rospy
from helper.robot_helper import *
from std_msgs.msg import Float64MultiArray

class SpeedMeasure:
    def __init__(self,duration) -> None:
        self.RobotInfo=RobotControl(node_name="SpeedMeasure",group_name="manipulator")
        self.speedpub=rospy.Publisher("/speed",Float64MultiArray,queue_size=0)
        self.currentjointSpeed=Float64MultiArray()
        self.currentjointstate=[0,0,0,0,0,0]
        self.pastjointstate=[0,0,0,0,0,0]
        self.duration=duration
        rospy.Timer(rospy.Duration(self.duration),self.Measure)
        pass
    def Measure(self,event):
        self.currentjointstate=self.RobotInfo.get_joint_state()
        for i in range (len(self.currentjointstate)):
            self.currentjointSpeed.data.append(abs(self.currentjointstate[i]-self.pastjointstate[i])/self.duration)
        self.pastjointstate=self.currentjointstate
        self.speedpub.publish(self.currentjointSpeed)
        self.currentjointSpeed.data.clear()
        pass
    def start(self):
        rospy.spin()
        pass

if __name__ == "__main__":
    rospy.init_node("SpeedMeasure")
    speed=SpeedMeasure(duration=0.1)
    speed.start()