#!/usr/bin/env python3
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from enums.topics import Topics

import matplotlib.pyplot as plt
import math

from enums.nodes import Nodes
from enums.topics import Topics
weightMultplier = 0.01

FxFiltered = 0
FyFiltered = 0
FzFiltered = 0
TxFiltered = 0
TyFiltered = 0
TzFiltered = 0



def raw_wrench_sub(wrench_msg):

    global weightMultplier, FxFiltered, FyFiltered, FzFiltered, TxFiltered, TyFiltered, TzFiltered
    # Update sensor readings
    Fx = wrench_msg.wrench.force.x
    Fy = wrench_msg.wrench.force.y
    Fz = wrench_msg.wrench.force.z
    Tx = wrench_msg.wrench.torque.x
    Ty = wrench_msg.wrench.torque.y
    Tz = wrench_msg.wrench.torque.z
    FxFiltered = weightMultplier * Fx + (1-weightMultplier) * FxFiltered
    FyFiltered = weightMultplier * Fy + (1-weightMultplier) * FyFiltered
    FzFiltered = weightMultplier * Fz + (1-weightMultplier) * FzFiltered
    TxFiltered = weightMultplier * Tx + (1-weightMultplier) * TxFiltered
    TyFiltered = weightMultplier * Ty + (1-weightMultplier) * TyFiltered
    TzFiltered = weightMultplier * Tz + (1-weightMultplier) * TzFiltered
    
    wrench_msg.wrench.force.x = FxFiltered
    wrench_msg.wrench.force.y = FyFiltered
    wrench_msg.wrench.force.z = FzFiltered
    wrench_msg.wrench.torque.x = TxFiltered
    wrench_msg.wrench.torque.y = TyFiltered
    wrench_msg.wrench.torque.z = TzFiltered
     
    weighted_filtered_pub.publish(wrench_msg)


rospy.init_node(Nodes.ForceFiltered.value)
rospy.Subscriber(Topics.ForceSensorWrench.value, WrenchStamped, raw_wrench_sub)
weighted_filtered_pub = rospy.Publisher(Topics.ForceSensorWrenchWeightedFilter.value, WrenchStamped, queue_size=1)
rospy.spin()
