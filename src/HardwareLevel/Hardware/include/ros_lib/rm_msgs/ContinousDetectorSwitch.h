#ifndef _ROS_SERVICE_ContinousDetectorSwitch_h
#define _ROS_SERVICE_ContinousDetectorSwitch_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

static const char CONTINOUSDETECTORSWITCH[] = "rm_msgs/ContinousDetectorSwitch";

  class ContinousDetectorSwitchRequest : public ros::Msg
  {
    public:
      typedef bool _detector_switch_type;
      _detector_switch_type detector_switch;

    ContinousDetectorSwitchRequest():
      detector_switch(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_detector_switch;
      u_detector_switch.real = this->detector_switch;
      *(outbuffer + offset + 0) = (u_detector_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detector_switch);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_detector_switch;
      u_detector_switch.base = 0;
      u_detector_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detector_switch = u_detector_switch.real;
      offset += sizeof(this->detector_switch);
     return offset;
    }

    virtual const char * getType() override { return CONTINOUSDETECTORSWITCH; };
    virtual const char * getMD5() override { return "44769af043220a0ab56c4e47f2a8fda6"; };

  };

  class ContinousDetectorSwitchResponse : public ros::Msg
  {
    public:
      typedef bool _continous_is_success_type;
      _continous_is_success_type continous_is_success;

    ContinousDetectorSwitchResponse():
      continous_is_success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_continous_is_success;
      u_continous_is_success.real = this->continous_is_success;
      *(outbuffer + offset + 0) = (u_continous_is_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->continous_is_success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_continous_is_success;
      u_continous_is_success.base = 0;
      u_continous_is_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->continous_is_success = u_continous_is_success.real;
      offset += sizeof(this->continous_is_success);
     return offset;
    }

    virtual const char * getType() override { return CONTINOUSDETECTORSWITCH; };
    virtual const char * getMD5() override { return "1c6f82f10f321f14f93ae1c9cc5286d6"; };

  };

  class ContinousDetectorSwitch {
    public:
    typedef ContinousDetectorSwitchRequest Request;
    typedef ContinousDetectorSwitchResponse Response;
  };

}
#endif
