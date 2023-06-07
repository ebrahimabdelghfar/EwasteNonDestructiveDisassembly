from abb_robot_msgs.msg import SystemState
import rospy
import roslaunch
class HeartBeat:
    def __init__(self) -> None:
        RobotState = SystemState()
        rospy.init_node("MotorHeartBeat")
        rospy.Subscriber("/rws/system_states", SystemState, self.RobotStateCallback)
        self.launch = roslaunch.scriptapi.ROSLaunch()
        self.launch.start()
        pass

    def RobotStateCallback(self,RobotState:SystemState):
        if RobotState.auto_mode == True and RobotState.motors_on == True and RobotState.rapid_running == True:
            #do nothing
            print("Robot all is ok")
            pass
        elif RobotState.auto_mode == False :
            print("Robot is not in auto mode")
            #do nothing
            pass
        elif RobotState.auto_mode == True and (RobotState.motors_on == False or RobotState.rapid_running == False):
            print("Robot is Starting")
            node = roslaunch.core.Node(package="egm_config",node_type="start_robot.bash")
            self.launch.launch(node)
        pass

MotorHeartBeat=HeartBeat()

while not rospy.is_shutdown():
    rospy.sleep(0.1)
    pass