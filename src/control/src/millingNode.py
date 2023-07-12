#!/usr/bin/env python3
import rospy 
from helper.robot_helper import *
from enums.nodes import Nodes
from enums.topics import Topics
from std_msgs.msg import Bool,Int32
class Milling:
    def __init__ (self,zdown,radius,tolerance,positionTolerance=0.001):
        '''
        zdown: distance to go down
        radius: radius of screw
        tolerance: tolerance from the screw
        positionTolerance: tolerance of position
        '''
        self.MillingControl = RobotControl(node_name=Nodes.MILLING.value,group_name="MillingIn")
        self.ZGoDown=zdown
        self.RadiusCut=radius+tolerance
        self.finishMillingFlag=rospy.Publisher(Topics.FINISHED_MILLING.value,Bool,queue_size=1,latch=True)
        self.center=list()
        self.wasypointsresolution=positionTolerance
        self.MillingMotor=rospy.Publisher(Topics.MillingMOTOR_COMMAND.value,Int32,queue_size=1)
        self.MillingCommmads=Int32()
        pass
    def startMilling(self):
        self.MillingCommmads.data = 1
        while self.MillingMotor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
        self.MillingMotor.publish(self.MillingCommmads)
        pass
    def stopMilling(self):
        self.MillingCommmads.data = 0
        while self.MillingMotor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
        self.MillingMotor.publish(self.MillingCommmads)
        pass
    def getCenter(self):
        self.center=self.MillingControl.get_pose()
        pass
    def goToRadius(self):
        self.MillingControl.go_to_pose_goal_cartesian(pose_goal=[self.center[0]+self.RadiusCut,self.center[1],self.center[2],self.center[3],self.center[4],self.center[5]],velocity=0.05,acceleration=0.05,Replanning=True,WaitFlag=False)
        pass
    def circle(self):
        postionTolerance=0.001
        circleways=[]
        xlast,ylast=0,0
        for i in range(1,360):
            x,y=self.center[0]+self.RadiusCut*math.cos(math.radians(i)),self.center[1]+self.RadiusCut*math.sin(math.radians(i))
            if(math.sqrt(((x-xlast)**2)+((y-ylast)**2))>=postionTolerance):
                circleways.append([x,y,self.center[2]-self.ZGoDown,self.center[3],self.center[4],self.center[5]])
                xlast,ylast=x,y
        self.MillingControl.go_to_pose_goal_cartesian_waypoints(waypoints=circleways,velocity=0.005,acceleration=0.005,list_type=True,waitFlag=True,positionTolerance=self.wasypointsresolution)
    def GoDown(self):
        mypos=self.MillingControl.get_pose()
        self.MillingControl.go_to_pose_goal_cartesian(pose_goal=[mypos[0],mypos[1],mypos[2]-self.ZGoDown,mypos[3],mypos[4],mypos[5]],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)
        pass
    def GoUp(self):
        mypos=self.MillingControl.get_pose()
        self.MillingControl.go_to_pose_goal_cartesian(pose_goal=[mypos[0],mypos[1],mypos[2]+self.ZGoDown,mypos[3],mypos[4],mypos[5]],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)
    def Cut(self):
        self.getCenter()
        self.goToRadius()
        self.startMilling()
        self.GoDown()
        self.circle()
        self.GoUp()
        self.stopMilling()
    def main(self):
        while not rospy.is_shutdown():
            print ("Waiting for Start Milling Flag")
            StartMillingFlag:Bool=rospy.wait_for_message(Topics.START_MILLING.value,Bool)
            if StartMillingFlag.data:
                self.Cut()
                self.finishMillingFlag.publish(True)
            pass

MillingNode=Milling(zdown=0.01,radius=0.011,tolerance=0.001)
MillingNode.main()
