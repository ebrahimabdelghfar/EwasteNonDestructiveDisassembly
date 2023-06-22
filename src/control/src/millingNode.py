import rospy 
from helper.robot_helper import *
from enums.nodes import Nodes
class Milling:
    def __init__ (self,zdown,radius,tolerance):
        self.MillingControl = RobotControl(node_name=Nodes.MILLING.value,group_name="manipulator")
        self.ZGoDown=zdown
        self.RadiusCut=radius+tolerance
        pass
    def circle(self):
        center=self.MillingControl.get_pose()
        postionTolerance=0.001
        circleways=[]
        xlast,ylast=0,0
        for i in range(1,360):
            x,y=center[0]+self.RadiusCut*math.cos(math.radians(i)),center[1]+self.RadiusCut*math.sin(math.radians(i))
            if(math.sqrt(((x-xlast)**2)+((y-ylast)**2))>postionTolerance):
                circleways.append([x,y,center[2],center[3],center[4],center[5]])
                print(f"apppend {x} , {y}")
                xlast,ylast=x,y

        self.MillingControl.go_to_pose_goal_cartesian_waypoints(waypoints=circleways,velocity=0.1,acceleration=0.1,list_type=True,waitFlag=True,positionTolerance=postionTolerance)
    def GoDown(self):
        mypos=self.MillingControl.get_pose()
        self.MillingControl.go_to_pose_goal_cartesian(pose_goal=[mypos[0],mypos[1],mypos[2]-self.ZGoDown,mypos[3],mypos[4],mypos[5]],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)
        pass
    def GoUp(self):
        mypos=self.MillingControl.get_pose()
        self.MillingControl.go_to_pose_goal_cartesian(pose_goal=[mypos[0],mypos[1],mypos[2]+self.ZGoDown,mypos[3],mypos[4],mypos[5]],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)
    def Cut(self):
        self.GoDown()
        self.circle()
        self.GoUp()
test=Milling(zdown=0.01,radius=0.01,tolerance=0.001)
test.Cut()