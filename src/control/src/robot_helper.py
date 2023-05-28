import sys
import copy
import rospy
from moveit_commander import *
import geometry_msgs.msg
import tf2_ros
import tf.transformations
import math
from std_msgs.msg import Bool
from tf.transformations import euler_from_quaternion, quaternion_from_euler
class RobotControl:
    '''
    This class contain module that facilitate the controll of the robot using moveit 
    '''
    def __init__(self,node_name="robot_control",group_name="joint_group"):
        '''
        constructor arguments:
            node_name: name of the node
            group_name: name of the group of joints to be controlled by moveit
        '''
        # initialize the node
        rospy.init_node(node_name)
        # initialize moveit_commander and rospy node
        roscpp_initialize(sys.argv)
        
        # Instantiate a RobotCommander object.
        # Provides information such as the robot’s kinematic model and the robot’s current joint states
        self.robot = RobotCommander()

        print(self.robot.get_group_names())
        # Instantiate a PlanningSceneInterface object.
        # This provides a remote interface for getting, setting, and updating the robot’s internal understanding of the surrounding world:
        self.scene = PlanningSceneInterface()

        # define the group of joints to be controlled by moveit
        self.move_group = MoveGroupCommander(group_name)
        self.move_group.set_planner_id("PRM")
        self.move_group.set_planning_time(10)
        self.move_group.allow_replanning(True)
        pass
    def go_by_joint_angle(self, joint_goal_list,velocity=0.1,acceleration=0.1):
        '''
        --------------------
        This function is used to move the robot to the desired joint state
        --------------------
        arguments:
            joint_goal: list of joint angles in radians
            velocity: velocity of the robot
            acceleration: acceleration of the robot
        '''
        # set the velocity of the robot
        self.move_group.set_max_velocity_scaling_factor(velocity)
        # set the acceleration of the robot
        self.move_group.set_max_acceleration_scaling_factor(acceleration)
        # set the goal joint state
        self.move_group.go(joint_goal_list,wait=True)
        # stop any residual movement
        self.move_group.stop()
        pass
    def go_to_pose_goal_cartesian(self, pose_goal,velocity=0.1,acceleration=0.1):
        '''
        --------------------
        This function is used to move the robot to the desired pose by cartesian path
        --------------------
        arguments:
            pose_goal: geometry_msgs.msg.Pose
            velocity: velocity of the robot
            acceleration: acceleration of the robot
        '''
        # set the velocity of the robot
        self.move_group.set_max_velocity_scaling_factor(velocity)
        # set the acceleration of the robot
        self.move_group.set_max_acceleration_scaling_factor(acceleration)
        # set the goal pose
        self.move_group.set_pose_target(pose_goal)
        # plan the motion
        plan = self.move_group.go(wait=True)
        self.move_group.stop()
        # clear the targets
        self.move_group.clear_pose_targets()
        pass
    def go_to_pose_goal_cartesian_waypoints(self, waypoints,velocity=0.1,acceleration=0.1,list_type=False):
        '''
        --------------------
        This function is used to move the robot to the desired pose by cartesian path
        --------------------
        arguments:
            if list_type is true 
                waypoints: nx6 list of waypoints
                    n: number of waypoints
                    6: x,y,z,roll,pitch,yaw
            if list_type is false 
                waypoints is given by type geometry_msgs.msg.Pose

            velocity: velocity of the robot
        
            acceleration: acceleration of the robot

            list_type indicatie if the given waypoints is geometry_msgs.msg.Pose or list
        '''
        geo_pose=geometry_msgs.msg.Pose() #create a geometry_msgs.msg.Pose() object
        list_of_poses = []
        for ways in waypoints:
            #set the position of the pose
            geo_pose.position.x = ways[0]
            geo_pose.position.y = ways[1]
            geo_pose.position.z = ways[2]
            #set the orientation of the pose
            quantrion = tf.transformations.quaternion_from_euler(ways[3],ways[4],ways[5])
            geo_pose.orientation.x = quantrion[0]
            geo_pose.orientation.y = quantrion[1]
            geo_pose.orientation.z = quantrion[2]
            geo_pose.orientation.w = quantrion[3]
            #append the pose to the list
            list_of_poses.append(copy.deepcopy(geo_pose))

        # set the goal pose
        (plan, fraction) = self.move_group.compute_cartesian_path(
                                    list_of_poses,   # waypoints to follow
                                    0.01,        # eef_step
                                    0.0)         # jump_threshold
        # plan the motion

        # generate a new plan with the new velocity and acceleration by retiming the trajectory
        new_plan=self.move_group.retime_trajectory(self.robot.get_current_state(),plan,velocity_scaling_factor=velocity,acceleration_scaling_factor=acceleration)
        
        # execute the plan
        self.move_group.execute(new_plan,wait=True)

        pass
    def generate_spiral_waypoints(self,starting_pose,angle,step):
        '''
        --------------------
        This function is used to generate a list of waypoints for a spiral path
        --------------------
        arguments:
            starting_pose: geometry_msgs.msg.Pose
            angle: angle of the spiral in radians
            step: step size of the spiral
        --------------------
        return:
            list_of_poses: nx6 list of waypoints
                n: number of waypoints
                6: x,y,z,roll,pitch,yaw
        '''
        list_poses = []
        # generate the waypoints
        for i in range(angle):
            list_poses.append([starting_pose.position.x+step*i*math.cos(i/5),starting_pose.position.y+step*i*math.sin(i/5),starting_pose.position.z,0,-math.pi,0])
        return list_poses
    def get_joint_state(self):
        '''
        fuctionality:
            This function is used to get the robot's joints state
        --------------------
        arguments:
            no arguments
        --------------------
        This function is used to get the current joint state of the robot
        --------------------
        return:
            joint_state: list of joint angles in radians
        --------------------
        '''
        # get the current joint state
        joint_state = self.move_group.get_current_joint_values()
        return joint_state
    def get_pose(self):
        '''
        fuctionality:
            This function is used to get the robot's or the end effector W.R.T the base_link frame
        --------------------
        arguments:
            no arguments
        --------------------
        This function is used to get the current pose of the robot
        --------------------
        return:
            pose: list of pose [x,y,z,roll,pitch,yaw]
        --------------------
        '''
        # get the current pose
        pose = self.move_group.get_current_pose().pose
        EulerAngles = tf.transformations.euler_from_quaternion([pose.orientation.x,pose.orientation.y,pose.orientation.z,pose.orientation.w])
        EndEffectorPose = [pose.position.x,pose.position.y,pose.position.z,EulerAngles[0],EulerAngles[1],EulerAngles[2]]
        return EndEffectorPose
    def get_joints_velocity(self):
        '''
        fucntionality:
            This function is used to get the current joint velocity of the robot
        --------------------
        arguments:
            no arguments
        --------------------
        This function is used to get the current joint velocity of the robot
        --------------------
        return:
            joint_velocity: list of joint velocities in radians per second
        --------------------
        '''
        # get the current joint velocity
        joint_velocity = self.move_group.get_current_joint_velocity()
        return joint_velocity
    def get_end_effector_velocity(self):
        '''
        functionality:
            This function is used to get the current end effector velocity of the robot
        --------------------
        arguments:
            no arguments
        --------------------
        return:
            end_effector_velocity: geometry_msgs.msg.Twist
        --------------------
        '''
        # get the current end effector velocity
        end_effector_velocity = self.move_group.get_current_velocity()
        return end_effector_velocity

class frames_transformations:
    '''
    this class is used to put and tarnsform frames in the tf tree
    '''
    def __init__(self):
        '''
        --------------------
        the constructor of the class
        --------------------
        functioninality:
            This function is used to instantiate the tf2_ros objects
        --------------------
        '''
        # This object is used to store the frames
        self.tfBuffer = tf2_ros.Buffer()

        # instantiate a tf2_ros.TransformListener object
        self.listener = tf2_ros.TransformListener(self.tfBuffer)

        # instantiate a tf2_ros.StaticTransformBroadcaster object
        self.static_broadcaster = tf2_ros.StaticTransformBroadcaster()
        
        # instantiate a tf2_ros.TransformBroadcaster object
        self.broadcaster = tf2_ros.TransformBroadcaster()

        pass

    def transform(self, parent_id, child_frame_id):
        '''
        functioninality:
            This function is used get the transform between two frames and return the pose of the child frame
        --------------------
        arguments:
            parent_id: name of the parent frame
            child_frame_id: name of the child frame
        --------------------
        return:
            pose: geometry_msgs.msg.Pose()
        '''
        # transform the frame

        transform_msg = geometry_msgs.msg.TransformStamped()
        pose=geometry_msgs.msg.Pose()

        transform_msg = self.tfBuffer.lookup_transform(parent_id,child_frame_id,rospy.Time.now())
        #transfer from TransformStamped() to PoseStamped()
        pose.position.x=transform_msg.transform.translation.x
        pose.position.y=transform_msg.transform.translation.y
        pose.position.z=transform_msg.transform.translation.z
        pose.orientation.x=transform_msg.transform.rotation.x
        pose.orientation.y=transform_msg.transform.rotation.y
        pose.orientation.z=transform_msg.transform.rotation.z
        pose.orientation.w=transform_msg.transform.rotation.w
        
        return pose

    def put_frame_static_frame(self,parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[0,0,0,0,0,0]):
        '''
        --------------------
        This function is used to put the frame in the tf tree
        --------------------
        arguments:
            parent_frame_name: name of the parent frame
            child_frame_name: name of the child frame
            frame_coordinate: list of coordinates of the frame 1x6
                [x,y,z,rx,ry,rz]
                translation( in meter ) and rotation ( in radians )
        functionality:
            This function is used to put the frame in the tf tree
            it have delay of 0.05 seconds for the frame to be published
        --------------------
        '''
        frames_msg=geometry_msgs.msg.TransformStamped()
        frames_msg.header.frame_id=parent_frame_name
        frames_msg.child_frame_id=child_frame_name
        frames_msg.transform.translation.x=frame_coordinate[0]
        frames_msg.transform.translation.y=frame_coordinate[1]
        frames_msg.transform.translation.z=frame_coordinate[2]
        quatrion=tf.transformations.quaternion_from_euler(frame_coordinate[3],frame_coordinate[4],frame_coordinate[5])
        frames_msg.transform.rotation.x=quatrion[0]
        frames_msg.transform.rotation.y=quatrion[1]
        frames_msg.transform.rotation.z=quatrion[2]
        frames_msg.transform.rotation.w=quatrion[3]
        # put the frame in the tf tree
        self.static_broadcaster.sendTransform(frames_msg)
        rospy.sleep(0.5)
    def Convert(self,angles):
        (x_or,y_or,z_or)=tf.transformations.quaternion_from_euler(angles[0],angles[1],angles[2],angles[3])
        return [x_or,y_or,z_or]

class EwasteRobot:
    def __init__(self,group_name_1="NoTool"):
        self.RobotController = RobotControl(group_name=group_name_1)
        self.TransformationCalculator=frames_transformations()
        #list of the last pose of the robot after getting the tool
        self.LastPose=[]
        #toelrance value to get the tool 
        self.XtoleranceOutHolder=0.09
        self.XtoleranceInHolder=0.093
        self.ZtoleranceToGetDown=0.0006
        self.ZtoleranceAboveTheHolder=0.05
    def ChangeGroupName(self,groupname_1="NoTool"):
    	self.RobotController = RobotControl(group_name=groupname_1)
        
    def GetScrewTool(self):
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
        #rotate the robot by 90o for safely get the tool 
        self.RobotController.go_by_joint_angle([-1.57,0.0,0.0,0.0,1.57,0.0],0.1,0.1)
        #go above the tool
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[-0.09801404568477788,-0.3760770949075972,0.19738717727263178+self.ZtoleranceAboveTheHolder,3.1357148366265943, 0.0025491386875668, -0.22123945166312356])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.1,0.1)

     	# #go to Holder 
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[-0.09801404568477788,-0.3760770949075972,0.19738717727263178+self.ZtoleranceToGetDown,3.1357148366265943, 0.0025491386875668, -0.22123945166312356])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.01,0.01)
        
    	#lock the tool
        joints=self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle([joints[0],joints[1],joints[2],joints[3],joints[4],math.radians(-68)],0.01,0.01)
        
        #get the tool out of the holder
        NowPose=self.RobotController.get_pose()#pose after griping to conserve the ring position 
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[NowPose[0]+self.XtoleranceOutHolder,NowPose[1],NowPose[2],NowPose[3],NowPose[4], NowPose[5]])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.10,0.10)

        self.LastPose=self.RobotController.get_pose()
        #releasec
        self.RobotController.go_by_joint_angle([-1.57,0.0,0.0,0.0,1.57,0.0],0.1,0.1)

    def ReturnScrew(self):
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

        #go to the tool of before the tool
        self.RobotController.go_by_joint_angle([-1.57,0.0,0.0,0.0,1.57,0.0],0.5,0.2)
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[-0.007926887356337653, -0.37607745548092686, 0.19805928144388488, 3.133940171073178, 5.769876402243904e-05, -0.6326096198336734])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.10,0.10)

        #go inside the holder
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[-0.007926887356337653-self.XtoleranceInHolder, -0.37607745548092686, 0.19805928144388488, 3.133940171073178, 5.769876402243904e-05, -0.6326096198336734])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.10,0.10)

        #unlock
        joints=self.RobotController.get_joint_state()
        self.RobotController.go_by_joint_angle([joints[0],joints[1],joints[2],joints[3],joints[4],math.radians(-93.3)],0.01,0.005)
        
        #go up

        NowPose=self.RobotController.get_pose()#pose after griping to conserve the ring position 
        self.TransformationCalculator.put_frame_static_frame(parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[NowPose[0],NowPose[1],NowPose[2]+self.ZtoleranceAboveTheHolder,NowPose[3],NowPose[4], NowPose[5]])
        pose=self.TransformationCalculator.transform(parent_id="base_link",child_frame_id="tool0")
        self.RobotController.go_to_pose_goal_cartesian(pose,0.1,0.1)

        
    def Homing(self):
        self.RobotController.go_by_joint_angle([0.0,0.0,0.0,0.0,1.57,0.0],0.1,0.1)
    def SpiralSearch(self):
        pose=self.RobotController.generate_spiral_waypoints(self.RobotController.get_pose(),10000,0.0001)
        self.RobotController.go_to_pose_goal_cartesian_waypoints(pose,1,1,list_type=True)

if __name__=="__main__":
   EwasteTooless=EwasteRobot(group_name_1="NoTool")
#    EwasteTooless.Homing()
   #EwasteTooless.SpiralSearch()
   
   #EwasteTooless.ReturnScrew()
   EwasteTooless.GetScrewTool()
   
   #EwasteTooless.Homing()
