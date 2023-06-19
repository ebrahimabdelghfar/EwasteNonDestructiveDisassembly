#ifndef _ROS_abb_rapid_msgs_ToolData_h
#define _ROS_abb_rapid_msgs_ToolData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/Pose.h"
#include "abb_rapid_msgs/LoadData.h"

namespace abb_rapid_msgs
{

  class ToolData : public ros::Msg
  {
    public:
      typedef bool _robhold_type;
      _robhold_type robhold;
      typedef abb_rapid_msgs::Pose _tframe_type;
      _tframe_type tframe;
      typedef abb_rapid_msgs::LoadData _tload_type;
      _tload_type tload;

    ToolData():
      robhold(0),
      tframe(),
      tload()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_robhold;
      u_robhold.real = this->robhold;
      *(outbuffer + offset + 0) = (u_robhold.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->robhold);
      offset += this->tframe.serialize(outbuffer + offset);
      offset += this->tload.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_robhold;
      u_robhold.base = 0;
      u_robhold.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->robhold = u_robhold.real;
      offset += sizeof(this->robhold);
      offset += this->tframe.deserialize(inbuffer + offset);
      offset += this->tload.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/ToolData"; };
    virtual const char * getMD5() override { return "2d526e4dd17e28147b27f746cf88c5b6"; };

  };

}
#endif
