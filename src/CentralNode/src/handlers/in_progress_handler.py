from src.storage.db import RobotDatabase
from operations import OPERATIONS
import sys
from resources.src.enums.nodes import Nodes
from resources.src.enums.tools import Tools
import src.storage.storage_keys as StorageKeys
#from enums.nodes import Nodes
sys.path.append("./")

def findIndices(x, item):
    indices = []
    for idx, value in enumerate(x):
        if value == item:
            indices.append(idx)
    return indices

def handleInProgress(currentNode, nodeResponse):
    if(currentNode in findIndices(OPERATIONS,Nodes.APPROACH_AND_ENGAGE)):
        #TODO change data to integer
        RobotDatabase().addToDB(StorageKeys.SCREW_INDEX, nodeResponse.extraData)
    elif(currentNode in findIndices(OPERATIONS, Nodes.CHANGE_TOOL)):
        #TODO change data to integer
        RobotDatabase().addToDB(StorageKeys.CHANGE_TOOL_SCHEDULE_INDEX, nodeResponse.extraData)



