#!/usr/bin/env python3
import rospy
from abb_rapid_sm_addin_msgs.srv import SetEGMSettings, SetEGMSettingsRequest, SetEGMSettingsResponse
from std_srvs.srv import SetBool, SetBoolRequest, SetBoolResponse
from abb_robot_msgs.srv import TriggerWithResultCode, TriggerWithResultCodeRequest, TriggerWithResultCodeResponse


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


def set_control_mode_cb(request):
    global egm
    "stop egm"
    req_1 = TriggerWithResultCodeRequest()
    res_1 = TriggerWithResultCodeResponse()
    res_1 = stop_egm.call(req_1)
    print (res_1)
    rospy.sleep(1)
    "change the controller gain"
    if request.data is True:
        "set trajectory control"
        egm.settings.run.pos_corr_gain = 1
        print ("true")
    else:
        egm.settings.run.pos_corr_gain = 0.1
          
    res = SetEGMSettingsResponse()
    res = egm_client(egm)
    print (res)
    rospy.sleep(1)
    
    "restart egm"
    req = TriggerWithResultCodeRequest()
    res = TriggerWithResultCodeResponse()
    res = start_egm.call(req)
    
    "return the response"
    response = SetBoolResponse(success=True)
    return response
    



rospy.init_node("egm_config")
rospy.Service("/egm/set_control_mode", SetBool, set_control_mode_cb)
egm_client = rospy.ServiceProxy("/rws/sm_addin/set_egm_settings", SetEGMSettings)
stop_egm = rospy.ServiceProxy("/rws/sm_addin/stop_egm", TriggerWithResultCode)
start_egm = rospy.ServiceProxy("/rws/sm_addin/start_egm_joint", TriggerWithResultCode)
rospy.sleep(1)
rospy.spin()
