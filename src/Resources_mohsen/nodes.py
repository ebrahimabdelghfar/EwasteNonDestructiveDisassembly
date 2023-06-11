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


if __name__ == "__main__":
    print("Hello, World!")
    print(Nodes.CENTRAL.value)
