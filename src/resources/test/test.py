import rospy
from std_msgs.msg import String
st=rospy.Publisher("test",String,queue_size=10)
rospy.init_node("s")
