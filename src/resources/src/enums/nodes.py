from enum import Enum


class Nodes(Enum):
    FORCE="FORCE"
    COLLISION_DETECTION = "COLLISION_DETECTION"
    CENTRAL = "CENTRAL"
    VISION="VISION"
    CLAMPING = "CLAMPING"
    CHANGE_TOOL = "CHANGE_TOOL"
    CHECK_MOTOR = "CHECK_MOTOR"
    APPROACH_AND_ENGAGE = "APPROACH_ANG_ENGAGE"
    UNSCREW = "UNSCREW_NODE"
    MILLING = "MILLING"
    HeartBeat = "HeartBeat"
    #list that contains all the nodes that always should be running
    NodesToBeOperated=[FORCE,COLLISION_DETECTION,CENTRAL,VISION,CLAMPING,CHANGE_TOOL,CHECK_MOTOR,APPROACH_AND_ENGAGE,UNSCREW,MILLING]
    #dictionary that contains the information about the nodes [pkgname , executable , node name]
    NodesToBeOperatedInfo = {CHECK_MOTOR:[ "checkMotors" , "checkMotorsNode.py" ,CHECK_MOTOR ],
                             HeartBeat: ["CentralNode" , "heartBeat.py" , HeartBeat ],
                             CHANGE_TOOL:["control","ChangeToolNode.py",CHANGE_TOOL],
                            }
    StartSequance=[CENTRAL,
                   CHECK_MOTOR,
                   VISION,
                   CLAMPING,
                   CHANGE_TOOL,
                   APPROACH_AND_ENGAGE,
                   UNSCREW,
                   MILLING,
                   COLLISION_DETECTION,
                   HeartBeat]
