#ifndef _ROS_SERVICE_SetFileContents_h
#define _ROS_SERVICE_SetFileContents_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char SETFILECONTENTS[] = "abb_robot_msgs/SetFileContents";

  class SetFileContentsRequest : public ros::Msg
  {
    public:
      typedef const char* _filename_type;
      _filename_type filename;
      typedef const char* _contents_type;
      _contents_type contents;

    SetFileContentsRequest():
      filename(""),
      contents("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_filename = strlen(this->filename);
      varToArr(outbuffer + offset, length_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      uint32_t length_contents = strlen(this->contents);
      varToArr(outbuffer + offset, length_contents);
      offset += 4;
      memcpy(outbuffer + offset, this->contents, length_contents);
      offset += length_contents;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_filename;
      arrToVar(length_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
      uint32_t length_contents;
      arrToVar(length_contents, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_contents; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_contents-1]=0;
      this->contents = (char *)(inbuffer + offset-1);
      offset += length_contents;
     return offset;
    }

    virtual const char * getType() override { return SETFILECONTENTS; };
    virtual const char * getMD5() override { return "328533d33dcf184e6cd9fb09e7803883"; };

  };

  class SetFileContentsResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetFileContentsResponse():
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

    virtual const char * getType() override { return SETFILECONTENTS; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetFileContents {
    public:
    typedef SetFileContentsRequest Request;
    typedef SetFileContentsResponse Response;
  };

}
#endif
