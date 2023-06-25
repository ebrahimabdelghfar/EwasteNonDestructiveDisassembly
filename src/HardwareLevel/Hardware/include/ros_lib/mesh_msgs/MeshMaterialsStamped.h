#ifndef _ROS_mesh_msgs_MeshMaterialsStamped_h
#define _ROS_mesh_msgs_MeshMaterialsStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/MeshMaterials.h"

namespace mesh_msgs
{

  class MeshMaterialsStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef mesh_msgs::MeshMaterials _mesh_materials_type;
      _mesh_materials_type mesh_materials;

    MeshMaterialsStamped():
      header(),
      uuid(""),
      mesh_materials()
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
      offset += this->mesh_materials.serialize(outbuffer + offset);
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
      offset += this->mesh_materials.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshMaterialsStamped"; };
    virtual const char * getMD5() override { return "80683ad6336327fea277cb1ed5f58927"; };

  };

}
#endif
