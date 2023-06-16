#!/usr/bin/env python3
import rospy 
from abb_robot_msgs.msg import SystemState
import roslaunch
from enums.nodes import Nodes
class CheckMotors:
    def __init__(self,heartRate,maxCount) -> None:
        '''the following line disable rossignal handler so we can launch form callback'''
        rospy.init_node(Nodes.CHECK_MOTOR.value)
        roslaunch.pmon._init_signal_handlers = self.dummy_function
        '''end'''
        rospy.Subscriber("/rws/system_states", SystemState, self.RobotStateCallback)
        self.HeartRate = heartRate
        self.MaxCount = maxCount
        #interval checker for the motors
        rospy.Timer(rospy.Duration(self.HeartRate), self.motorHeartBeat)
        self.launch = roslaunch.scriptapi.ROSLaunch()
        self.launch.start()
        self.State = SystemState()

    def dummy_function(self)->None: 
        '''
        Objective : This is a dummy function to disable the rossignal handler
        '''
        pass

    def RobotStateCallback(self,RobotState:SystemState)->None:
        '''
        Objective : This is the callback function for the system state subscriber
        '''
        self.State = RobotState
        pass

    def motorHeartBeat(self,event)->None:
        '''
        Objective : where it check the state of the robot and if the robot is not running and in automatic mode then it will start the robot
        '''
        print("Motor Heart Beat")
        if self.State.auto_mode == True and (self.State.motors_on == False or self.State.rapid_running == False):
            '''
            if the robot is in automatic mode and the motors are off or the rapid is not running then start the robot
            '''
            node = roslaunch.core.Node(package="egm_config",node_type="start_robot.bash" ,name="start_robot")
            process=self.launch.launch(node)
            pass
        pass

MotorBeat = CheckMotors(1,1)

rospy.spin()