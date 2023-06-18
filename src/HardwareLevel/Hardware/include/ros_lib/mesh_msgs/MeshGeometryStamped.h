#ifndef _ROS_mesh_msgs_MeshGeometryStamped_h
#define _ROS_mesh_msgs_MeshGeometryStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/MeshGeometry.h"

namespace mesh_msgs
{

  class MeshGeometryStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef mesh_msgs::MeshGeometry _mesh_geometry_type;
      _mesh_geometry_type mesh_geometry;

    MeshGeometryStamped():
      header(),
      uuid(""),
      mesh_geometry()
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
      offset += this->mesh_geometry.serialize(outbuffer + offset);
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
      offset += this->mesh_geometry.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshGeometryStamped"; };
    virtual const char * getMD5() override { return "2d62dc21b3d9b8f528e4ee7f76a77fb7"; };

  };

}
#endif
