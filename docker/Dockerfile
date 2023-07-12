FROM nvidia/cudagl:11.1.1-base-ubuntu20.04 
# Minimal setup
RUN apt-get update && apt-get install -y locales lsb-release
ARG DEBIAN_FRONTEND=noninteractive
RUN dpkg-reconfigure locales
 
# Install ROS Noetic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN apt-get update\
 && apt-get install -y --no-install-recommends ros-noetic-desktop-full
RUN apt-get install -y --no-install-recommends python3-rosdep
RUN rosdep init \
 && rosdep fix-permissions \
 && rosdep update
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
RUN apt-get -y upgrade
RUN apt-get install -y --no-install-recommends python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
RUN apt-get install python3-pip -y
#install python packages 
RUN pip install torch
RUN pip install torchvision
RUN pip install opencv-python
RUN pip install seaborn
RUN pip install matplotlib
RUN pip install numpy
RUN pip install open3d 
#install cuda
RUN apt-get -y install cuda   
#install git
RUN apt-get -y install git
#install ros packages depedencies
RUN apt-get install -y ros-noetic-moveit*
RUN apt-get install -y ros-noetic-abb*
RUN apt-get install -y ros-noetic-industrial*
RUN apt-get install -y ros-noetic-trac-ik-kinematics-plugin
RUN apt-get install -y ros-noetic-joint*
RUN apt-get install -y ros-noetic-control*
# install the system repo
RUN git clone https://github.com/ebrahimabdelghfar/EwasteNonDestructiveDisassembly.git
#make the workspace 
RUN cd EwasteNonDestructiveDisassembly \
&& rm -r .catkin_tools \ 
&& rm -r .vscode \
&& rosdep install --from-paths src --ignore-src -r -y \
&& catkin build
RUN echo "source /EwasteNonDestructiveDisassembly/devel/setup.bash" >> ~/.bashrc