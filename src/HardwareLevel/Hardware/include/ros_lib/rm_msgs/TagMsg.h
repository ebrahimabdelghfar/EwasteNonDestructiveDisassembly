#ifndef _ROS_rm_msgs_TagMsg_h
#define _ROS_rm_msgs_TagMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace rm_msgs
{

  class TagMsg : public ros::Msg
  {
    public:
      typedef uint8_t _color_type;
      _color_type color;
      typedef uint8_t _letter_type;
      _letter_type letter;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;

    TagMsg():
      color(0),
      letter(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      *(outbuffer + offset + 0) = (this->letter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->letter);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
      this->letter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->letter);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/TagMsg"; };
    virtual const char * getMD5() override { return "20cfdd82cc6da3ba1e2608103b8aa270"; };

  };

}
#endif
