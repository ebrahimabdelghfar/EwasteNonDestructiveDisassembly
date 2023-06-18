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