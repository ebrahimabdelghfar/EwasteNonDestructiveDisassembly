#!/usr/bin/env python
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from scipy.signal import butter, filtfilt
from collections import deque
from ros_numpy import numpify
import matplotlib.pyplot as plt


sampling_rate = 500
cutoff_freq = 10
num_samples = 1000
queue = deque(maxlen=num_samples)


def raw_wrench_sub(wrench_msg):

    pass


def raw_res_sub(res_msg):
    # print res_msg
    global queue
    queue.append(res_msg.data)
    raw_arr = np.array(list(queue))
    filtered_arr = butter_lowpass_filter(raw_arr, cutoff_freq, sampling_rate)
    # print filtered_arr
    # queue.clear()
    # queue = deque(filtered_arr.tolist())
    filtered_msg = Float64(data=filtered_arr[-1])
    filtered_res_pub.publish(filtered_msg)
    plot_msg = PointStamped()
    plot_msg.header.stamp = rospy.Time.now()
    plot_msg.point.x = res_msg.data
    plot_msg.point.y = filtered_arr[-1]
    plot_pub.publish(plot_msg)

def butter_lowpass_filter(data, cutoff, fs, order=2):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients
    b, a = butter(order, normal_cutoff, btype='low', analog=False)
    y = filtfilt(b, a, data, axis=0, padlen=0)
    return y


rospy.init_node("ft_lpr")
rospy.Subscriber("ft_sensor_wrench/wrench/raw", WrenchStamped, raw_wrench_sub)
filtered_wrench_pub = rospy.Publisher("ft_sensor_wrench/wrench/filtered", Float64, queue_size=1)
rospy.Subscriber("ft_sensor_wrench/resultant/raw", Float64, raw_res_sub)
filtered_res_pub = rospy.Publisher("ft_sensor_wrench/resultant/filtered", Float64, queue_size=1)
plot_pub = rospy.Publisher("plot", PointStamped, queue_size=1)

rospy.spin()
