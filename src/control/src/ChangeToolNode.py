from robot_helper import *
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from geometry_msgs.msg import WrenchStamped


class GetToolNode:
    def __init__(self, group_name_1="NoTool", StopTourqeThershold1=0.5):
        self.RobotController = RobotControl(group_name=group_name_1)
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
        
        # Operation numbers from parameters file to integrate with centeral node
        self.GettingScrewOperationNo =rospy.get_param("/OrdersOfOperation/GettingScrewNode")
        self.ReturnScrewOperationNo =rospy.get_param("/OrdersOfOperation/ReturnScrewNode")
        
        self.GettingMillingOperationNo =rospy.get_param("/OrdersOfOperation/GettingMillingNode")
        self.ReturnMillingOperationNo =rospy.get_param("/OrdersOfOperation/ReturnMillingNode")
        
        
        # States to be published to the centeral node
        
        self.GettingScrewSuccess =rospy.get_param("/ToolChangeState/GettingScrewSuccess")
        self.GettingScrewFailed =rospy.get_param("/ToolChangeState/GettingScrewFailure")
        
        self.ReturningScrewSuccess =rospy.get_param("/ToolChangeState/ReturningScrewSuccess")
        self.ReturningScrewFailed =rospy.get_param("/ToolChangeState/ReturningScrewFailure")
    
        
        self.GettingMillingSuccess =rospy.get_param("/ToolChangeState/GettingMillingSuccess")
        self.GettingMillingFailed =rospy.get_param("/ToolChangeState/GettingScrewFailure")
        
        self.ReturningMillingSuccess =rospy.get_param("/ToolChangeState/ReturningMillingSuccess")
        self.ReturningMillingFailed=rospy.get_param("/ToolChangeState/ReturningMillingFailure")
        
        
        # define the Topic that being used
        self.ToolChangePub = rospy.Publisher(
            "/ToolChangingState", Int32, queue_size=1)
        self.TorqueZReadingPub = rospy.Subscriber(
            "/ft_sensor_wrench/wrench/raw", WrenchStamped, self.FTReadingCallBack)
        self.TorqueZReading = 0.0
        self.ForceZReading = 0.0
        self.StopTourqeThershold = StopTourqeThershold1

    def FTReadingCallBack(self, data: WrenchStamped) -> None:
        '''
        objective: this function is used to get the torque reading from the sensor
        '''
        self.TorqueZReading = data.wrench.torque.z
        self.ForceZReading = data.wrench.force.z


    def ChangeGroupName(self, groupname_1="NoTool") -> None:
        self.RobotController = RobotControl(group_name=groupname_1)

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

        # # go above the tool
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceAboveTheHolder, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 1, 1, Replanning=True)

        # go to Holder
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceToGetDown, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 0.005, 0.005, Replanning=True,WaitFlag=False)


        # lock the tool
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(-50)], 0.01, 0.01, Replanning=False, WaitFlag=False) 
        while True :
            print(self.TorqueZReading)

            if (abs(self.TorqueZReading) >= abs(self.thresholdLocking) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("locking")
        print("Done locking")  
           
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
        [joints[0], joints[1], joints[2], joints[3], joints[4], joints[5]-math.radians(5)], 0.01, 0.01, Replanning=False, WaitFlag=True) 
        # get the tool out of the holder
        
        # # pose after griping to conserve the ring position
        NowPose = self.RobotController.get_pose()
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool1", frame_coordinate=[
                                                             NowPose[0]+self.XtoleranceOutHolder, NowPose[1], NowPose[2], NowPose[3], NowPose[4], NowPose[5]])
        pose = self.TransformationCalculator.transform(
             parent_id="base_link", child_frame_id="tool1")
        self.RobotController.go_to_pose_goal_cartesian(pose, 1, 1,Replanning=True,WaitFlag=False)

        # self.LastPose = self.RobotController.get_pose()
        # print(self.LastPose)
        
        # releasec
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.1, 0.1, Replanning=True, WaitFlag=False)
        
        

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
        
        # # go up

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

    def StartOperation(self):
        while not rospy.is_shutdown():
            RecievedOpertaion:Int32 =rospy.wait_for_message("/NodeToOperate", Int32)
            
            # Order recieved for getting unscrewing tool
            if self.GettingScrewOperationNo == RecievedOpertaion.data:
                self.GetScrewTool()
                if self.ForceZReading >= self.thresholdForToolWeightForceZ:
                    self.ToolChangePub.publish(self.GettingScrewSuccess)
                    print("GettingScrewSuccess")
                else:
                    self.ToolChangePub.publish(self.GettingScrewFailed)
                    print("GettingScrewFailed")
                    
            # Order recieved for returning unscrewing tool
            elif self.ReturnScrewOperationNo == RecievedOpertaion.data:
                self.ReturnScrew()
                if self.ForceZReading <= self.thresholdForToolWeightForceZ:
                    self.ToolChangePub.publish(self.ReturningScrewSuccess)
                    print("ReturningScrewSuccess")

                else:
                    self.ToolChangePub.publish(self.ReturningScrewFailed)
                    print("ReturningScrewFailed")

            else:
                pass
                


changeTool=GetToolNode(group_name_1="NoTool")
changeTool.StartOperation()

# test=GetToolNode(group_name_1="NoTool")
# test.GetScrewTool()
# test.ReturnScrew()
# while True:
#     rospy.sleep()

