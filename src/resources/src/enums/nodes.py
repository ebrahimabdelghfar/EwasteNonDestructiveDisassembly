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
    # NodesToBeOperated=[FORCE,COLLISION_DETECTION,CENTRAL,VISION,CLAMPING,CHANGE_TOOL,CHECK_MOTOR,APPROACH_AND_ENGAGE,UNSCREW,MILLING]
    NodesToBeOperated=[CHECK_MOTOR]
    NodesToBeOperatedInfo = {CHECK_MOTOR:["checkMotors","checkMotorsNode.py",CHECK_MOTOR]}

if __name__ == "__main__":
    print("Hello, World!")
    print(Nodes.NodesToBeOperated.value)
