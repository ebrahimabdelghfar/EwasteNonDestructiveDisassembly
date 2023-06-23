#ifndef _ROS_SERVICE_SetIOSignal_h
#define _ROS_SERVICE_SetIOSignal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char SETIOSIGNAL[] = "abb_robot_msgs/SetIOSignal";

  class SetIOSignalRequest : public ros::Msg
  {
    public:
      typedef const char* _signal_type;
      _signal_type signal;
      typedef const char* _value_type;
      _value_type value;

    SetIOSignalRequest():
      signal(""),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_signal = strlen(this->signal);
      varToArr(outbuffer + offset, length_signal);
      offset += 4;
      memcpy(outbuffer + offset, this->signal, length_signal);
      offset += length_signal;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_signal;
      arrToVar(length_signal, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_signal; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_signal-1]=0;
      this->signal = (char *)(inbuffer + offset-1);
      offset += length_signal;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    virtual const char * getType() override { return SETIOSIGNAL; };
    virtual const char * getMD5() override { return "17cb31e0dfb7106dce1621cc1fa3f3bf"; };

  };

  class SetIOSignalResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetIOSignalResponse():
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

    virtual const char * getType() override { return SETIOSIGNAL; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetIOSignal {
    public:
    typedef SetIOSignalRequest Request;
    typedef SetIOSignalResponse Response;
  };

}
#endif
