#!/usr/bin/env python3
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from scipy.signal import butter, sosfilt, sosfilt_zi
from collections import deque
from ros_numpy import numpify
import matplotlib.pyplot as plt


sampling_rate = 250
cutoff_freq = 5
zi_fx = None
zi_fy = None
zi_fz = None
zi_tx = None
zi_ty = None
zi_tz = None
zi_res = None
filter_torques = False

def raw_wrench_sub(wrench_msg):
    global cutoff_freq, sampling_rate, zi_fx, zi_fy, zi_fz, zi_tx, zi_ty, zi_tz
    filtered_msg = WrenchStamped()
    filtered_msg.header.frame_id = wrench_msg.header.frame_id

    # apply filters in forces
    filtered_fx, zi_fx = butter_lowpass_filter([wrench_msg.wrench.force.x], cutoff_freq, sampling_rate, zi_fx)
    filtered_fy, zi_fy = butter_lowpass_filter([wrench_msg.wrench.force.y], cutoff_freq, sampling_rate, zi_fy)
    filtered_fz, zi_fz = butter_lowpass_filter([wrench_msg.wrench.force.z], cutoff_freq, sampling_rate, zi_fz)
    filtered_msg.wrench.force.x = filtered_fx[0]
    filtered_msg.wrench.force.y = filtered_fy[0]
    filtered_msg.wrench.force.z = filtered_fz[0]
    
    if filter_torques:
        filtered_tx, zi_tx = butter_lowpass_filter([wrench_msg.wrench.torque.x], cutoff_freq, sampling_rate, zi_tx)
        filtered_ty, zi_ty = butter_lowpass_filter([wrench_msg.wrench.torque.y], cutoff_freq, sampling_rate, zi_ty)
        filtered_tz, zi_tz = butter_lowpass_filter([wrench_msg.wrench.torque.z], cutoff_freq, sampling_rate, zi_tz)
    else:
        filtered_msg.wrench.torque.x = wrench_msg.wrench.torque.x
        filtered_msg.wrench.torque.y = wrench_msg.wrench.torque.y
        filtered_msg.wrench.torque.z = wrench_msg.wrench.torque.z     

    # print(filtered_msg)
    filtered_msg.header.stamp = rospy.Time.now()
    filtered_pub.publish(filtered_msg)
   
def butter_lowpass_filter(data, cutoff, fs, z, order=2):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    sos = butter(order, normal_cutoff, btype='low', analog=False, output='sos')
    if z is None:
        z = sosfilt_zi(sos)
    y, zf = sosfilt(sos, data, zi=z)
    return y, zf

rospy.init_node("ft_lpr")
rospy.Subscriber("ft_sensor_wrench/wrench/raw", WrenchStamped, raw_wrench_sub)
filtered_pub = rospy.Publisher("ft_sensor_wrench/wrench/filtered", WrenchStamped, queue_size=1)
rospy.spin()
