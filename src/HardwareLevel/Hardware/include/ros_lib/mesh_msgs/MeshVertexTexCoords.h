#ifndef _ROS_mesh_msgs_MeshVertexTexCoords_h
#define _ROS_mesh_msgs_MeshVertexTexCoords_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mesh_msgs
{

  class MeshVertexTexCoords : public ros::Msg
  {
    public:
      typedef float _u_type;
      _u_type u;
      typedef float _v_type;
      _v_type v;

    MeshVertexTexCoords():
      u(0),
      v(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_u;
      u_u.real = this->u;
      *(outbuffer + offset + 0) = (u_u.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.real = this->v;
      *(outbuffer + offset + 0) = (u_v.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_u;
      u_u.base = 0;
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u = u_u.real;
      offset += sizeof(this->u);
      union {
        float real;
        uint32_t base;
      } u_v;
      u_v.base = 0;
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v = u_v.real;
      offset += sizeof(this->v);
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshVertexTexCoords"; };
    virtual const char * getMD5() override { return "4f5254e0e12914c461d4b17a0cd07f7f"; };

  };

}
#endif
