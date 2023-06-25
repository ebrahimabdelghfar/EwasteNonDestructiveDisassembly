#ifndef _ROS_SERVICE_GetSpeedRatio_h
#define _ROS_SERVICE_GetSpeedRatio_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char GETSPEEDRATIO[] = "abb_robot_msgs/GetSpeedRatio";

  class GetSpeedRatioRequest : public ros::Msg
  {
    public:

    GetSpeedRatioRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETSPEEDRATIO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetSpeedRatioResponse : public ros::Msg
  {
    public:
      typedef uint8_t _speed_ratio_type;
      _speed_ratio_type speed_ratio;
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    GetSpeedRatioResponse():
      speed_ratio(0),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->speed_ratio >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_ratio);
      *(outbuffer + offset + 0) = (this->result_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->result_code >> (8 * 1)) & 0xFF;
      offset += sizeof(this->result_code);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->speed_ratio =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed_ratio);
      this->result_code =  ((uint16_t) (*(inbuffer + offset)));
      this->result_code |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->result_code);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return GETSPEEDRATIO; };
    virtual const char * getMD5() override { return "f0753046e29c5c4aa8b7b9ff8a761daf"; };

  };

  class GetSpeedRatio {
    public:
    typedef GetSpeedRatioRequest Request;
    typedef GetSpeedRatioResponse Response;
  };

}
#endif
