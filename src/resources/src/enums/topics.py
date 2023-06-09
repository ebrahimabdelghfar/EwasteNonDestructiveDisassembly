from enum import Enum

class Topics(Enum):
    NODE_TO_OPERATE = "NODE_TO_OPERATE"
    NODE_SUCCESS = "NODE_SUCCESS"
    SCREW_LIST="ListOfScrews"
    START_COLLISION_DETECTED = "START_COLLISION_DETECTED"
    COLLISION_DETECTED = "COLLISION_DETECTED"
    UNSCREW_START_FLAG = "UNSCREW_START_FLAG"
    UNSCREW_DONE = "UNSCREW_DONE"
    START_MILLING = "START_MILLING"
    FINISHED_MILLING = "FINISHED_MILLING"
    ScrewDriverMOTOR_COMMAND = "MOTOR_COMMAND"
    MillingMOTOR_COMMAND = "Milling_COMMAND"
    ForceSensorWrench = "ft_sensor_wrench/wrench/raw"
    ForceSensorWrenchWeightedFilter = "ft_sensor_wrench/wrench/weighted_filtered"
