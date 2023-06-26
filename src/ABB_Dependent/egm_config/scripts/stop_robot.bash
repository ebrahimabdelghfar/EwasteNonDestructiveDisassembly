#!/usr/bin/env bash
source /opt/ros/noetic/setup.bash
<<<<<<< HEAD
source ~/Desktop/GP/EwasteNonDestructiveDisassembly/devel/setup.bash
=======
source ~/EwasteNonDestructiveDisassembly/devel/setup.bash
>>>>>>> e4efe4999684bd48e11bd0ba537aa22367802886
rosservice call /rws/sm_addin/stop_egm "{}"
rosservice call /rws/stop_rapid "{}"
rosservice call /rws/set_motors_off "{}" 
