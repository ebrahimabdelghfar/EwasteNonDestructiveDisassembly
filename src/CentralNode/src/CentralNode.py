from abb_robot_msgs.msg import SystemState
import rospy
import roslaunch
from std_msgs.msg import String,Bool
from geometry_msgs.msg import WrenchStamped
from consts import TopicNames

#rospy.Subscriber("/topic_name", String, callback)
def ListofScrewsCallback(data):
    pass
def ForceTorqueCallback(data):
    pass

def CollisionDetectionCallback(data):
    pass
def ToolGettingCallback(data):
    pass
def ClampingCallback(data):
    pass
print(TopicNames.LISTOFSCREWS)
VisionSubscriber=rospy.Subscriber(TopicNames.LISTOFSCREWS,String,ListofScrewsCallback)
ForceTorqueSubscriber=rospy.Subscriber("ForceTorque",WrenchStamped,ForceTorqueCallback)
CollisionDetectionSubscriber=rospy.Subscriber("CollisionDetected",Bool,CollisionDetectionCallback)
GetToolSubscriber=rospy.Subscriber("ToolGettingSuccess",Bool,ToolGettingCallback)
ClampingSubscriber=rospy.Subscriber("ClampingState",Bool,)
