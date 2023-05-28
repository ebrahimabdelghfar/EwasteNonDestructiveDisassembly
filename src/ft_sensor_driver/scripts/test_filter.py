#!/usr/bin/env python3
from filters import *
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from scipy.signal import butter, sosfilt, sosfilt_zi, savgol_filter, detrend
from collections import deque
from ros_numpy import numpify
import matplotlib.pyplot as plt
from collections import deque
import matplotlib.pyplot as plt
import scipy.linalg as linalg
import rosbag


def wrench_sub(wrench_msg):
    fx = wrench_msg.wrench.force.x
    time_list_raw.append(wrench_msg.header.stamp.to_sec())
    data_list_raw.append(fx)
   
   
rospy.init_node("ft_lpr")
read_from_bag = True
raw_topic = '/ft_sensor_wrench/wrench/raw'
data_list_raw = []
time_list_raw = []
data_list_filt = []
time_list_filt = []

if not read_from_bag:
    rospy.Subscriber(raw_topic, WrenchStamped, wrench_sub)
    rospy.spin()

else:
    bag = rosbag.Bag('/home/zaferpc/abb_ws/src/ft_sensor_driver/bags/ft_filtered_raw.bag')
    for topic, msg, t in bag.read_messages(topics=[raw_topic]):
        if topic == raw_topic:
            pass
            data_list_raw.append(msg.wrench.force.x)
bag.close()
data_raw = np.array(data_list_raw)
data_size = data_raw.shape[0]
queue_size = 80
data_queue = []
window = 50
down_step = 1
zi = None
data_list_down_sampled = []
time_list_down_sampled = []
for i in range(0, data_size):
    data_list_down_sampled.append(data_raw[i])

'''
start filtering
'''
rospy.loginfo("start filtering")

"""
design the filter
"""
cutoff = 10
sample_rate = 800.0
actual_sample_rate = sample_rate / down_step
normal_cutoff = cutoff / actual_sample_rate
sos = butter(2, normal_cutoff, analog=False, output='sos')

for i in range(len(data_list_down_sampled)):
    data_queue.append(data_list_down_sampled[i])
    time_list_down_sampled.append(rospy.Time.now().to_sec())
    if len(data_queue) == queue_size:
        data = np.array(data_queue)
        data = sosfilt(sos, data)
        data = data - detrend(data, type='constant')
        data_list_filt.append(np.mean(data))
        time_list_filt.append(rospy.Time.now().to_sec())
    #     rospy.loginfo("in the looactual_freq

data_down_sampled = np.array(data_list_down_sampled)
time_down_sampled = np.array(time_list_down_sampled)
start_time = time_down_sampled[0]
time_down_sampled = time_down_sampled - start_time
time_filt = np.array(time_list_filt)
time_filt = time_filt - start_time
data_filt = np.array(data_list_filt)

plt.plot(time_down_sampled, data_down_sampled, c='r')
plt.plot(time_filt, data_filt, c='g', linewidth=4)
rospy.loginfo("reconstruction ended")
plt.ylim((-20, 20))
plt.show()

xf_down, yf_down = fft_func(data_down_sampled, actual_sample_rate)
xf_filt, yf_filt = fft_func(data_filt, actual_sample_rate)
plt.plot(xf_down, yf_down, c='r')
plt.plot(xf_filt, yf_filt, c='g', linewidth=4)
plt.show()
