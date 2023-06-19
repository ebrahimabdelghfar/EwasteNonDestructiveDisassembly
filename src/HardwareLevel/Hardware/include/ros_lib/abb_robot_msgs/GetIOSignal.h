#ifndef _ROS_SERVICE_GetIOSignal_h
#define _ROS_SERVICE_GetIOSignal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char GETIOSIGNAL[] = "abb_robot_msgs/GetIOSignal";

  class GetIOSignalRequest : public ros::Msg
  {
    public:
      typedef const char* _signal_type;
      _signal_type signal;

    GetIOSignalRequest():
      signal("")
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
     return offset;
    }

    virtual const char * getType() override { return GETIOSIGNAL; };
    virtual const char * getMD5() override { return "9591b8ace81feee36c93130ad3fe6a19"; };

  };

  class GetIOSignalResponse : public ros::Msg
  {
    public:
      typedef const char* _value_type;
      _value_type value;
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    GetIOSignalResponse():
      value(""),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
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
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
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

    virtual const char * getType() override { return GETIOSIGNAL; };
    virtual const char * getMD5() override { return "2e935abf84f6e652529bba09693d1ffe"; };

  };

  class GetIOSignal {
    public:
    typedef GetIOSignalRequest Request;
    typedef GetIOSignalResponse Response;
  };

}
#endif
