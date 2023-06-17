import rospy
from CentralNode.srv import *
from enums.services import Services

def reshapeList(ListOfscrews)->list:
    #reshaping the list to 2D of shape (nx6) list array
    ListOfscrews = [ListOfscrews[i:i+6] for i in range(0, len(ListOfscrews), 6)]



rospy.init_node("test")
rospy.wait_for_service(Services.SCHEDULAR.value)
test=rospy.ServiceProxy(Services.SCHEDULAR.value,Schedular)
resp:SchedularResponse=test(SchedularRequest())
reshapeList(resp.waypoints)
