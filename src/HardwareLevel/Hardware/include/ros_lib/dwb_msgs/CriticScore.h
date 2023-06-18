#ifndef _ROS_dwb_msgs_CriticScore_h
#define _ROS_dwb_msgs_CriticScore_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dwb_msgs
{

  class CriticScore : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef float _raw_score_type;
      _raw_score_type raw_score;
      typedef float _scale_type;
      _scale_type scale;

    CriticScore():
      name(""),
      raw_score(0),
      scale(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_raw_score;
      u_raw_score.real = this->raw_score;
      *(outbuffer + offset + 0) = (u_raw_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_score);
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.real = this->scale;
      *(outbuffer + offset + 0) = (u_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scale.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_raw_score;
      u_raw_score.base = 0;
      u_raw_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->raw_score = u_raw_score.real;
      offset += sizeof(this->raw_score);
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.base = 0;
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scale = u_scale.real;
      offset += sizeof(this->scale);
     return offset;
    }

    virtual const char * getType() override { return "dwb_msgs/CriticScore"; };
    virtual const char * getMD5() override { return "442332720f7b0ede3653c34ceeb74662"; };

  };

}
#endif
