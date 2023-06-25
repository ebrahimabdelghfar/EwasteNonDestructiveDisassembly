#!/usr/bin/env bash
source /opt/ros/noetic/setup.bash
<<<<<<< HEAD
source ~/Desktop/GP/EwasteNonDestructiveDisassembly/devel/setup.bash
=======
source ~/EwasteNonDestructiveDisassembly/devel/setup.bash
>>>>>>> e4efe4999684bd48e11bd0ba537aa22367802886
rosservice call /rws/set_motors_on "{}" 
rosservice call /rws/pp_to_main "{}"
rosservice call /rws/start_rapid "{}"
rosrun egm_config egm_config.py
rosservice call /rws/sm_addin/start_egm_joint "{}" 
