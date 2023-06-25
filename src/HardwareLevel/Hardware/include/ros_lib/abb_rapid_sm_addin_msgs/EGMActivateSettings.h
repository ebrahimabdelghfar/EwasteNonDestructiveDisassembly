#ifndef _ROS_abb_rapid_sm_addin_msgs_EGMActivateSettings_h
#define _ROS_abb_rapid_sm_addin_msgs_EGMActivateSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/ToolData.h"
#include "abb_rapid_msgs/WObjData.h"
#include "abb_rapid_msgs/Pose.h"

namespace abb_rapid_sm_addin_msgs
{

  class EGMActivateSettings : public ros::Msg
  {
    public:
      typedef abb_rapid_msgs::ToolData _tool_type;
      _tool_type tool;
      typedef abb_rapid_msgs::WObjData _wobj_type;
      _wobj_type wobj;
      typedef abb_rapid_msgs::Pose _correction_frame_type;
      _correction_frame_type correction_frame;
      typedef abb_rapid_msgs::Pose _sensor_frame_type;
      _sensor_frame_type sensor_frame;
      typedef float _cond_min_max_type;
      _cond_min_max_type cond_min_max;
      typedef float _lp_filter_type;
      _lp_filter_type lp_filter;
      typedef uint8_t _sample_rate_type;
      _sample_rate_type sample_rate;
      typedef float _max_speed_deviation_type;
      _max_speed_deviation_type max_speed_deviation;

    EGMActivateSettings():
      tool(),
      wobj(),
      correction_frame(),
      sensor_frame(),
      cond_min_max(0),
      lp_filter(0),
      sample_rate(0),
      max_speed_deviation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->tool.serialize(outbuffer + offset);
      offset += this->wobj.serialize(outbuffer + offset);
      offset += this->correction_frame.serialize(outbuffer + offset);
      offset += this->sensor_frame.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_cond_min_max;
      u_cond_min_max.real = this->cond_min_max;
      *(outbuffer + offset + 0) = (u_cond_min_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cond_min_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cond_min_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cond_min_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cond_min_max);
      union {
        float real;
        uint32_t base;
      } u_lp_filter;
      u_lp_filter.real = this->lp_filter;
      *(outbuffer + offset + 0) = (u_lp_filter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lp_filter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lp_filter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lp_filter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lp_filter);
      *(outbuffer + offset + 0) = (this->sample_rate >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sample_rate);
      union {
        float real;
        uint32_t base;
      } u_max_speed_deviation;
      u_max_speed_deviation.real = this->max_speed_deviation;
      *(outbuffer + offset + 0) = (u_max_speed_deviation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_speed_deviation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_speed_deviation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_speed_deviation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_speed_deviation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->tool.deserialize(inbuffer + offset);
      offset += this->wobj.deserialize(inbuffer + offset);
      offset += this->correction_frame.deserialize(inbuffer + offset);
      offset += this->sensor_frame.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_cond_min_max;
      u_cond_min_max.base = 0;
      u_cond_min_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cond_min_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cond_min_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cond_min_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cond_min_max = u_cond_min_max.real;
      offset += sizeof(this->cond_min_max);
      union {
        float real;
        uint32_t base;
      } u_lp_filter;
      u_lp_filter.base = 0;
      u_lp_filter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lp_filter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lp_filter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lp_filter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lp_filter = u_lp_filter.real;
      offset += sizeof(this->lp_filter);
      this->sample_rate =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sample_rate);
      union {
        float real;
        uint32_t base;
      } u_max_speed_deviation;
      u_max_speed_deviation.base = 0;
      u_max_speed_deviation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_speed_deviation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_speed_deviation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_speed_deviation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_speed_deviation = u_max_speed_deviation.real;
      offset += sizeof(this->max_speed_deviation);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/EGMActivateSettings"; };
    virtual const char * getMD5() override { return "edc93be8ce076e9147c54b4dc80e7974"; };

  };

}
#endif
