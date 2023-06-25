#ifndef _ROS_abb_rapid_sm_addin_msgs_EGMStopSettings_h
#define _ROS_abb_rapid_sm_addin_msgs_EGMStopSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_sm_addin_msgs
{

  class EGMStopSettings : public ros::Msg
  {
    public:
      typedef float _ramp_out_time_type;
      _ramp_out_time_type ramp_out_time;

    EGMStopSettings():
      ramp_out_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ramp_out_time;
      u_ramp_out_time.real = this->ramp_out_time;
      *(outbuffer + offset + 0) = (u_ramp_out_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ramp_out_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ramp_out_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ramp_out_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ramp_out_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_ramp_out_time;
      u_ramp_out_time.base = 0;
      u_ramp_out_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ramp_out_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ramp_out_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ramp_out_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ramp_out_time = u_ramp_out_time.real;
      offset += sizeof(this->ramp_out_time);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/EGMStopSettings"; };
    virtual const char * getMD5() override { return "0e3716aa777ece435e2f7343649fe19b"; };

  };

}
#endif
