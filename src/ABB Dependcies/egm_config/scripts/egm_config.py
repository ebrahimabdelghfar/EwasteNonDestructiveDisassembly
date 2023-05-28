#!/usr/bin/env python3
import rospy
from abb_rapid_sm_addin_msgs.srv import SetEGMSettings, SetEGMSettingsRequest, SetEGMSettingsResponse

rospy.init_node("egm_config")
rospy.sleep(1)
egm_client = rospy.ServiceProxy("/rws/sm_addin/set_egm_settings", SetEGMSettings)

egm = SetEGMSettingsRequest()
egm.task = 'T_ROB1'
egm.settings.activate.tool.robhold = True
egm.settings.activate.tool.tframe.trans.x = 0
egm.settings.activate.tool.tframe.trans.y = 0
egm.settings.activate.tool.tframe.trans.z = 0
egm.settings.activate.tool.tframe.rot.q1 = 1
egm.settings.activate.tool.tframe.rot.q2 = 0
egm.settings.activate.tool.tframe.rot.q3 = 0
egm.settings.activate.tool.tframe.rot.q4 = 0
egm.settings.activate.tool.tload.mass = 0.001
egm.settings.activate.tool.tload.cog.x = 0
egm.settings.activate.tool.tload.cog.y = 0
egm.settings.activate.tool.tload.cog.z = 0.001
egm.settings.activate.tool.tload.aom.q1 = 1
egm.settings.activate.tool.tload.aom.q2 = 0
egm.settings.activate.tool.tload.aom.q3 = 0
egm.settings.activate.tool.tload.aom.q4 = 0
egm.settings.activate.tool.tload.ix = 0
egm.settings.activate.tool.tload.iy = 0
egm.settings.activate.tool.tload.iz = 0

egm.settings.activate.wobj.robhold = False
egm.settings.activate.wobj.ufprog = True
egm.settings.activate.wobj.ufmec = ""
egm.settings.activate.wobj.uframe.trans.x = 0
egm.settings.activate.wobj.uframe.trans.y = 0
egm.settings.activate.wobj.uframe.trans.z = 0
egm.settings.activate.wobj.uframe.rot.q1 = 1
egm.settings.activate.wobj.uframe.rot.q2 = 0
egm.settings.activate.wobj.uframe.rot.q3 = 0
egm.settings.activate.wobj.uframe.rot.q4 = 0
egm.settings.activate.wobj.oframe.trans.x = 0
egm.settings.activate.wobj.oframe.trans.y = 0
egm.settings.activate.wobj.oframe.trans.z = 0
egm.settings.activate.wobj.oframe.rot.q1 = 1
egm.settings.activate.wobj.oframe.rot.q2 = 0
egm.settings.activate.wobj.oframe.rot.q3 = 0
egm.settings.activate.wobj.oframe.rot.q4 = 0

egm.settings.activate.correction_frame = egm.settings.activate.tool.tframe
egm.settings.activate.sensor_frame = egm.settings.activate.tool.tframe

egm.settings.activate.lp_filter = 30
# egm.settings.activate.lp_filter = 0
egm.settings.activate.max_speed_deviation = 250
# egm.settings.activate.max_speed_deviation = 50
# egm.settings.activate.sample_rate = 20
egm.settings.activate.sample_rate = 4

egm.settings.activate.cond_min_max = 0.15
egm.settings.use_presync = True
egm.settings.allow_egm_motions = True
egm.settings.setup_uc.comm_timeout = 1000
# egm.settings.setup_uc.use_filtering = False
egm.settings.setup_uc.use_filtering = True
egm.settings.stop.ramp_out_time = 0.01
egm.settings.run.ramp_in_time = 0.01
egm.settings.run.cond_time = 1000
egm.settings.run.pos_corr_gain = 1
egm.settings.run.offset = egm.settings.activate.tool.tframe

res = SetEGMSettingsResponse()
res = egm_client(egm)
print (res)
