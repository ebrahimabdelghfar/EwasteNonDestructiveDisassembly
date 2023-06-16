import rospy
import sys
sys.path.append(".../")
from enums.nodes import Nodes
from enums.topics import Topics
from std_msgs.msg import Int32, Bool
from CentralNode.msg import node_response as NodeResponse
from src.storage.db import RobotDatabase


class CentralNode:
    def __init__(self):
        self.subscribers = {}
        self.publishers = {}
        self.currentNode = 0
    def initPublishers(self):
        self.publishers = {}
        self.publishers[Topics.NODE_TO_OPERATE] = rospy.publisher(Topics.NODE_TO_OPERATE, Int32)
        self.publishers[Topics.START_COLLISION_DETECTED] = rospy.publisher(Topics.START_COLLISION_DETECTED, Bool)


    def initSubscribers(self):
        self.subscribers = {}
        self.subscribers[Topics.NODE_TO_OPERATE] = rospy.Subscriber(Topics.NODE_SUCCESS, NodeResponse)
        self.subscribers[Topics.START_COLLISION_DETECTED] = rospy.Subscriber(Topics.COLLISION_DETECTED, Bool)

    
    def start(self):
        rospy.init_node(Nodes.CENTRAL.value)
        self.initPublishers()
        self.initSubscribers()
        rate = rospy.rate(10)

        while not rospy.is_shutdown():
            self.publishers[Topics.NODE_TO_OPERATE].publish()

    def config(self):
        db = RobotDatabase()
        data = db.readAllFromDB()
        pass



    def nodeSuccessCallback(self):
        pass
