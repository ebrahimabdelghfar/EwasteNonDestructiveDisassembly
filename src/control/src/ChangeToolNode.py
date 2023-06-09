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
from enums.operations import OPERATIONS, getChangeToolIndices
from CentralNode.msg import node_response
from CentralNode.srv import Schedular , SchedularResponse , SchedularRequest
class GetToolNode:
    def __init__(self, group_name_1:str="NoTool", StopTourqeThershold1:float=0.5):
        self.RobotController = RobotControl(node_name=Nodes.CHANGE_TOOL.value,group_name=group_name_1,PositionTolerance=0.001,OrientationTolerance=0.001,PlanningId="PRMkConfigDefault")
        self.TransformationCalculator = frames_transformations()
        # list of the last pose of the robot after getting the tool
        self.LastPoseScrew = []
        # toelrance value to get the tool
        self.XtoleranceOutHolder = 0.09
        self.XtoleranceInHolder = 0.093
        self.ZtoleranceToGetDown = 0.002
        self.ZtoleranceAboveTheHolder = 0.05
        # Threshold to check z torque while unlocking
        self.thresholdLocking = -0.6
        # To check z force if tool is attached or not (tool weight)
        self.thresholdForToolWeightForceZ = 2.5
        # define the Topic and sever that being used
        self.ToolChangePub = rospy.Publisher(
            Topics.NODE_SUCCESS.value, node_response, queue_size=1)
        self.TorqueZReadingPub = rospy.Subscriber(
            Topics.ForceSensorWrenchWeightedFilter.value, WrenchStamped, self.FTReadingCallBack)
        self.ToolChangeClient = rospy.ServiceProxy(Services.SCHEDULAR.value, Schedular, persistent=True)
        self.CentralResponse = SchedularResponse()
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
        self.getScrewDriverIndex, self.returnScrewDriverIndex, self.getMillingIndex, self.returnMillingIndex = getChangeToolIndices()
        self.unscrewIndex = OPERATIONS.index(Nodes.APPROACH_AND_ENGAGE)
        self.visionIndex = OPERATIONS.index(Nodes.VISION)
        # self.getScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
        # self.getMillingIndex = self.returnScrewDriverIndex + 1
        # self.returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, self.getMillingIndex + 1)
        # self.returnScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
        # self.getMillingIndex = self.returnScrewDriverIndex + 1
        # self.returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, self.getMillingIndex + 1)
        # self.getScrewDriverIndex = self.returnMillingIndex + 1
        print(f"the screw no : {self.getMillingIndex} , the return screw index :{self.returnMillingIndex}")

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
        self.waypoints = self.reshapeList(list(self.CentralResponse.waypoints))
        print(self.waypoints)
        self.waypointstype = list(self.CentralResponse.waypoint_types)
        self.CheckForceFlag = list(self.CentralResponse.checkTorque)
        self.Velocity = list(self.CentralResponse.velocity)
        self.Acceleration = list(self.CentralResponse.acceleration)
        #save the schedule of getting and returning tool
        for ways in self.waypoints:
            print(self.waypointstype[self.waypoints.index(ways)])
            if self.waypointstype[self.waypoints.index(ways)]==schedulars.JointType.value:
                if self.CheckForceFlag[self.waypoints.index(ways)]==schedulars.CheckForceSensor.value:
                    self.RobotController.go_by_joint_angle(ways, self.Velocity[self.waypoints.index(ways)], self.Acceleration[self.waypoints.index(ways)], Replanning=False,WaitFlag=False)
                    self.CheckToolTourqe()              
                    pass
                else:
                    print
                    self.RobotController.go_by_joint_angle(ways, self.Velocity[self.waypoints.index(ways)], self.Acceleration[self.waypoints.index(ways)], Replanning=True,WaitFlag=False)
                    pass
                pass
            elif self.waypointstype[self.waypoints.index(ways)]==schedulars.CartesianType.value:
                if self.CheckForceFlag[self.waypoints.index(ways)]==schedulars.CheckForceSensor.value:
                    self.RobotController.go_to_pose_goal_cartesian(ways, self.Velocity[self.waypoints.index(ways)], self.Acceleration[self.waypoints.index(ways)], Replanning=True,WaitFlag=False)
                    self.CheckToolTourqe()
                    pass
                else:
                    self.RobotController.go_to_pose_goal_cartesian(ways, self.Velocity[self.waypoints.index(ways)], self.Acceleration[self.waypoints.index(ways)], Replanning=True,WaitFlag=False)
                    pass
                pass
            #after each point go it will increment the index of the node
            #and publish the status of the node
            self.State.status=Response.IN_PROGRESS.value
            self.State.extraMessage=str(self.waypoints.index(ways))
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
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True,WaitFlag=False)
        
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        # # go above the tool
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceAboveTheHolder, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 0.1, 0.1, Replanning=True,WaitFlag=False)
        
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
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.1, 0.1,Replanning=True,WaitFlag=False)

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
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True)
        
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
    def getMilling(self):
        self.RobotController.go_by_joint_angle(
           [1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 1, 1, Replanning=True,WaitFlag=False)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        millingpose=[-0.09151079575874518+0.0022, 0.38115756747328866, 0.19735952156206063, -3.112502050572731, 0.021292323008053112, 0.8125718156068518]
        self.RobotController.go_to_pose_goal_cartesian([millingpose[0],millingpose[1],millingpose[2]+self.ZtoleranceAboveTheHolder,millingpose[3],millingpose[4],millingpose[5]],velocity=1,acceleration=1,Replanning=True,WaitFlag=False)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())
        self.RobotController.go_to_pose_goal_cartesian([millingpose[0],millingpose[1],millingpose[2]+self.ZtoleranceToGetDown,millingpose[3],millingpose[4],millingpose[5]],velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=False)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle([joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(150)], 0.01, 0.01, Replanning=False, WaitFlag=False)
        # wait in the loop untill finish locking 
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(-0.6) ):
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
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        NowPose = self.RobotController.get_pose() 
        self.RobotController.go_to_pose_goal_cartesian([NowPose[0]+self.XtoleranceOutHolder, NowPose[1], NowPose[2], NowPose[3], NowPose[4], NowPose[5]],velocity=1,acceleration=1,Replanning=True)   
        print(self.RobotController.get_pose()) 
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())      
        self.schedulecollectorofgettingTool = [item for sublist in self.schedulecollectorofgettingTool for item in sublist]
        print(self.schedulecollectorofgettingTool) 

    def returnMilling(self):
        self.RobotController.go_by_joint_angle(
            [1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 1, 1, Replanning=True)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        returnMill=[0.0006220377928233731, 0.3809777629928159, 0.19945188907163106, -3.120342633470789, 0.02873265492544359, 0.5147456481987344]
        self.RobotController.go_to_pose_goal_cartesian([returnMill[0], returnMill[1], returnMill[2], returnMill[3], returnMill[4], returnMill[5]],velocity=1,acceleration=1,Replanning=True)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())        
        self.RobotController.go_to_pose_goal_cartesian([returnMill[0]-self.XtoleranceOutHolder, returnMill[1], returnMill[2], returnMill[3], returnMill[4], returnMill[5]],velocity=1,acceleration=1,Replanning=True)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())        
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(40)], 0.01, 0.01, Replanning=False, WaitFlag=False) 
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(0.6) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("unlocking")
        print("Done unlocking")  
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], joints[5]+math.radians(5)], 0.01, 0.01, Replanning=True, WaitFlag=False) 
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        NowPose = self.RobotController.get_pose()
        self.RobotController.go_to_pose_goal_cartesian(pose_goal=[NowPose[0], NowPose[1], NowPose[2]+self.ZtoleranceAboveTheHolder, NowPose[3], NowPose[4], NowPose[5]],velocity=1,acceleration=1,Replanning=True)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_pose())
        self.RobotController.go_by_joint_angle(
            [1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True, WaitFlag=False)
        self.schedulecollectorofgettingTool.append(self.RobotController.get_joint_state())
        self.schedulecollectorofgettingTool = [item for sublist in self.schedulecollectorofgettingTool for item in sublist]
        print(self.schedulecollectorofgettingTool) 
        pass

    def Operation(self,OperationNo:int)->None:
        print("Operation Number ",OperationNo)
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
        elif self.getMillingIndex == OperationNo:
            self.ChangeTool()
            if self.ForceZReading >= self.thresholdForToolWeightForceZ: 
                self.State.status=Response.SUCCESSFULL.value
                self.ToolChangePub.publish(self.State)
                print("GettingMillingSuccess")
            else:
                self.State.status=Response.FAILED.value
                self.ToolChangePub.publish(self.State)
                print("GettingMillingFailed")
                pass
            pass
        elif self.returnMillingIndex == OperationNo:
            self.ChangeTool()
            if self.ForceZReading <= self.thresholdForToolWeightForceZ:
                self.State.status=Response.SUCCESSFULL.value
                self.ToolChangePub.publish(self.State)
                print("ReturningMillingSuccess")

            else:
                self.State.status=Response.FAILED.value
                self.ToolChangePub.publish(self.State)
                print("ReturningMillingFailed")
            pass
    def Main(self)->None:
        '''
        objective: t his function is the main function of the node
        input: None
        output: None
        '''
        while not rospy.is_shutdown():
            RecievedOpertaion:Int32 = rospy.wait_for_message(Topics.NODE_TO_OPERATE.value, Int32)
            self.Operation(RecievedOpertaion.data)
        pass             
changeTool=GetToolNode(group_name_1="NoTool")
changeTool.GetScrewTool()


