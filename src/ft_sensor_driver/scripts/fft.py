#!/usr/bin/env python
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from std_msgs.msg import Float64
import matplotlib.pyplot as plt
from numpy.fft import fft, fftfreq

fx_raw_list = []
fx_filtered_list = []

def raw_cb(msg):
    # get the forces
    fx = msg.wrench.force.x
    fy = msg.wrench.force.y
    fz = msg.wrench.force.z
    
    tx = msg.wrench.torque.x
    ty = msg.wrench.torque.y
    tz = msg.wrench.torque.z
    
    fx_raw_list.append(fx)

def filtered_cb(msg):
    # get the forces
    fx = msg.wrench.force.x
    fy = msg.wrench.force.y
    fz = msg.wrench.force.z
    
    tx = msg.wrench.torque.x
    ty = msg.wrench.torque.y
    tz = msg.wrench.torque.z
    
    fx_filtered_list.append(fx)


rospy.init_node("res_pub")
rospy.Subscriber("ft_sensor_wrench/wrench/raw", WrenchStamped, raw_cb)
rospy.Subscriber("ft_sensor_wrench/wrench/filtered", WrenchStamped, filtered_cb)
rospy.spin()

# plot raw data
yf_raw = fft(fx_raw_list)
N_raw = len(fx_raw_list)
T_raw = 1.0 / 250.0
xf_raw = fftfreq(N_raw, T_raw)[:N_raw//2]
plt.plot(xf_raw, 2.0/N_raw * np.abs(yf_raw[0:N_raw//2]), c='r', label='raw')

# plot filtered data
yf_filt = fft(fx_filtered_list)
N_filt = len(fx_filtered_list)
T_filt = 1.0 / 250.0
xf_filt = fftfreq(N_filt, T_filt)[:N_filt//2]
plt.plot(xf_filt, 2.0/N_filt * np.abs(yf_filt[0:N_filt//2]), c='g', label='filtered')
plt.legend(loc='upper right')
plt.grid()
plt.show()
