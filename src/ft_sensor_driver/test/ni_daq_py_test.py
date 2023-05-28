#!/usr/bin/env python
import nidaqmx
from numpy.core.records import array
from scipy.signal import butter, filtfilt
from collections import deque
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from abb_robot_msgs.srv import TriggerWithResultCode, TriggerWithResultCodeRequest
import time


transformation_matrix = np.array([[-0.023653656180277, 0.013498529819632, 0.21932096679904, -3.49237283000002, -0.260976645567291, 3.76683279822371],
                                  [-0.27509758285346, 4.18175481585886, 0.06683548240138, -
                                      2.0143756008427, 0.161855269400006, -2.18500540342714],
                                  [6.54419998573492, -0.37515063215338, 6.69545217350523, -
                                      0.458698390024187, 6.64864170271365, -0.351508483900239],
                                  [-0.003065032809969, 0.050837610370019, -0.191309874107432, -
                                      0.011682495430063, 0.195310317930836, -0.036035209146095],
                                  [0.217770789204777, -0.012313946101769, -0.114575684516563,
                                      0.049325825236666, -0.106740349421393, -0.039094333983985],
                                  [0.008003163374078, -0.112344720021756, 0.00643395871361, -0.107936745804472, 0.006696875526182, -0.117835960308104]])


mins_to_recalibrate = 50

num_samples = 1000
timeout = 10
queue = deque(maxlen=num_samples)

bias_num_samples = 10000
bias_timeout = 10

sampling_rate = 200      
cutoff_freq = 100


def butter_lowpass_filter(data, cutoff, fs, order=2):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    # Get the filter coefficients 
    b, a = butter(order, normal_cutoff, btype='low', analog=False)
    y = filtfilt(b, a, data, axis=1, padlen=0)
    return y


rospy.init_node("ft_sensor")
pub = rospy.Publisher("/egm/force_controller/ft_sensor_wrench", WrenchStamped, queue_size=1)
stop_egm = rospy.ServiceProxy("/rws/sm_addin/stop_egm", TriggerWithResultCode)
rospy.sleep(1)


with nidaqmx.Task() as task:
    task.ai_channels.add_ai_voltage_chan("Dev1/ai0:5")
    
    data = task.read(number_of_samples_per_channel=bias_num_samples, timeout=bias_timeout)
    bias_arr = np.array(data)
    bias_all = butter_lowpass_filter(bias_arr, cutoff_freq, sampling_rate)
    bias = np.mean(bias_all, axis=1)
    start_time = time.time()
    wrench_msg = WrenchStamped()
    wrench_msg.header.seq = -1
    
    # initialize list
    for i in range(num_samples):
        data = task.read(number_of_samples_per_channel=1)
        queue.append(data)
    
    print queue
    
    try:
        while not rospy.is_shutdown():
            
            data = task.read(number_of_samples_per_channel=1)
            queue.append(data)
            queue_list = list(queue)
            raw_data = np.array(queue_list).reshape(6,num_samples)
            

            # apply low-pass filter
            # filtered_data = butter_lowpass_filter(raw_data, cutoff_freq, sampling_rate)[:, -1]
            filtered_data = butter_lowpass_filter(raw_data, cutoff_freq, sampling_rate)
            filtered_list = filtered_data.reshape(num_samples, 6).tolist()
            queue = deque(filtered_list, maxlen=num_samples)
            # apply mean filter
            # mean_data = np.mean(filtered_data, axis=1)
            
            # remove the bias
            biased_data = filtered_data[:, -1] - bias
            biased_data.reshape(6,)
            
            # biased_data = raw_data
            
            # apply the calibration matrix
            wrench = np.matmul(transformation_matrix, biased_data)
            
            # Publish the force data
            
            wrench_msg.header.frame_id = 'tool0'
            wrench_msg.header.seq += 1
            wrench_msg.header.stamp = rospy.Time.now()
            wrench_msg.wrench.force.x = wrench[0]
            wrench_msg.wrench.force.y = wrench[1]
            wrench_msg.wrench.force.z = wrench[2]
            wrench_msg.wrench.torque.x = wrench[3]
            wrench_msg.wrench.torque.y = wrench[4]
            wrench_msg.wrench.torque.z = wrench[5]
            pub.publish(wrench_msg)
            
            # print the force data
            print (wrench_msg)
            
            
            diff = time.time() - start_time
            # print(diff)
            if ((time.time() - start_time) >= (mins_to_recalibrate * 60.0)):
                rospy.loginfo("Recalibrate")
                stop_egm.wait_for_service()
                stop_msg = TriggerWithResultCodeRequest()
                res = stop_egm(stop_msg)
                print(res)
                raw_input()
                data = task.read(number_of_samples_per_channel=bias_num_samples, timeout=bias_timeout)
                bias_arr = np.array(data)
                bias = np.mean(bias_arr, axis=1)
                start_time = time.time()
                print (start_time)
                
    except rospy.ROSInterruptException:
        pass
