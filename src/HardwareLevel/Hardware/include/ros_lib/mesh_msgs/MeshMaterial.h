#ifndef _ROS_mesh_msgs_MeshMaterial_h
#define _ROS_mesh_msgs_MeshMaterial_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace mesh_msgs
{

  class MeshMaterial : public ros::Msg
  {
    public:
      typedef uint32_t _texture_index_type;
      _texture_index_type texture_index;
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef bool _has_texture_type;
      _has_texture_type has_texture;

    MeshMaterial():
      texture_index(0),
      color(),
      has_texture(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->texture_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->texture_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->texture_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->texture_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->texture_index);
      offset += this->color.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_texture;
      u_has_texture.real = this->has_texture;
      *(outbuffer + offset + 0) = (u_has_texture.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_texture);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->texture_index =  ((uint32_t) (*(inbuffer + offset)));
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->texture_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->texture_index);
      offset += this->color.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_texture;
      u_has_texture.base = 0;
      u_has_texture.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_texture = u_has_texture.real;
      offset += sizeof(this->has_texture);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshMaterial"; };
    virtual const char * getMD5() override { return "6ad79583de5735994d239e1d0f34371b"; };

  };

}
#endif
