#!/usr/bin/env bash
source /opt/ros/noetic/setup.bash
source ~/EwasteNonDestructiveDisassembly/devel/setup.bash
rosservice call /rws/set_motors_on "{}" 
rosservice call /rws/pp_to_main "{}"
rosservice call /rws/start_rapid "{}"
rosrun egm_config egm_config.py
rosservice call /rws/sm_addin/start_egm_joint "{}" 
rosrun egm_config egm_config_rt.py
