import rospy
from enums.topics import Topics
from enums.nodes import Nodes
from CentralNode.msg import node_response
from std_msgs.msg import Int32
class Hardwarebridge:
    def __init__(self) -> None:
        self.SuccessMsg=node_response()
        rospy.init_node(Nodes.CLAMPING.value)
        rospy.Subscriber("/NODE_SUCCESSArduino",Int32,self.NodeSuccessARDUINO)
        self.Success=rospy.Publisher(Topics.NODE_SUCCESS.value,node_response,queue_size=1)
    def NodeSuccessARDUINO(self,data:Int32):
        self.SuccessMsg.status=data.data
        self.Success.publish(self.SuccessMsg)

Hardwarebridge()
rospy.spin()