#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int64
from std_msgs.msg import Bool
from geometry_msgs.msg import Wrench , WrenchStamped

from enums.nodes import Nodes
from enums.topics import Topics

try:
    rospy.init_node('test_1', anonymous=True)
    testPub = rospy.Publisher('UnscrewingStartFlag', Bool, queue_size=1)
    # testPub = rospy.Publisher('startCollisionDetection', Bool, queue_size=1)

    while not rospy.is_shutdown():
        # rospy.loginfo("checking condition")
        testPub.publish(True)

        # rospy.sleep(5)
        
        # testPub.publish(False)

        # rospy.sleep(5)
      
except rospy.ROSInterruptException:
    pass
