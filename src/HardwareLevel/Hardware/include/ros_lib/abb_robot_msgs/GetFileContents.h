#ifndef _ROS_SERVICE_GetFileContents_h
#define _ROS_SERVICE_GetFileContents_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

static const char GETFILECONTENTS[] = "abb_robot_msgs/GetFileContents";

  class GetFileContentsRequest : public ros::Msg
  {
    public:
      typedef const char* _filename_type;
      _filename_type filename;

    GetFileContentsRequest():
      filename("")
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
     return offset;
    }

    virtual const char * getType() override { return GETFILECONTENTS; };
    virtual const char * getMD5() override { return "030824f52a0628ead956fb9d67e66ae9"; };

  };

  class GetFileContentsResponse : public ros::Msg
  {
    public:
      typedef const char* _contents_type;
      _contents_type contents;
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    GetFileContentsResponse():
      contents(""),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_contents = strlen(this->contents);
      varToArr(outbuffer + offset, length_contents);
      offset += 4;
      memcpy(outbuffer + offset, this->contents, length_contents);
      offset += length_contents;
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
      uint32_t length_contents;
      arrToVar(length_contents, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_contents; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_contents-1]=0;
      this->contents = (char *)(inbuffer + offset-1);
      offset += length_contents;
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

    virtual const char * getType() override { return GETFILECONTENTS; };
    virtual const char * getMD5() override { return "3a83ecd2e6d8d82acbb6145f3b481cff"; };

  };

  class GetFileContents {
    public:
    typedef GetFileContentsRequest Request;
    typedef GetFileContentsResponse Response;
  };

}
#endif
