#!/usr/bin/env python3
from threading import Thread
from queue import Queue
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float64
from scipy.signal import butter, sosfiltfilt, sosfilt_zi, savgol_filter, detrend, cheby2
import scipy.linalg as linalg
from collections import deque
from ros_numpy import numpify
import matplotlib.pyplot as plt
from copy import deepcopy
from collections import deque
import pandas as pd
from math import sqrt
from filters import cheby2_lowpass_filter


def fft_filter(data, l_freq_thresh=0.01, amp_thresh=0.5, attenuation=1, cut_off_freq=30, sample_rate=250):
    yf = np.fft.fft(data)
    N = len(yf)
    T = 1.0 / sample_rate
    xf = np.fft.fftfreq(N, T)
    # scaled_yf = (abs(np.real(yf))*2.0/len(yf))
    scaled_yf = abs(np.real(yf))

    new_indices = np.argwhere(scaled_yf < amp_thresh)
    # print("new_indicies = ", new_indices)
    # print(scaled_yf)
    print(new_indices.shape[0])
    if new_indices.shape[0] >=1:
        print("min_amp = ", np.min(scaled_yf[new_indices]))
        print("max_amp = ", np.max(scaled_yf[new_indices]))
    zero_indices = np.argwhere(abs(xf) >= cut_off_freq)
    yf[zero_indices] *= 0

    low_freqs_indices = np.argwhere(abs(xf) <= l_freq_thresh)
    non_zero_freq = deepcopy(yf[low_freqs_indices])
    print("low_freq = ", non_zero_freq)
    yf[new_indices] *= attenuation
    # yf[low_freqs_indices] = non_zero_freq
    return np.real(np.fft.ifft(yf))

class FilterTimer():
    def __init__(self, timer_name, ft_rate, cutoff_freq, order, queue_size):
        self.timer_name = timer_name
        self.raw_data = 0
        self.filtered_data = 0
        rospy.Timer(rospy.Duration((1.0/ft_rate)), self.timer)
        self.queue_size = queue_size
        # self.q = deque(maxlen=self.queue_size)
        self.q = []
        normal_cutoff = cutoff_freq / ft_rate
        self.sos = butter(order, normal_cutoff, analog=False, output='sos')
        # self.zi = None
        
    def timer(self, event):
        self.q.append(self.raw_data)
        if len(self.q) == self.queue_size:
            data = np.array(self.q)
            data = sosfiltfilt(self.sos, data)
            data = data - detrend(data, type='constant')
            self.filtered_data = np.mean(data)
            self.q = []
            # data_list_filt.append(data[-1])
            # time_list_filt.append(rospy.Time.now().to_sec())
    
    # def timer(self, event):
    #     self.q.append(self.raw_data)
    #     if len(self.q) == self.queue_size:
    #         data = np.array(self.q)
    #         data = fft_filter(data, l_freq_thresh=0.1, amp_thresh=500, attenuation=0.0, cut_off_freq=20, sample_rate=250)
    #         self.filtered_data = data[-1]
            # data_list_filt.append(data[-1])
            # time_list_filt.append(rospy.Time.now().to_sec()) 
            

        
    def set_raw_data(self, data):
        self.raw_data = data

    def get_filtered_data(self):
        data = self.filtered_data
        return data


class Node():
    def __init__(self, ft_rate=800.0, cutoff_freq=5, order=2, queue_size=40):
        self.timers = []
        filter_rate = ft_rate / queue_size
        # filter_rate = ft_rate
        for i in range(6):
            self.timers.append(FilterTimer(
                str(i), ft_rate=ft_rate, cutoff_freq=cutoff_freq, order=order, queue_size=queue_size))

        rospy.Subscriber("ft_sensor_wrench/wrench/raw",
                         WrenchStamped, self.Subscriber)
        self.filtered_pub = rospy.Publisher(
            "ft_sensor_wrench/wrench/filtered", WrenchStamped, queue_size=1)
        rospy.Timer(rospy.Duration(1.0/filter_rate), self.PublishTimer)

    def Subscriber(self, msg):
        self.timers[0].set_raw_data(msg.wrench.force.x)
        self.timers[1].set_raw_data(msg.wrench.force.y)
        self.timers[2].set_raw_data(msg.wrench.force.z)
        self.timers[3].set_raw_data(msg.wrench.torque.x)
        self.timers[4].set_raw_data(msg.wrench.torque.y)
        self.timers[5].set_raw_data(msg.wrench.torque.z)

    def PublishTimer(self, event):
        msg = WrenchStamped()
        msg.wrench.force.x = self.timers[0].get_filtered_data()
        msg.wrench.force.y = self.timers[1].get_filtered_data()
        msg.wrench.force.z = self.timers[2].get_filtered_data()
        msg.wrench.torque.x = self.timers[3].get_filtered_data()
        msg.wrench.torque.y = self.timers[4].get_filtered_data()
        msg.wrench.torque.z = self.timers[5].get_filtered_data()
        msg.header.stamp = rospy.Time.now()
        self.filtered_pub.publish(msg)

def main():
    rospy.init_node("threaded_lp_filter")
    # Node(ft_rate=250.0, cutoff_freq=10.0, order=2, queue_size=80)
    Node(ft_rate=800.0, cutoff_freq=10.0, order=2, queue_size=80)
    rospy.spin()


if __name__ == '__main__':
    main()
