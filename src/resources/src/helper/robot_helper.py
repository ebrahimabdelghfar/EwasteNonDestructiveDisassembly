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
import time
class RobotControl:
    '''
    This class contain module that facilitate the controll of the robot using moveit 
    '''
    def __init__(self,node_name="robot_control",group_name="joint_group",PlanningId="RRTConnect",JointTolerance=0.0001,PositionTolerance=0.0001,OrientationTolerance=0.0001):
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
        self.move_group.set_planner_id(PlanningId)
        # set the planning time and flags
        self.move_group.set_num_planning_attempts(100)
        self.move_group.set_planning_time(50)
        self.move_group.allow_replanning(True)
        self.move_group.allow_looking(True)
        #adjust tolerance of the joint 
        self.move_group.set_goal_joint_tolerance(JointTolerance)
        self.move_group.set_goal_position_tolerance(PositionTolerance)
        self.move_group.set_goal_orientation_tolerance(OrientationTolerance)
        self.PostionTolerance=0.0001 
        pass
    def Stop(self)->None:
        '''
        functionality:
            This function is used to stop the robot
        --------------------
        arguments:
            no arguments
        --------------------
        '''
        # stop the robot
        self.move_group.stop()
        self.move_group.clear_pose_targets()
        rospy.sleep(0.1)# wait for the robot to stop
        print("stop")
        pass
    def get_joint_state(self)->list:
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
    def get_pose(self)->list:
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
    def go_by_joint_angle(self, joint_goal_list,velocity=0.1,acceleration=0.1,Replanning=True,WaitFlag=True)->None:
        '''
        --------------------
        This function is used to move the robot to the desired joint state
        --------------------
        arguments:
            joint_goal: list of joint angles in radians
            velocity: velocity of the robot
            acceleration: acceleration of the robot
            replan: if True, the robot will re-execute the path if it doesn't reach the goal under certain tolerance
            WaitFlag: if True, the robot will wait until it reaches the goal and will not execute any other commands
        '''
        # set the velocity of the robot
        self.move_group.set_max_velocity_scaling_factor(velocity)
        # set the acceleration of the robot
        self.move_group.set_max_acceleration_scaling_factor(acceleration)
        #re-execute if doesn't reach the goal
        if Replanning==True:
            state=self.move_group.go(joint_goal_list,wait=False)
            start=time.time()
            last_joint_state=[0,0,0,0,0,0]
            while not rospy.is_shutdown() and state==True:
                # stop any residual movement
                current_joints = self.get_joint_state()
                if all(abs(current_joints[i]-joint_goal_list[i])<self.PostionTolerance for i in range(len(current_joints))):
                    self.Stop()
                    print ("reached")
                    break
                if time.time()-start>2:
                    if all(abs(last_joint_state[i]-current_joints[i])>self.PostionTolerance for i in range(len(current_joints))):
                        pass
                    else:
                        break
                    last_joint_state=self.get_joint_state()
                    start=time.time()

            pass
        else:
            if WaitFlag==True:
                self.move_group.go(joint_goal_list,wait=WaitFlag)
                self.Stop()
            else:
                self.move_group.go(joint_goal_list,wait=WaitFlag)
            pass
#function that calculate the velocity and acceleration of the robot durning the movement

    def go_to_pose_goal_cartesian(self, pose_goal,velocity=0.1,acceleration=0.1,Replanning=False,WaitFlag=False)->None:
        '''
        --------------------
        This function is used to move the robot to the desired pose by cartesian path
        --------------------
        arguments:
            pose_goal: geometry_msgs.msg.Pose
            velocity: velocity of the robot
            acceleration: acceleration of the robot
            replan: if True, the robot will re-execute the path if it doesn't reach the goal under certain tolerance
            WaitFlag: if True, the robot will wait until it reaches the goal and will not execute any other commands
        '''
        # set the velocity of the robot
        self.move_group.set_max_velocity_scaling_factor(velocity)
        # set the acceleration of the robot
        self.move_group.set_max_acceleration_scaling_factor(acceleration)
        #re-execute if doesn't reach the goal
        self.move_group.set_pose_target(pose_goal)
        if Replanning==True:
            plan = self.move_group.go(wait=False)
            start=time.time()
            last_pose=[0,0,0,0,0,0]
            while not rospy.is_shutdown() and plan==True:
                current_pose = self.get_pose()
                if all(abs(current_pose[i]-pose_goal[i])<self.PostionTolerance for i in range(len(current_pose))):
                    self.Stop()
                    print ("reached")
                    break
                if time.time()-start>2:
                    if any(abs(last_pose[i]-current_pose[i])>0.01 for i in range(len(current_pose))):
                        pass
                    else:
                        print("stucked")
                        break
                    last_pose=self.get_pose()
                    start=time.time()
                # print ("re-execute")
            pass
        else:
            if WaitFlag==True:
                self.move_group.go(wait=WaitFlag)
                self.Stop()
            else:
                self.move_group.go(wait=WaitFlag)
            pass
    def go_to_pose_goal_cartesian_waypoints(self, waypoints,velocity=0.1,acceleration=0.1,list_type=False,waitFlag=False,positionTolerance=0.01)->None:
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

            list_type indicatie if the given waypoints is geometry_msgs.msg.Pose or list of waypoints [[x,y,z,roll,pitch,yaw],...]
        '''
        geo_pose=geometry_msgs.msg.Pose() #create a geometry_msgs.msg.Pose() object
        list_of_poses = []
        #start with appending the initial starting
        if list_type==True:
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
        else:
            for ways in waypoints:
                list_of_poses.append(copy.deepcopy(ways))
        # set the goal pose
        (plan, fraction) = self.move_group.compute_cartesian_path(
                                    list_of_poses,   # waypoints to follow
                                    positionTolerance,        # eef_step
                                    0.0)         # jump_threshold

        # generate a new plan with the new velocity and acceleration by retiming the trajectory
        new_plan=self.move_group.retime_trajectory(self.robot.get_current_state(),plan,velocity_scaling_factor=velocity,acceleration_scaling_factor=acceleration)
        # execute the plan
        state=self.move_group.execute(new_plan,wait=waitFlag)
        pass

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
            pose: geometry_msgs.msg.Pose() , list of 6d pose
        '''
        # transform the frame

        transform_msg = geometry_msgs.msg.TransformStamped()
        pose=geometry_msgs.msg.Pose()
        Pose2List=[]
        # transform_msg = self.tfBuffer.lookup_transform(parent_id,child_frame_id,rospy.Time.now(),timeout=rospy.Duration(0.5))
        transform_msg = self.tfBuffer.lookup_transform(parent_id,child_frame_id,rospy.Time(0),timeout=rospy.Duration(0.5))
        #transfer from TransformStamped() to PoseStamped()
        pose.position.x=transform_msg.transform.translation.x
        pose.position.y=transform_msg.transform.translation.y
        pose.position.z=transform_msg.transform.translation.z
        pose.orientation.x=transform_msg.transform.rotation.x
        pose.orientation.y=transform_msg.transform.rotation.y
        pose.orientation.z=transform_msg.transform.rotation.z
        pose.orientation.w=transform_msg.transform.rotation.w
        #convert the it to 6d list
        angles=tf.transformations.euler_from_quaternion([pose.orientation.x,pose.orientation.y,pose.orientation.z,pose.orientation.w])
        Pose2List=[pose.position.x,pose.position.y,pose.position.z,angles[0],angles[1],angles[2]]
        return Pose2List
    def put_frame_static_frame(self,parent_frame_name="base_link",child_frame_name="tool0",frame_coordinate=[0,0,0,0,0,0])->None:
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
        pass