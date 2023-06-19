#ifndef _ROS_robotont_msgs_LedModuleSegment_h
#define _ROS_robotont_msgs_LedModuleSegment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotont_msgs/ColorRGB.h"

namespace robotont_msgs
{

  class LedModuleSegment : public ros::Msg
  {
    public:
      typedef uint32_t _idx_start_type;
      _idx_start_type idx_start;
      uint32_t colors_length;
      typedef robotont_msgs::ColorRGB _colors_type;
      _colors_type st_colors;
      _colors_type * colors;

    LedModuleSegment():
      idx_start(0),
      colors_length(0), st_colors(), colors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->idx_start >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idx_start >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idx_start >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idx_start >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idx_start);
      *(outbuffer + offset + 0) = (this->colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colors_length);
      for( uint32_t i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->idx_start =  ((uint32_t) (*(inbuffer + offset)));
      this->idx_start |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idx_start |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->idx_start |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->idx_start);
      uint32_t colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->colors_length);
      if(colors_lengthT > colors_length)
        this->colors = (robotont_msgs::ColorRGB*)realloc(this->colors, colors_lengthT * sizeof(robotont_msgs::ColorRGB));
      colors_length = colors_lengthT;
      for( uint32_t i = 0; i < colors_length; i++){
      offset += this->st_colors.deserialize(inbuffer + offset);
        memcpy( &(this->colors[i]), &(this->st_colors), sizeof(robotont_msgs::ColorRGB));
      }
     return offset;
    }

    virtual const char * getType() override { return "robotont_msgs/LedModuleSegment"; };
    virtual const char * getMD5() override { return "074116e38328a837ef6928799ed4707a"; };

  };

}
#endif
