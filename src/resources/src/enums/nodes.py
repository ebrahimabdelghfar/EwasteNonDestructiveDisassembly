from enum import Enum

# Enum that contains the information about the nodes
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
    ForceFiltered="ForceFiltered"
    HardwareInterface="Arduino1"
    #list that contains all the nodes that always should be running
    NodesToBeOperated=[FORCE,
                       ForceFiltered,
                       COLLISION_DETECTION,
                       CENTRAL,
                       VISION,
                       CLAMPING,
                       CHANGE_TOOL,
                       CHECK_MOTOR,
                       APPROACH_AND_ENGAGE,
                       UNSCREW,
                       MILLING]
    #dictionary that contains the information about the nodes [pkgname , executable , node name]
    NodesToBeOperatedInfo = {CHECK_MOTOR : ["checkMotors","checkMotorsNode.py" ,CHECK_MOTOR],
                             HeartBeat : ["CentralNode" , "heartBeat.py" , HeartBeat],
                             CHANGE_TOOL : ["control","ChangeToolNode.py",CHANGE_TOOL],
                             CENTRAL : ["CentralNode","main.py",CENTRAL],
                             FORCE : ["ft_sensor_driver","ft_sensor_driver.py",FORCE],
                             ForceFiltered : ["ft_sensor_driver","weighted_avg_filter.py",ForceFiltered],
                             UNSCREW :["control","unscrewing.py",UNSCREW],
                             APPROACH_AND_ENGAGE : ["control","ApprochAndEngaging.py",APPROACH_AND_ENGAGE],
                             MILLING : ["control","millingNode.py",MILLING],
                             CLAMPING: ["HardwareLevel","HardwareBridge.py",CLAMPING],
                             HardwareInterface : ["rosserial_python","serial_node.py",HardwareInterface,"_port:=/dev/ttyACM0 _baud:=115200"]
                            }
    StartSequance=[CHECK_MOTOR,
                   HardwareInterface,
                   #CLAMPING,
                   #CHANGE_TOOL,
                   #APPROACH_AND_ENGAGE,
                   #UNSCREW,
                   #MILLING,
                   #CENTRAL,
                   #HeartBeat
                   ]
