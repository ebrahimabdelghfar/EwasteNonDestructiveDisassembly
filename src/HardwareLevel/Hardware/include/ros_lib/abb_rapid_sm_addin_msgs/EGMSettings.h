#ifndef _ROS_abb_rapid_sm_addin_msgs_EGMSettings_h
#define _ROS_abb_rapid_sm_addin_msgs_EGMSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_sm_addin_msgs/EGMSetupSettings.h"
#include "abb_rapid_sm_addin_msgs/EGMActivateSettings.h"
#include "abb_rapid_sm_addin_msgs/EGMRunSettings.h"
#include "abb_rapid_sm_addin_msgs/EGMStopSettings.h"

namespace abb_rapid_sm_addin_msgs
{

  class EGMSettings : public ros::Msg
  {
    public:
      typedef bool _allow_egm_motions_type;
      _allow_egm_motions_type allow_egm_motions;
      typedef bool _use_presync_type;
      _use_presync_type use_presync;
      typedef abb_rapid_sm_addin_msgs::EGMSetupSettings _setup_uc_type;
      _setup_uc_type setup_uc;
      typedef abb_rapid_sm_addin_msgs::EGMActivateSettings _activate_type;
      _activate_type activate;
      typedef abb_rapid_sm_addin_msgs::EGMRunSettings _run_type;
      _run_type run;
      typedef abb_rapid_sm_addin_msgs::EGMStopSettings _stop_type;
      _stop_type stop;

    EGMSettings():
      allow_egm_motions(0),
      use_presync(0),
      setup_uc(),
      activate(),
      run(),
      stop()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_allow_egm_motions;
      u_allow_egm_motions.real = this->allow_egm_motions;
      *(outbuffer + offset + 0) = (u_allow_egm_motions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_egm_motions);
      union {
        bool real;
        uint8_t base;
      } u_use_presync;
      u_use_presync.real = this->use_presync;
      *(outbuffer + offset + 0) = (u_use_presync.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_presync);
      offset += this->setup_uc.serialize(outbuffer + offset);
      offset += this->activate.serialize(outbuffer + offset);
      offset += this->run.serialize(outbuffer + offset);
      offset += this->stop.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_allow_egm_motions;
      u_allow_egm_motions.base = 0;
      u_allow_egm_motions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_egm_motions = u_allow_egm_motions.real;
      offset += sizeof(this->allow_egm_motions);
      union {
        bool real;
        uint8_t base;
      } u_use_presync;
      u_use_presync.base = 0;
      u_use_presync.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_presync = u_use_presync.real;
      offset += sizeof(this->use_presync);
      offset += this->setup_uc.deserialize(inbuffer + offset);
      offset += this->activate.deserialize(inbuffer + offset);
      offset += this->run.deserialize(inbuffer + offset);
      offset += this->stop.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/EGMSettings"; };
    virtual const char * getMD5() override { return "7c458fd979a6a372744a25dc9e88085d"; };

  };

}
#endif
