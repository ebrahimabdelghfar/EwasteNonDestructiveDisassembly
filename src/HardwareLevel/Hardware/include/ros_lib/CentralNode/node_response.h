#ifndef _ROS_CentralNode_node_response_h
#define _ROS_CentralNode_node_response_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace CentralNode
{

  class node_response : public ros::Msg
  {
    public:
      typedef int32_t _nodeId_type;
      _nodeId_type nodeId;
      typedef const char* _extraMessage_type;
      _extraMessage_type extraMessage;
      typedef uint8_t _status_type;
      _status_type status;

    node_response():
      nodeId(0),
      extraMessage(""),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nodeId;
      u_nodeId.real = this->nodeId;
      *(outbuffer + offset + 0) = (u_nodeId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeId);
      uint32_t length_extraMessage = strlen(this->extraMessage);
      varToArr(outbuffer + offset, length_extraMessage);
      offset += 4;
      memcpy(outbuffer + offset, this->extraMessage, length_extraMessage);
      offset += length_extraMessage;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nodeId;
      u_nodeId.base = 0;
      u_nodeId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeId = u_nodeId.real;
      offset += sizeof(this->nodeId);
      uint32_t length_extraMessage;
      arrToVar(length_extraMessage, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_extraMessage; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_extraMessage-1]=0;
      this->extraMessage = (char *)(inbuffer + offset-1);
      offset += length_extraMessage;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "CentralNode/node_response"; };
    virtual const char * getMD5() override { return "b888e972b0112a456a30ae15a1f395cd"; };

  };

}
#endif
