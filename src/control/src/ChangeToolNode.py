from robot_helper import *
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from geometry_msgs.msg import WrenchStamped


class GetToolNode:
    def __init__(self, group_name_1="NoTool", StopTourqeThershold1=0.5):
        self.RobotController = RobotControl(group_name=group_name_1)
        self.TransformationCalculator = frames_transformations()
        # list of the last pose of the robot after getting the tool
        self.LastPose = []
        # toelrance value to get the tool
        self.XtoleranceOutHolder = 0.09
        self.XtoleranceInHolder = 0.093
        self.ZtoleranceToGetDown = 0.002
        self.ZtoleranceAboveTheHolder = 0.05
        
        # Threshold to check z torque while unlocking
        self.thresholdLocking = -1.1
        #end
        # self.OperationNo =rospy.get_param("/OrdersOfOperation/GettingToolNode")
        # define the Topic that being used
        self.ToolGettingPub = rospy.Publisher(
            "/ToolGettingSuccess", Bool, queue_size=1)
        self.TorqueReadingPub = rospy.Subscriber(
            "/ft_sensor_wrench/wrench/raw", WrenchStamped, self.TorqueReadingCallBack)
        self.TorqueReading = 0.0
        self.StopTourqeThershold = StopTourqeThershold1

    def TorqueReadingCallBack(self, data: WrenchStamped) -> None:
        '''
        objective: this function is used to get the torque reading from the sensor
        '''
        self.TorqueReading = data.wrench.torque.z
        

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

        # go above the tool
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.09868947696839801, -0.38160183758005417, 0.1959320787026243+self.ZtoleranceAboveTheHolder, -3.141268865426805,0, -0.35668452629565967])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(
            pose, 0.5, 0.5, Replanning=True)

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
            print(self.TorqueReading)

            if (abs(self.TorqueReading) >= abs(self.thresholdLocking) ):
                self.RobotController.Stop()
                print("Breaking")
                break
            else :
                print("locking")
        print("Done locking")     
        # get the tool out of the holder
        
        # pose after griping to conserve the ring position
        NowPose = self.RobotController.get_pose()
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             NowPose[0]+self.XtoleranceOutHolder, NowPose[1], NowPose[2], NowPose[3], NowPose[4], NowPose[5]])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.10, 0.10)

        self.LastPose = self.RobotController.get_pose()
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

        # go to the tool of before the tool
        self.RobotController.go_by_joint_angle(
            [-1.57, 0.0, 0.0, 0.0, 1.57, 0.0], 0.5, 0.2,Replanning=True)
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             self.LastPose[0], -0.37607745548092686, 0.19805928144388488, 3.133940171073178, 5.769876402243904e-05, -0.6326096198336734])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.10, 0.10,Replanning=True)

        # go inside the holder
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             -0.007926887356337653-self.XtoleranceInHolder, -0.37607745548092686, 0.19805928144388488, 3.133940171073178, 5.769876402243904e-05, -0.6326096198336734])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.10, 0.10,Replanning=True)

        # unlock
        joints = self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle(
            [joints[0], joints[1], joints[2], joints[3], joints[4], math.radians(-93.3)], 0.01, 0.005,Replanning=True)

        # go up

        # pose after griping to conserve the ring position
        NowPose = self.RobotController.get_pose()
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link", child_frame_name="tool0", frame_coordinate=[
                                                             NowPose[0], NowPose[1], NowPose[2]+self.ZtoleranceAboveTheHolder, NowPose[3], NowPose[4], NowPose[5]])
        pose = self.TransformationCalculator.transform(
            parent_id="base_link", child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose, 0.1, 0.1,Replanning=True)
    def StartOperation(self):
        while not rospy.is_shutdown():
            RecievedOpertaion:Int32 =rospy.wait_for_message("/NodeToOperate", Int32)
            if self.OperationNo == RecievedOpertaion.data:
                self.GetScrewTool()
                self.OperationNo = 0
            elif self.OperationNo == 2:
                self.ReturnScrew()
                self.OperationNo = 0
            else:
                pass

test=GetToolNode(group_name_1="NoTool")
test.GetScrewTool()
# while True:
#     rospy.sleep()