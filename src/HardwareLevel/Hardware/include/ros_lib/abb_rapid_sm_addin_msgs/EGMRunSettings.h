#ifndef _ROS_abb_rapid_sm_addin_msgs_EGMRunSettings_h
#define _ROS_abb_rapid_sm_addin_msgs_EGMRunSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/Pose.h"

namespace abb_rapid_sm_addin_msgs
{

  class EGMRunSettings : public ros::Msg
  {
    public:
      typedef float _cond_time_type;
      _cond_time_type cond_time;
      typedef float _ramp_in_time_type;
      _ramp_in_time_type ramp_in_time;
      typedef abb_rapid_msgs::Pose _offset_type;
      _offset_type offset;
      typedef float _pos_corr_gain_type;
      _pos_corr_gain_type pos_corr_gain;

    EGMRunSettings():
      cond_time(0),
      ramp_in_time(0),
      offset(),
      pos_corr_gain(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cond_time;
      u_cond_time.real = this->cond_time;
      *(outbuffer + offset + 0) = (u_cond_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cond_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cond_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cond_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cond_time);
      union {
        float real;
        uint32_t base;
      } u_ramp_in_time;
      u_ramp_in_time.real = this->ramp_in_time;
      *(outbuffer + offset + 0) = (u_ramp_in_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ramp_in_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ramp_in_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ramp_in_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ramp_in_time);
      offset += this->offset.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pos_corr_gain;
      u_pos_corr_gain.real = this->pos_corr_gain;
      *(outbuffer + offset + 0) = (u_pos_corr_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_corr_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_corr_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_corr_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_corr_gain);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cond_time;
      u_cond_time.base = 0;
      u_cond_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cond_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cond_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cond_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cond_time = u_cond_time.real;
      offset += sizeof(this->cond_time);
      union {
        float real;
        uint32_t base;
      } u_ramp_in_time;
      u_ramp_in_time.base = 0;
      u_ramp_in_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ramp_in_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ramp_in_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ramp_in_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ramp_in_time = u_ramp_in_time.real;
      offset += sizeof(this->ramp_in_time);
      offset += this->offset.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pos_corr_gain;
      u_pos_corr_gain.base = 0;
      u_pos_corr_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos_corr_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos_corr_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos_corr_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos_corr_gain = u_pos_corr_gain.real;
      offset += sizeof(this->pos_corr_gain);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/EGMRunSettings"; };
    virtual const char * getMD5() override { return "f6a2d3b6d7d6ffc880c4bc86612a6691"; };

  };

}
#endif
