from enums.nodes import Nodes
#from enums.nodes import Nodes
OPERATIONS = [
    Nodes.CLAMPING,
    Nodes.VISION,
    Nodes.APPROACH_AND_ENGAGE, #Unscrew
    Nodes.CHANGE_TOOL,  #Return tool
    Nodes.CHANGE_TOOL,  #Get milling
    Nodes.APPROACH_AND_ENGAGE, #Milling
    Nodes.CHANGE_TOOL, #Return milling
    Nodes.CHANGE_TOOL, #Get screw
    Nodes.CLAMPING, #Unclamp
]

def getChangeToolIndices():
    returnScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
    getMillingIndex = returnScrewDriverIndex + 1
    returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, getMillingIndex + 1)
    getScrewDriverIndex = returnMillingIndex + 1

    return getScrewDriverIndex, returnScrewDriverIndex, getMillingIndex, returnMillingIndex


