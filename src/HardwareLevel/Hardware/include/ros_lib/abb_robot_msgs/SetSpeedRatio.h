#ifndef _ROS_SERVICE_SetSpeedRatio_h
#define _ROS_SERVICE_SetSpeedRatio_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char SETSPEEDRATIO[] = "abb_robot_msgs/SetSpeedRatio";

  class SetSpeedRatioRequest : public ros::Msg
  {
    public:
      typedef uint8_t _speed_ratio_type;
      _speed_ratio_type speed_ratio;

    SetSpeedRatioRequest():
      speed_ratio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->speed_ratio >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_ratio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->speed_ratio =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed_ratio);
     return offset;
    }

    virtual const char * getType() override { return SETSPEEDRATIO; };
    virtual const char * getMD5() override { return "433e0c752185d553ba16644b83665ddc"; };

  };

  class SetSpeedRatioResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetSpeedRatioResponse():
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return SETSPEEDRATIO; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetSpeedRatio {
    public:
    typedef SetSpeedRatioRequest Request;
    typedef SetSpeedRatioResponse Response;
  };

}
#endif
