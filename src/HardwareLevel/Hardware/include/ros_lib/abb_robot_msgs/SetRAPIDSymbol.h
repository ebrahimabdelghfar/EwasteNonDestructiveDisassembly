#ifndef _ROS_SERVICE_SetRAPIDSymbol_h
#define _ROS_SERVICE_SetRAPIDSymbol_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_robot_msgs/RAPIDSymbolPath.h"

namespace abb_robot_msgs
{

static const char SETRAPIDSYMBOL[] = "abb_robot_msgs/SetRAPIDSymbol";

  class SetRAPIDSymbolRequest : public ros::Msg
  {
    public:
      typedef abb_robot_msgs::RAPIDSymbolPath _path_type;
      _path_type path;
      typedef const char* _value_type;
      _value_type value;

    SetRAPIDSymbolRequest():
      path(),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
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
      offset += this->path.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return SETRAPIDSYMBOL; };
    virtual const char * getMD5() override { return "c81ac0a08ec42b48b22060c8bbfc22d7"; };

  };

  class SetRAPIDSymbolResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetRAPIDSymbolResponse():
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

    virtual const char * getType() override { return SETRAPIDSYMBOL; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetRAPIDSymbol {
    public:
    typedef SetRAPIDSymbolRequest Request;
    typedef SetRAPIDSymbolResponse Response;
  };

}
#endif
