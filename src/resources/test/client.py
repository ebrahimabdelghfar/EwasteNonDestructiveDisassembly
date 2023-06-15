import rospy
from rospy_tutorials.srv import AddTwoInts
x= 5  
y=6
rospy.init_node("s")
rospy.wait_for_service('add_two_ints')
add_two_ints = rospy.ServiceProxy('add_two_ints', AddTwoInts,persistent=True)
try:
  for i in range (5):
    resp1 = add_two_ints(i, i+i)
    print("Sum of {} and {} is {}".format(i, i+i, resp1.sum))
except rospy.ServiceException as exc:
  print("Service did not process request: " + str(exc))