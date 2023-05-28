#!/usr/bin/env python3
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from std_msgs.msg import Float64
from math import fabs

def res_cb(msg):
    # get the forces
    fx = msg.wrench.force.x
    fy = msg.wrench.force.y
    fz = msg.wrench.force.z
    
    tx = msg.wrench.torque.x
    ty = msg.wrench.torque.y
    tz = msg.wrench.torque.z
    
    # calculate the resultants
    f_res_xy = np.sqrt(fx**2 + fy**2)
    f_res_yz = np.sqrt(fy**2 + fz**2)
    f_res_xz = np.sqrt(fx**2 + fz**2)
    
    t_res_xy = np.sqrt(tx**2 + ty**2)
    t_res_yz = np.sqrt(ty**2 + tz**2)
    t_res_xz = np.sqrt(tx**2 + tz**2)
    
    # resultant messages
    f_res_xy_msg = Float64(data=f_res_xy)
    f_res_yz_msg = Float64(data=f_res_yz)
    f_res_xz_msg = Float64(data=f_res_xz)
    
    t_res_xy_msg = Float64(data=t_res_xy)
    t_res_yz_msg = Float64(data=t_res_yz)
    t_res_xz_msg = Float64(data=t_res_xz)


    # publish resultant messages
    f_res_xy_pub.publish(f_res_xy_msg)
    f_res_yz_pub.publish(f_res_yz_msg)
    f_res_xz_pub.publish(f_res_xz_msg)
    
    t_res_xy_pub.publish(t_res_xy_msg)
    t_res_yz_pub.publish(t_res_yz_msg)
    t_res_xz_pub.publish(t_res_xz_msg)
    
    if fabs(fy) < 2.0:
        arm_depth_msg = Float64(data=0.3)
    else:
        arm_depth_msg = Float64(data=(fabs(tz)/(fabs(fy)+1e-3)))
    arm_depth_pub.publish(arm_depth_msg)

rospy.init_node("res_pub")
rospy.Subscriber("ft_sensor_wrench/wrench/filtered", WrenchStamped, res_cb)
f_res_xy_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/xy", Float64, queue_size=1)
f_res_yz_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/yz", Float64, queue_size=1)
f_res_xz_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/xz", Float64, queue_size=1)
t_res_xy_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/torque/xy", Float64, queue_size=1)
t_res_yz_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/torque/yz", Float64, queue_size=1)
t_res_xz_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered/torque/xz", Float64, queue_size=1)
arm_depth_pub = rospy.Publisher("ft_sensor_wrench/arm_depth", Float64, queue_size=1)
rospy.spin()
