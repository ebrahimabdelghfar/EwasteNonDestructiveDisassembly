import rospy
from rospy_tutorials.srv import AddTwoIntsRequest, AddTwoIntsResponse , AddTwoInts
def add_two_ints(req: AddTwoIntsRequest):
    test=AddTwoIntsResponse()
    test.sum = 7 
    return test


def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    rospy.Service('add_two_ints',AddTwoInts, add_two_ints)

add_two_ints_server()

while not rospy.is_shutdown():
    rospy.sleep(0.1)