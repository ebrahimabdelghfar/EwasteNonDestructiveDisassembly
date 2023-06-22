#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float32MultiArray ,Float64MultiArray, Bool, Int32
from helper.robot_helper import *
from enums.nodes import Nodes
from enums.topics import Topics
from geometry_msgs.msg import WrenchStamped
from CentralNode.msg import node_response
import numpy as np

class ApprochAndEngaging:
    def __init__(self) -> None:
        self.RobotJoystick = RobotControl(node_name=Nodes.APPROACH_AND_ENGAGE.value,group_name="ScrewIn")
        self.TransformCalculator = frames_transformations()
        #editabel parameters
        self.MyNumber = 4
        self.UnscrewFlag = False
        self.engageFlag  = False
        self.SensorRead = WrenchStamped()
        self.NodeToOperate = 0
        self.EngageTourqe = 2.5
        self.ListOfscrews = [1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12]#for testing only
        self.BadScrews = []
        #define publishers 
        self.Motor=rospy.Publisher(Topics.ScrewDriverMOTOR_COMMAND.value, Int32, queue_size=1)
        self.StartUnscrewing = rospy.Publisher(Topics.UNSCREW_START_FLAG.value, Bool , queue_size=1)
        self.startMilling = rospy.Publisher(Topics.START_MILLING.value, Bool , queue_size=1)        
        self.NodeSuccess=rospy.Publisher(Topics.NODE_SUCCESS.value, node_response, queue_size=1)

        #define subscribers
        rospy.Subscriber(Topics.UNSCREW_DONE.value, Bool, self.unscrewDoneCallback)
        #rospy.Subscriber(Topics.FINISHED_MILLING.value, Bool, self.finishedMillingCallback)
        rospy.Subscriber(Topics.ForceSensorWrenchWeightedFilter.value, WrenchStamped, self.SensorCallback)
        rospy.Subscriber(Topics.NODE_TO_OPERATE.value, Int32, self.NodeToOperateCallback)
        #motor commands 
        # 0: stop
        # 1: for rotate clockwise
        self.on = 1
        self.off = 0
        self.motorCommands = Int32()

    def Approach(self,Pose,velocity,acceleration)->None:
        '''
        this function will go to the give cordinates path
        parameters:
        Pose: the pose of the path
        @type Pose: list [x,y,z,roll,pitch,yaw]
        '''
        self.RobotJoystick.go_to_pose_goal_cartesian(Pose,velocity=velocity,acceleration=acceleration,Replanning=True,WaitFlag=False)
        pass

    def Spiralshape(self,timeStep)->None:
        '''
        this function will generate and execute the spiral shape
        parameters:
        step: the step of the time shape
        @type step: float
        '''
        #constant parameters for spiral shape
        recess=0.005
        fs=2*recess
        N_s=60
        fixederror=0.002 #(mm)
        waypoints = []
        PostionTolerance = 0.001
        #calculate the parameters of the spiral
        tmax=int(((10*math.pi)/N_s)*(math.ceil(N_s/2)))
        #generate a list of screws in spiral shape
        pose = self.RobotJoystick.get_pose()
        for i in np.arange(timeStep,tmax,timeStep):
            t=i
            x,y=pose[0]+(((fs/math.pi)*math.sqrt(((8*math.pi*N_s*t)/15))*math.cos(math.sqrt(((8*math.pi*N_s*t)/15))))*0.1),pose[1]+(((fs/math.pi)*math.sqrt(((8*math.pi*N_s*t)/15))*math.sin(math.sqrt(((8*math.pi*N_s*t)/15))))*0.1)
            waypoints.append([x,y,pose[2],pose[3],pose[4],pose[5]])

        #if wait flag == true then the followin line will not be skipped until the robot finish the path
        #if wait flag == false then the following line will be skipped and the robot will start the path and the code will continue
        # self.OperateMotor()
        self.RobotJoystick.go_to_pose_goal_cartesian_waypoints(waypoints,velocity=0.1,acceleration=0.1,list_type=True,waitFlag=False,positionTolerance=0.01)
        while True:
            if self.SensorRead.wrench.torque.z >= self.EngageTourqe:
                self.stopMotor()
                self.engageFlag = True
                print("engaged")
                break
            #check that the robot reached the last point
            currentPose = self.RobotJoystick.get_pose()
            if all(abs(currentPose[i]-waypoints[-1][i])<PostionTolerance for i in range(len(currentPose))):
                print("broken")
                self.stopMotor()
                self.engageFlag = False
                break
        if self.engageFlag:
            self.engageFlag = False
            pass
        else:
            # self.BadScrews.append(NowScrew)
            pass
        #end of spiral shape

    def reshapeList(self,ListOfscrews)->list:
        #reshaping the list of screws to 2D (nx6) list array
        return np.reshape(ListOfscrews,(-1,6)).tolist()

    def unscrewDoneCallback(self,msg:Bool)->None:
        #self.UnscrewFlag = msg.data
        pass

    def SensorCallback(self,msg:WrenchStamped)->None:
        self.SensorRead = msg

    def OperateMotor(self)->None:
        self.motorCommands.data = self.on
        while self.Motor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
        self.Motor.publish(self.motorCommands)

    def stopMotor(self):
        self.motorCommands.data = self.off
        while self.Motor.get_num_connections() < 1:
            #ensure that the publisher is connected
            rospy.sleep(0.1)
            pass
        self.Motor.publish(self.motorCommands)

    def NodeToOperateCallback(self,msg):
        self.NodeToOperate = msg.data

    def unscrew(self, index):
        self.StartUnscrewing(True)
        #rospy.Spin()
        receivedFlag = rospy.wait_for_message(Topics.UNSCREW_DONE.value, Bool)
        self.UnscrewFlag = receivedFlag.data
        if not receivedFlag.data:
            self.BadScrews.append(index)

    def mill(self):
        self.startMilling(True)
        #rospy.Spin()
        receivedFlag = rospy.wait_for_message(Topics.UNSCREW_DONE.value, Bool)


    def main(self):
        while not rospy.is_shutdown():
            if self.NodeToOperate == self.MyNumber:
                #here we will get the list of screws from the central node by service
                #first put frames at each center of the screws
                i=0 #iterator for screws
                for screw in self.ListOfscrews:
                    self.TransformCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="screw"+str(i),frame_coordinate=screw)
                    i += 1
                #then go to each screw and unscrew it
                i=0 #iterator for screws
                for screw in self.ListOfscrews:
                    pose = self.TransformCalculator.transform(parent_id="base_link",child_frame_id="screw"+str(i))
                    self.RobotJoystick.go_to_pose_goal_cartesian(pose_goal=pose,velocity=0.1,acceleration=0.1,replanning=True)
                    #rest of the cycle





                    #end of one screw cycle
                    i += 1

test=ApprochAndEngaging()
waysTest=[[0.3194, -0.0956, 0.2432-0.002, -3.123396721367978, -0.019725309395561646, 0.07185048913905212],
[0.3137, 0.1085, 0.241, -3.123403135584518, -0.019725996711971124, 0.07183367654001661],
[0.3706, 0.0052, 0.2314, -3.1235418005447126, -0.019750957277378283, 0.07184738769188843],
[0.4423, 0.117, 0.2314, -3.1235554386840754, -0.01974810023185756, 0.07186302361390409]]

test.Approach(waysTest[2],velocity=0.1,acceleration=0.1)
test.Spiralshape(0.01)