#ifndef _ROS_rm_msgs_TagMsgArray_h
#define _ROS_rm_msgs_TagMsgArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rm_msgs/TagMsg.h"

namespace rm_msgs
{

  class TagMsgArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t tag_msgs_array_length;
      typedef rm_msgs::TagMsg _tag_msgs_array_type;
      _tag_msgs_array_type st_tag_msgs_array;
      _tag_msgs_array_type * tag_msgs_array;

    TagMsgArray():
      header(),
      tag_msgs_array_length(0), st_tag_msgs_array(), tag_msgs_array(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tag_msgs_array_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tag_msgs_array_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tag_msgs_array_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tag_msgs_array_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tag_msgs_array_length);
      for( uint32_t i = 0; i < tag_msgs_array_length; i++){
      offset += this->tag_msgs_array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t tag_msgs_array_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tag_msgs_array_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tag_msgs_array_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tag_msgs_array_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tag_msgs_array_length);
      if(tag_msgs_array_lengthT > tag_msgs_array_length)
        this->tag_msgs_array = (rm_msgs::TagMsg*)realloc(this->tag_msgs_array, tag_msgs_array_lengthT * sizeof(rm_msgs::TagMsg));
      tag_msgs_array_length = tag_msgs_array_lengthT;
      for( uint32_t i = 0; i < tag_msgs_array_length; i++){
      offset += this->st_tag_msgs_array.deserialize(inbuffer + offset);
        memcpy( &(this->tag_msgs_array[i]), &(this->st_tag_msgs_array), sizeof(rm_msgs::TagMsg));
      }
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/TagMsgArray"; };
    virtual const char * getMD5() override { return "902a772db603bf3e4cf94e3aa203838c"; };

  };

}
#endif
