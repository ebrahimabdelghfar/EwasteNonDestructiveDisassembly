#ifndef _ROS_robotont_msgs_LedModulePixel_h
#define _ROS_robotont_msgs_LedModulePixel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotont_msgs/ColorRGB.h"

namespace robotont_msgs
{

  class LedModulePixel : public ros::Msg
  {
    public:
      typedef uint32_t _idx_type;
      _idx_type idx;
      typedef robotont_msgs::ColorRGB _color_type;
      _color_type color;

    LedModulePixel():
      idx(0),
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->idx >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idx >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idx >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idx >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idx);
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->idx =  ((uint32_t) (*(inbuffer + offset)));
      this->idx |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idx |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->idx |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->idx);
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "robotont_msgs/LedModulePixel"; };
    virtual const char * getMD5() override { return "3e8715e10cbaf5916ac0df9876db527d"; };

  };

}
#endif
