#ifndef _ROS_mesh_msgs_MeshFaceClusterStamped_h
#define _ROS_mesh_msgs_MeshFaceClusterStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/MeshFaceCluster.h"

namespace mesh_msgs
{

  class MeshFaceClusterStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef mesh_msgs::MeshFaceCluster _cluster_type;
      _cluster_type cluster;
      typedef bool _override_type;
      _override_type override;

    MeshFaceClusterStamped():
      header(),
      uuid(""),
      cluster(),
      override(0)
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
      offset += this->cluster.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_override;
      u_override.real = this->override;
      *(outbuffer + offset + 0) = (u_override.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override);
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
      offset += this->cluster.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_override;
      u_override.base = 0;
      u_override.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override = u_override.real;
      offset += sizeof(this->override);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshFaceClusterStamped"; };
    virtual const char * getMD5() override { return "e9b5993e06e78f5ff36e4050fa2e88c6"; };

  };

}
#endif
