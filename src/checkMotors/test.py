from CentralNode.msg import node_response 
import rospy 
from enums.response_status import Response 
data=node_response()
data.status=Response.SUCCESSFULL.value
data.nodeId=1
data.extraMessage="hello"
rospy.init_node("test")
pub=rospy.Publisher("/node_response",node_response,queue_size=10)
rate=rospy.Rate(10)

while not rospy.is_shutdown():
    pub.publish(data)
    rate.sleep()
