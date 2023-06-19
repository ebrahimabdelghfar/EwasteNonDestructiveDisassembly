#ifndef _ROS_SERVICE_SetRAPIDDnum_h
#define _ROS_SERVICE_SetRAPIDDnum_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_robot_msgs/RAPIDSymbolPath.h"

namespace abb_robot_msgs
{

static const char SETRAPIDDNUM[] = "abb_robot_msgs/SetRAPIDDnum";

  class SetRAPIDDnumRequest : public ros::Msg
  {
    public:
      typedef abb_robot_msgs::RAPIDSymbolPath _path_type;
      _path_type path;
      typedef double _value_type;
      _value_type value;

    SetRAPIDDnumRequest():
      path(),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_value.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_value.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_value.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_value.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return SETRAPIDDNUM; };
    virtual const char * getMD5() override { return "0b5fcc6b7bef74cb953dc54422f98c94"; };

  };

  class SetRAPIDDnumResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetRAPIDDnumResponse():
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

    virtual const char * getType() override { return SETRAPIDDNUM; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetRAPIDDnum {
    public:
    typedef SetRAPIDDnumRequest Request;
    typedef SetRAPIDDnumResponse Response;
  };

}
#endif
