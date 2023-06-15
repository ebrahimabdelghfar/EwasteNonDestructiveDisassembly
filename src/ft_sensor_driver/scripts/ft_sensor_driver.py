#!/usr/bin/env python3
import nidaqmx
from numpy.core.records import array
import rospy
import numpy as np
from geometry_msgs.msg import WrenchStamped, Wrench
from std_msgs.msg import Float64


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

bias_num_samples = 10000
bias_timeout = 10
publish_rate = 800.0 # hz
use_raw_data = False

rospy.init_node("ft_sensor")
wrench_pub = rospy.Publisher("ft_sensor_wrench/wrench/raw", WrenchStamped, queue_size=1)
rospy.sleep(1)

with nidaqmx.Task() as task:
    task.ai_channels.add_ai_voltage_chan("Dev1/ai0:5")
    data = task.read(number_of_samples_per_channel=bias_num_samples, timeout=bias_timeout)
    bias_arr = np.array(data)
    bias_mean = np.mean(bias_arr, axis=1)
    wrench_msg = WrenchStamped()
    rate = rospy.Rate(publish_rate)

    try:
        while not rospy.is_shutdown():
            
            data = task.read(number_of_samples_per_channel=1)
            raw_data = np.array(data).reshape(6,)
            # remove the bias
            if use_raw_data is True:
                biased_data = raw_data
            else:
                biased_data = raw_data - bias_mean
            # 
            # apply the calibration matrix
            wrench = np.matmul(transformation_matrix, biased_data)
            
            # Publish the force data           
            wrench_msg.header.frame_id = 'ft_sensor_link'
            wrench_msg.header.stamp = rospy.Time.now()
            wrench_msg.wrench.force.x = wrench[0]
            wrench_msg.wrench.force.y = wrench[1]
            wrench_msg.wrench.force.z = wrench[2]
            wrench_msg.wrench.torque.x = wrench[3]
            wrench_msg.wrench.torque.y = wrench[4]
            wrench_msg.wrench.torque.z = wrench[5] 
            wrench_pub.publish(wrench_msg)
            # print the force data
            # print (wrench_msg)
            rate.sleep()
                
    except rospy.ROSInterruptException:
        pass
