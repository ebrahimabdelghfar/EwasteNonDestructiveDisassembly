#ifndef _ROS_SERVICE_GetRAPIDBool_h
#define _ROS_SERVICE_GetRAPIDBool_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_robot_msgs/RAPIDSymbolPath.h"

namespace abb_robot_msgs
{

static const char GETRAPIDBOOL[] = "abb_robot_msgs/GetRAPIDBool";

  class GetRAPIDBoolRequest : public ros::Msg
  {
    public:
      typedef abb_robot_msgs::RAPIDSymbolPath _path_type;
      _path_type path;

    GetRAPIDBoolRequest():
      path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETRAPIDBOOL; };
    virtual const char * getMD5() override { return "575c1566b746b035b579d998cd699eb8"; };

  };

  class GetRAPIDBoolResponse : public ros::Msg
  {
    public:
      typedef bool _value_type;
      _value_type value;
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    GetRAPIDBoolResponse():
      value(0),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
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
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value = u_value.real;
      offset += sizeof(this->value);
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

    virtual const char * getType() override { return GETRAPIDBOOL; };
    virtual const char * getMD5() override { return "1add5488daec3a43971bfb40db471016"; };

  };

  class GetRAPIDBool {
    public:
    typedef GetRAPIDBoolRequest Request;
    typedef GetRAPIDBoolResponse Response;
  };

}
#endif
