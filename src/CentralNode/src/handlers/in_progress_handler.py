from storage.db import RobotDatabase
from enums.operations import OPERATIONS, getChangeToolIndices
import sys
from enums.nodes import Nodes
from enums.tools import Tools
import storage.storage_keys as StorageKeys
#from enums.nodes import Nodes
sys.path.append("./")

def findIndices(x, item):
    indices = []
    for idx, value in enumerate(x):
        if value == item:
            indices.append(idx)
    return indices

def handleInProgress(currentNode, nodeResponse, schedule):
    if(currentNode in findIndices(OPERATIONS,Nodes.APPROACH_AND_ENGAGE)):
        #TODO change data to integer
        RobotDatabase().addToDB(StorageKeys.SCREW_INDEX, nodeResponse.extraMessage)
    elif(currentNode in findIndices(OPERATIONS, Nodes.CHANGE_TOOL)):
        #TODO change data to integer
        popFromSchedule()
        RobotDatabase().addToDB(StorageKeys.CHANGE_TOOL_SCHEDULE_INDEX, nodeResponse.extraMessage)


def popFromSchedule(schedule):
    schedule[StorageKeys.VEL].pop(0)
    schedule[StorageKeys.ACC].pop(0)
    schedule[StorageKeys.CHECK_FORCE].pop(0)
    schedule[StorageKeys.WAYPOINTS_TYPES].pop(0)
    schedule[StorageKeys.WAYPOINTS] = schedule[StorageKeys.WAYPOINTS][6:]





