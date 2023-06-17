import rospy
import sys
sys.path.append(".../")
from enums.nodes import Nodes
from enums.response_status import Response

#from enums.nodes import Nodes
from enums.topics import Topics
from std_msgs.msg import Int32, Bool
from CentralNode.msg import node_response as NodeResponse
from storage.db import RobotDatabase
import storage.storage_keys as StorageKeys
from operations import OPERATIONS
from handlers.success_handler import handleSuccess
from handlers.in_progress_handler import handleInProgress

def findIndices(x, item):
    indices = []
    for idx, value in enumerate(x):
        if value == item:
            indices.append(idx)
    return indices
class CentralNode:
    def __init__(self):
        self.subscribers = {}
        self.publishers = {}
        self.currentNode = 0
        self.objectExists = False
    def initPublishers(self):
        self.publishers = {}
        self.publishers[Topics.NODE_TO_OPERATE] = rospy.Publisher(Topics.NODE_TO_OPERATE.value, Int32,queue_size=1,latch=True)
        self.publishers[Topics.START_COLLISION_DETECTED] = rospy.Publisher(Topics.START_COLLISION_DETECTED.value, Bool,queue_size=1)

    def initSubscribers(self):
        self.subscribers = {}
        self.subscribers[Topics.NODE_SUCCESS] = rospy.Subscriber(Topics.NODE_SUCCESS.value, NodeResponse, self.nodeSuccessCallback,queue_size=1)
        # self.subscribers[Topics.COLLISION_DETECTED] = rospy.Subscriber(Topics.COLLISION_DETECTED, Bool)
    
    def start(self):
        rospy.init_node(Nodes.CENTRAL.value)
        self.initPublishers()
        self.initSubscribers()
        rate = rospy.Rate(10)

        while not rospy.is_shutdown():
            self.publishers[Topics.NODE_TO_OPERATE].publish(self.currentNode)
            rospy.spin()


    def config(self):
        db = RobotDatabase()
        data = db.readAllFromDB()
        if self.objectExists:
            if db.isNotEmpty():
                pass

                

    def nodeSuccessCallback(self,nodeResponse:NodeResponse):
        print(f"Node success callback {nodeResponse.status}")
        print(Response.SUCCESSFULL.value)
        if nodeResponse.status == Response.IN_PROGRESS.value:
            handleInProgress(self.currentNode, nodeResponse)
        elif nodeResponse.status == Response.SUCCESSFULL.value:
            handleSuccess(self.currentNode, nodeResponse)
            RobotDatabase().addToDB(StorageKeys.OPERATION_DONE, self.currentNode)
            if self.currentNode < len(OPERATIONS):
                RobotDatabase().addToDB(StorageKeys.OPERATION_INPROGRESS, self.currentNode + 1)
                self.currentNode += 1
                self.publishers[Topics.NODE_TO_OPERATE].publish(self.currentNode)
        
if __name__ == '__main__':
    try:
        c = CentralNode()
        c.start()
    except rospy.ROSInterruptException:
        pass 