
from enum import Enum, auto, unique

@unique
class Response(Enum):
    FAILED = auto()
    IN_PROGRESS = auto()
    SUCCESSFULL = auto()

