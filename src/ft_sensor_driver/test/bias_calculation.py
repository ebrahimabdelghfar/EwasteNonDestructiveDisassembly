import nidaqmx
import numpy as np

with nidaqmx.Task() as task:
    # task.ai_channels.add_ai_voltage_chan("DAQmx")
    # task.ai_channels.add_ai_temp_built_in_sensor_chan()
    task.ai_channels.add_ai_voltage_chan("Dev1/ai0:5")
 
    data = task.read(number_of_samples_per_channel=1000, timeout=10)
    # bias_samples = np.array(data)
    # bias_mean = np.mean(bias_samples, axis=1)
    print (data)