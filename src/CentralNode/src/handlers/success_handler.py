from src.storage.db import RobotDatabase
from operations import OPERATIONS
import sys
from resources.src.enums.nodes import Nodes
from resources.src.enums.tools import Tools
import src.storage.storage_keys as StorageKeys
#from enums.nodes import Nodes
sys.path.append("./")



def handleSuccess(currentNode, nodeResponse):
    unscrewIndex = OPERATIONS.index(Nodes.APPROACH_AND_ENGAGE)
    visionIndex = OPERATIONS.index(Nodes.VISION)
    returnScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
    getMillingIndex = returnScrewDriverIndex + 1
    returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, getMillingIndex + 1)
    getScrewDriverIndex = returnMillingIndex + 1

    if currentNode == unscrewIndex:
            RobotDatabase().addToDB(StorageKeys.CANT_UNSCREW_LIST, nodeResponse.extraData)
    elif currentNode == visionIndex:
            RobotDatabase().addToDB(StorageKeys.LIST_OF_SCREWS, nodeResponse.extraData)
    elif currentNode in [returnScrewDriverIndex, returnMillingIndex]:
           RobotDatabase().addToDB(StorageKeys.TOOL_IN_HAND, Tools.NO_TOOL.value)
    elif currentNode == getMillingIndex:
           RobotDatabase().addToDB(StorageKeys.TOOL_IN_HAND, Tools.MILLING.value)
    elif currentNode == getScrewDriverIndex:
           RobotDatabase().addToDB(StorageKeys.TOOL_IN_HAND, Tools.SCREW_DRIVER.value)



