# EwasteNonDestructiveDisassembly
<p align="center">
<img src="https://img.shields.io/badge/ros-%230A0FF9.svg?style=for-the-badge&logo=ros&logoColor=white" width="75" />
<img src="https://img.shields.io/badge/PyTorch-%23EE4C2C.svg?style=for-the-badge&logo=PyTorch&logoColor=white" />
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white" /> 
<img src="https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" /> 
<img src="https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/fbd98431-8832-479f-a85d-9c57664589c8" width="140"/> 

</p>

# Description

The "E-waste Non-Destructive Disassembly Robot" project is a cutting-edge endeavor aimed at addressing the pressing issue of electronic waste (e-waste) through an innovative robotic system. The project focuses on developing a robot capable of disassembling electronic devices without causing damage, facilitating efficient recycling and reuse of valuable components.

Key Features:

* Utilizes the ABB IRB120 robotic manipulator as the core hardware platform.
* Implements a pure mechanical tool-changing mechanism for the seamless switching of specialized tools.
* Utilizes the Intel RealSense D435 camera and a custom vision algorithm for precise component localization.
* Develops algorithms for approaching, engaging, and unfastening screws with high accuracy.
* Incorporates a central node for supervision, coordination, and fault tolerance.
* Comprehensive documentation is provided in a detailed thesis and accompanying video.

The project aims to contribute to sustainable e-waste management by offering an environmentally friendly and efficient solution for disassembling electronic devices. By enabling the safe extraction of valuable components, it promotes recycling and reduces the environmental impact of e-waste.

# Feature
* Pure Mechanical Tool changing algorithm
* Detect screws and locate their position precisely.
* Tool-changing algorithm that has 100% success in getting and returning tools.
* Central node that coordinates and determines the order of operation.
* Successfully approach and engage with screws.
* Unscrewing algorithm that can predict precisely when the screw is completely out.
# Connection Diagram 
<p align="center">
 <img src="https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/9aa98e2a-7c94-41ed-ad66-d2009ca91bca" /> 

</p>

# Project Cycle
<p align="center">
 <img src="https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/fdc5c255-99f7-43f3-8536-2a72fc1e7f8f" />  
</p>



# Requirements
- Operating system
   -  Ubuntu 20.04 Focal Fossal
-  Framework
   - Ros1 Noetic
   - Python 3.8 or above
   - Moveit 1
   - PyTorch
# How To
## Install ROS dependencies 
```
sudo apt-get install ros-noetic-moveit*
sudo apt-get install ros-noetic-abb*
sudo apt-get install ros-noetic-industrial*
sudo apt-get install ros-noetic-trac-ik-kinematics-plugin
sudo apt-get install ros-noetic-joint*
sudo apt-get install ros-noetic-control*
```
## Build the workspace
```
cd ~/EwasteNonDestructiveDisassembly
rosdep install --from-paths src --ignore-src --rosdistro=noetic -y
catkin build
```
🚨 This step must be done in both master and slave PC
## Run the system
### In the Master PC
#### Terminal 1
```
roslaunch ft_sensor_driver force_filtered.launch
```
#### Terminal 2
```
ls /dev/tty* #select the tty that contain the ACM
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=115200
```
### In the slave PC
#### Terminal 1
```
roscore
```
#### Terminal 2
```
#adjust the starter file to see which file should start first
rosrun CentralNode starterSystem.py
```
# Integration
![GP drawio](https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/19acd6ee-6b94-4af5-b320-a5827037b2bb)

# Full video

https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/bd3405e8-a57e-409f-bd26-478e25d90be8

# Resources 

<img align="center" src="https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly/assets/81301684/9f4551af-32a1-4df1-8719-abc87daf2bc5" alt="https://www.linkedin.com/in/ebrahim-abdelghafar/" width="150"/> :  [All Project Resources](https://engasuedu-my.sharepoint.com/:f:/g/personal/18p2187_eng_asu_edu_eg/EhhmfK2uarxNuSgLD824AL8BBW_xkY51RF4FKOA_jGJPSg?e=DFBrxT )
