#ifndef _ROS_mesh_msgs_MeshTexture_h
#define _ROS_mesh_msgs_MeshTexture_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace mesh_msgs
{

  class MeshTexture : public ros::Msg
  {
    public:
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef uint32_t _texture_index_type;
      _texture_index_type texture_index;
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    MeshTexture():
      uuid(""),
      texture_index(0),
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_uuid = strlen(this->uuid);
      varToArr(outbuffer + offset, length_uuid);
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_uuid);
      offset += length_uuid;
      *(outbuffer + offset + 0) = (this->texture_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->texture_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->texture_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->texture_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->texture_index);
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_uuid;
      arrToVar(length_uuid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uuid-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_uuid;
      this->texture_index =  ((uint32_t) (*(inbuffer + offset)));
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->texture_index);
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshTexture"; };
    virtual const char * getMD5() override { return "831d05ad895f7916c0c27143f387dfa0"; };

  };

}
#endif
