#ifndef _ROS_mesh_msgs_MeshVertexCostsStamped_h
#define _ROS_mesh_msgs_MeshVertexCostsStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/MeshVertexCosts.h"

namespace mesh_msgs
{

  class MeshVertexCostsStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef const char* _type_type;
      _type_type type;
      typedef mesh_msgs::MeshVertexCosts _mesh_vertex_costs_type;
      _mesh_vertex_costs_type mesh_vertex_costs;

    MeshVertexCostsStamped():
      header(),
      uuid(""),
      type(""),
      mesh_vertex_costs()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_uuid = strlen(this->uuid);
      varToArr(outbuffer + offset, length_uuid);
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_uuid);
      offset += length_uuid;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += this->mesh_vertex_costs.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_uuid;
      arrToVar(length_uuid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uuid-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_uuid;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += this->mesh_vertex_costs.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshVertexCostsStamped"; };
    virtual const char * getMD5() override { return "f65d52b48920bc9c2a071d643ab7b6b3"; };

  };

}
#endif
