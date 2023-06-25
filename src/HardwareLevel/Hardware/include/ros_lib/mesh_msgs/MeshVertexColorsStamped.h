#ifndef _ROS_mesh_msgs_MeshVertexColorsStamped_h
#define _ROS_mesh_msgs_MeshVertexColorsStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/MeshVertexColors.h"

namespace mesh_msgs
{

  class MeshVertexColorsStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef mesh_msgs::MeshVertexColors _mesh_vertex_colors_type;
      _mesh_vertex_colors_type mesh_vertex_colors;

    MeshVertexColorsStamped():
      header(),
      uuid(""),
      mesh_vertex_colors()
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
      offset += this->mesh_vertex_colors.serialize(outbuffer + offset);
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
      offset += this->mesh_vertex_colors.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshVertexColorsStamped"; };
    virtual const char * getMD5() override { return "9e3527729bbf26fabb162c58762b6739"; };

  };

}
#endif
