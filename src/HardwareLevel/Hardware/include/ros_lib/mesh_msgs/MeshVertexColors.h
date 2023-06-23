#ifndef _ROS_mesh_msgs_MeshVertexColors_h
#define _ROS_mesh_msgs_MeshVertexColors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace mesh_msgs
{

  class MeshVertexColors : public ros::Msg
  {
    public:
      uint32_t vertex_colors_length;
      typedef std_msgs::ColorRGBA _vertex_colors_type;
      _vertex_colors_type st_vertex_colors;
      _vertex_colors_type * vertex_colors;

    MeshVertexColors():
      vertex_colors_length(0), st_vertex_colors(), vertex_colors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vertex_colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertex_colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertex_colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertex_colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertex_colors_length);
      for( uint32_t i = 0; i < vertex_colors_length; i++){
      offset += this->vertex_colors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t vertex_colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertex_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertex_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertex_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertex_colors_length);
      if(vertex_colors_lengthT > vertex_colors_length)
        this->vertex_colors = (std_msgs::ColorRGBA*)realloc(this->vertex_colors, vertex_colors_lengthT * sizeof(std_msgs::ColorRGBA));
      vertex_colors_length = vertex_colors_lengthT;
      for( uint32_t i = 0; i < vertex_colors_length; i++){
      offset += this->st_vertex_colors.deserialize(inbuffer + offset);
        memcpy( &(this->vertex_colors[i]), &(this->st_vertex_colors), sizeof(std_msgs::ColorRGBA));
      }
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshVertexColors"; };
    virtual const char * getMD5() override { return "2af51ba6de42b829b6f716360dfdf4d9"; };

  };

}
#endif
