#ifndef _ROS_SERVICE_SetRAPIDBool_h
#define _ROS_SERVICE_SetRAPIDBool_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_robot_msgs/RAPIDSymbolPath.h"

namespace abb_robot_msgs
{

static const char SETRAPIDBOOL[] = "abb_robot_msgs/SetRAPIDBool";

  class SetRAPIDBoolRequest : public ros::Msg
  {
    public:
      typedef abb_robot_msgs::RAPIDSymbolPath _path_type;
      _path_type path;
      typedef bool _value_type;
      _value_type value;

    SetRAPIDBoolRequest():
      path(),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return SETRAPIDBOOL; };
    virtual const char * getMD5() override { return "2e5236433c861ca5387e52892a7a45c0"; };

  };

  class SetRAPIDBoolResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetRAPIDBoolResponse():
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

    virtual const char * getType() override { return SETRAPIDBOOL; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetRAPIDBool {
    public:
    typedef SetRAPIDBoolRequest Request;
    typedef SetRAPIDBoolResponse Response;
  };

}
#endif
