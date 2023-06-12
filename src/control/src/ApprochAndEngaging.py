import rospy
from std_msgs.msg import Float32MultiArray , Bool, Int32
from robot_helper import *
from enums.nodes import Nodes
from enums.topics import Topics
from geometry_msgs.msg import WrenchStamped
from CentralNode.msg import node_response


class ApprochAndEngaging:
    def __init__(self) -> None:
        self.RobotJoystick = RobotControl(node_name=Nodes.APPROACH_AND_ENGAGE.value,group_name="ScrewIn")
        self.TransformCalculator = frames_transformations()
        self.MyNumber = 4
        self.UnscrewFlag = False
        self.engageFlag  = False
        self.SensorRead = WrenchStamped()
        self.NodeToOperate = 0
        self.ListOfscrews = [1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12]#for testing only
        #define publishers 
        self.Motor=rospy.Publisher(Topics.ScrewDriverMOTOR_COMMAND.value, Int32, queue_size=1)
        self.StartUnscrewing = rospy.Publisher(Topics.UNSCREW_START_FLAG.value, Bool , queue_size=1)
        self.NodeSuccess=rospy.Publisher(Topics.NODE_SUCCESS.value, node_response, queue_size=1)
        #define subscribers
        rospy.Subscriber(Topics.UNSCREW_DONE.value, Bool, self.unscrewDoneCallback)
        rospy.Subscriber(Topics.ForceSensorWrench.value, WrenchStamped, self.SensorCallback)
        rospy.Subscriber(Topics.NODE_TO_OPERATE.value, Int32, self.NodeToOperateCallback)
        #motor commands 
        # 0: stop
        # 1: for rotate clockwise
        self.on = 1
        self.off = 0
        self.motorCommands = Int32()


    def reshapeList(self,ListOfscrews)->list:
        #reshaping the list of screws to 2D (nx6) list array
        ListOfscrews = [ListOfscrews[i:i+6] for i in range(0, len(ListOfscrews), 6)]
        return ListOfscrews

    def unscrewDoneCallback(self,msg):
        self.UnscrewFlag = msg.data
        pass

    def SensorCallback(self,msg):
        self.SensorRead = msg
        pass

    def OperateMotor(self):
        self.motorCommands.data = self.on
        while self.Motor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
            pass
        self.Motor.publish(self.motorCommands)
        pass

    def stopMotor(self):
        self.motorCommands.data = self.off
        while self.Motor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
            pass
        self.Motor.publish(self.motorCommands)
        pass

    def NodeToOperateCallback(self,msg):
        self.NodeToOperate = msg.data
        pass

    def unscrew(self):
        pass

    def main(self):
        while not rospy.is_shutdown():
            if self.NodeToOperate == self.MyNumber:
                #here we will get the list of screws from the central node by service
                #first put frames at each center of the screws
                i=0 #iterator for screws
                for screw in self.ListOfscrews:
                    self.TransformCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="screw"+str(i),frame_coordinate=screw)
                    i += 1
                    pass
                #then go to each screw and unscrew it
                i=0 #iterator for screws
                for screw in self.ListOfscrews:
                    pose,_ = self.TransformCalculator.transform(parent_id="base_link",child_frame_id="screw"+str(i))
                    self.RobotJoystick.go_to_pose_goal_cartesian(pose_goal=pose,velocity=0.1,acceleration=0.1,replanning=True)
                    #rest of the cycle




                    #end of one screw cycle
                    i += 1
                    pass
                pass
        pass
