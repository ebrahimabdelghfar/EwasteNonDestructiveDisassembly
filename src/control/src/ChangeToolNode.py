#!/usr/bin/env python3
from helper.robot_helper import *
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from geometry_msgs.msg import WrenchStamped
from enums.nodes import Nodes
from enums.topics import Topics
from enums.schedular import schedulars
from enums.services import Services
from enums.response_status import Response
from enums.operations import OPERATIONS
from CentralNode.msg import node_response
from CentralNode.srv import Schedular , SchedularResponse , SchedularRequest
class GetToolNode:
    def __init__(self, group_name_1:str="NoTool", StopTourqeThershold1:float=0.5):
        self.RobotController = RobotControl(node_name=Nodes.CHANGE_TOOL.value,group_name=group_name_1)
        self.TransformationCalculator = frames_transformations()
        # list of the last pose of the robot after getting the tool
        self.LastPoseScrew = []
        # toelrance value to get the tool
        self.XtoleranceOutHolder = 0.09
        self.XtoleranceInHolder = 0.093
        self.ZtoleranceToGetDown = 0.002
        self.ZtoleranceAboveTheHolder = 0.05
        # Threshold to check z torque while unlocking
        self.thresholdLocking = -1.1
        # To check z force if tool is attached or not (tool weight)
        self.thresholdForToolWeightForceZ = 2.5
        # define the Topic and sever that being used
        self.ToolChangePub = rospy.Publisher(
            Topics.NODE_SUCCESS.value, node_response, queue_size=1)
        self.TorqueZReadingPub = rospy.Subscriber(
            Topics.ForceSensorWrench.value, WrenchStamped, self.FTReadingCallBack)
        self.ToolChangeClient = rospy.ServiceProxy(Services.SCHEDULAR.value, Schedular, persistent=True)
        CentralResponse = SchedularResponse()
        #end
        #force-tourqe thershold
        self.TorqueZReading = 0.0
        self.ForceZReading = 0.0
        self.StopTourqeThershold = StopTourqeThershold1
        #end
        self.State=node_response()
        #this variable is used to store the scehdule of getting and returning tool
        self.schedulecollectorofgettingTool=[]
        self.schedulecollectorofreturningTool=[]
        #this variable will be reterive from server
        self.waypoints=[]
        self.waypointstype=[]
        self.CheckForceFlag=[]
        self.Velocity=[]
        self.Acceleration=[]
        #end

        self.unscrewIndex = OPERATIONS.index(Nodes.APPROACH_AND_ENGAGE)
        self.visionIndex = OPERATIONS.index(Nodes.VISION)
        self.returnScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
        self.getMillingIndex = self.returnScrewDriverIndex + 1
        self.returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, self.getMillingIndex + 1)
        self.getScrewDriverIndex = self.returnMillingIndex + 1

    def FTReadingCallBack(self, data: WrenchStamped) -> None:
        '''
        objective: this function is used to get the torque reading from the sensor
        '''
        self.TorqueZReading = data.wrench.torque.z
        self.ForceZReading = data.wrench.force.z

    def reshapeList(self,GivenList:list)->list:
        #reshaping the given list to 2D (nx6) list array
        GivenList = [GivenList[i:i+6] for i in range(0, len(GivenList), 6)]
        return GivenList
    
    def ChangeGroupName(self, groupname_1:str="NoTool") -> None:
        self.RobotController = RobotControl(group_name=groupname_1)
    
    def CheckToolTourqe(self) -> None:
        '''
        arguments:
            null
        functionality:
            This function is used to check the tourqe of locking and unlocking the tool
        '''
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(self.thresholdLocking) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("locking")     
        pass
        
    def ChangeTool(self)->None:
        rospy.wait_for_service(Services.SCHEDULAR.value)
        #this where the tool will call the server to get the schedule of changing tool
        self.CentralResponse:SchedularResponse = self.ToolChangeClient(SchedularRequest())
        self.waypoints = self.CentralResponse.waypoints
        self.waypointstype = self.CentralResponse.waypoint_types
        self.CheckForceFlag = self.CentralResponse.check_force_flag
        self.Velocity = self.CentralResponse.Velocity
        self.Acceleration = self.CentralResponse.Acceleration
        #save the schedule of getting and returning tool
        for index in range(len(self.waypoints)):
            if self.waypointstype[index]==schedulars.JointType.value:
                if self.CheckForceFlag[index]==schedulars.CheckForceSensor.value:
                    self.RobotController.go_by_joint_angle(self.waypoints[index], self.Velocity, self.Acceleration, Replanning=False,WaitFlag=False)
                    self.CheckToolTourqe()              
                    pass
                else:
                    self.RobotController.go_by_joint_angle(self.waypoints[index], self.Velocity, self.Acceleration, Replanning=True,WaitFlag=False)
                    pass
                pass
            elif self.waypointstype[index]==schedulars.CartesianType.value:
                if self.CheckForceFlag[index]==schedulars.CheckForceSensor.value:
                    self.RobotController.go_to_pose_goal_cartesian(self.waypoints[index], self.Velocity, self.Acceleration, Replanning=False,WaitFlag=False)
                    self.CheckToolTourqe()
                    pass
                else:
                    self.RobotController.go_to_pose_goal_cartesian(self.waypoints[index], self.Velocity, self.Acceleration, Replanning=True,WaitFlag=False)
                    pass
                pass
            #after each point go it will increment the index of the node
            #and publish the status of the node
            self.State.status=Response.IN_PROGRESS.value
            self.State.extraMessage=str(index+1)
            self.ToolChangePub.publish(self.State)
            pass

        pass 
#old codes that will be used to get the the schedule of getting and returning tool
    def GetScrewTool(self) -> None:
        '''
        --------------------
        This function is used get tool 
        --------------------
        arguments:
            null 
        functionality:
            This function is used to move the robot and get the tool
        --------------------
        '''
        list_of_poses = []
        # rotate the robot by 90o for safely get the tool
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 1, 1, Replanning=True)
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        # # go above the tool
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceAboveTheHolder, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 1, 1, Replanning=True,wating=False)
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())
        # go to Holder
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceToGetDown, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 0.005, 0.005, Replanning=True,WaitFlag=False)
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())

        # lock the tool
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(-50)], 0.01, 0.01, Replanning=False, WaitFlag=False)
        # wait in the loop untill finish locking 
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(self.thresholdLocking) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("locking")
        print("Done locking")  
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())

        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], joints[5]-math.radians(5)], 0.01, 0.01, Replanning=True, WaitFlag=False) 
        # get the tool out of the holder
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())

        # # pose after griping to conserve the ring position
        NowPose = self.RobotController.get_pose()
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool1", frame_coordinate=[
                                                             NowPose[0]+self.XtoleranceOutHolder, NowPose[1], NowPose[2], NowPose[3], NowPose[4], NowPose[5]])
        pose = self.TransformationCalculator.transform(
             parent_id="base_link", child_frame_id="tool1")
        self.RobotController.go_to_pose_goal_cartesian(pose, 1, 1,Replanning=True,WaitFlag=False)

        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())
        
        # go to save position
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True, WaitFlag=False)
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        #flatten the list
        self.schedulecollectorofgettingTool = [item for sublist in self.schedulecollectorofgettingTool for item in sublist]
        print(self.schedulecollectorofgettingTool)
        
    def ReturnScrew(self) -> None:
        '''
        --------------------
        This function is used get tool 
        --------------------
        arguments:

            null 
        functionality:
            This function is used to move the robot and get the tool
        --------------------
        '''

       # rotate the robot by 90o for safely get the tool
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 1, 1, Replanning=True)
        
        self.LastPoseScrew= [-0.008646758616481053, -0.3815806593735198, 0.19797902752280033, -3.141458694563271, -3.532326355302995e-05, -0.8195031142692732]
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             self.LastPoseScrew[0], self.LastPoseScrew[1], self.LastPoseScrew[2], self.LastPoseScrew[3], self.LastPoseScrew[4], self.LastPoseScrew[5]])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.10, 0.10,Replanning=True)

        # go inside the holder
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             self.LastPoseScrew[0]-self.XtoleranceOutHolder, self.LastPoseScrew[1], self.LastPoseScrew[2], self.LastPoseScrew[3], self.LastPoseScrew[4], self.LastPoseScrew[5]])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.10, 0.10,Replanning=True)

        # # unlock
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(-100)], 0.01, 0.01, Replanning=False, WaitFlag=False) 
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(self.thresholdLocking) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("unlocking")
        print("Done unlocking")  
        
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], joints[5]+math.radians(5) ], 0.01, 0.01, Replanning=False, WaitFlag=True) 
        
        # pose after griping to conserve the ring position
        NowPose = self.RobotController.get_pose()
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             NowPose[0], NowPose[1], NowPose[2]+self.ZtoleranceAboveTheHolder, NowPose[3], NowPose[4], NowPose[5]])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.1, 0.1,Replanning=True)
        
        # releasec
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True, WaitFlag=False)
#end of old code
    def Operation(self,OperationNo:int)->None:
        '''
        objective: this function as switch case for the operations manily used to see how to check force sensor
        input: OperationNo:int -----> the number of the operation
        output: None
        '''
        if self.getScrewDriverIndex == OperationNo:
            self.ChangeTool()
            if self.ForceZReading >= self.thresholdForToolWeightForceZ: 
                self.State.status=Response.SUCCESSFULL.value
                self.ToolChangePub.publish(self.State)
                print("GettingScrewSuccess")
            else:
                self.State.status=Response.FAILED.value
                self.ToolChangePub.publish(self.State)
                print("GettingScrewFailed")
                pass
            pass
        elif self.returnScrewDriverIndex == OperationNo:
            self.ChangeTool()
            if self.ForceZReading <= self.thresholdForToolWeightForceZ:
                self.State.status=Response.SUCCESSFULL.value
                self.ToolChangePub.publish(self.State)
                print("ReturningScrewSuccess")

            else:
                self.State.status=Response.FAILED.value
                self.ToolChangePub.publish(self.State)
                print("ReturningScrewFailed")
            pass

    def Main(self)->None:
        '''
        objective: this function is the main function of the node
        input: None
        output: None
        '''
        while not rospy.is_shutdown():
            RecievedOpertaion:Int32 = rospy.wait_for_message(Topics.NODE_TO_OPERATE.value, Int32)
            self.Operation(RecievedOpertaion.data)
        pass             
changeTool=GetToolNode(group_name_1="NoTool")


