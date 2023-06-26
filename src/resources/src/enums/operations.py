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
    getScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL)
    returnScrewDriverIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, getScrewDriverIndex)
    getMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, returnScrewDriverIndex)
    returnMillingIndex = OPERATIONS.index(Nodes.CHANGE_TOOL, getMillingIndex)

    return getScrewDriverIndex, returnScrewDriverIndex, getMillingIndex, returnMillingIndex


