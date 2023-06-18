from CentralNode.srv import *
from enums.services import Services
import rospy
rospy.init_node("testserver")
def callback(req:SchedularRequest):
    test=SchedularResponse()
    test.waypoint_types=[2,3,4,5,6,7,8,8,5,6,7,8]
    test.waypoints=[2,3,4,5,6,7,8,8,5,6,7,8]
    return test

server=rospy.Service(Services.SCHEDULAR.value,Schedular,callback)
rospy.spin()