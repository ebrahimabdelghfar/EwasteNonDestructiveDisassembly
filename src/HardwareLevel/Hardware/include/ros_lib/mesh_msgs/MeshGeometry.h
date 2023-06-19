#ifndef _ROS_mesh_msgs_MeshGeometry_h
#define _ROS_mesh_msgs_MeshGeometry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "mesh_msgs/MeshTriangleIndices.h"

namespace mesh_msgs
{

  class MeshGeometry : public ros::Msg
  {
    public:
      uint32_t vertices_length;
      typedef geometry_msgs::Point _vertices_type;
      _vertices_type st_vertices;
      _vertices_type * vertices;
      uint32_t vertex_normals_length;
      typedef geometry_msgs::Point _vertex_normals_type;
      _vertex_normals_type st_vertex_normals;
      _vertex_normals_type * vertex_normals;
      uint32_t faces_length;
      typedef mesh_msgs::MeshTriangleIndices _faces_type;
      _faces_type st_faces;
      _faces_type * faces;

    MeshGeometry():
      vertices_length(0), st_vertices(), vertices(nullptr),
      vertex_normals_length(0), st_vertex_normals(), vertex_normals(nullptr),
      faces_length(0), st_faces(), faces(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vertices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vertex_normals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertex_normals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertex_normals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertex_normals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertex_normals_length);
      for( uint32_t i = 0; i < vertex_normals_length; i++){
      offset += this->vertex_normals[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->faces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->faces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->faces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->faces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->faces_length);
      for( uint32_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertices_length);
      if(vertices_lengthT > vertices_length)
        this->vertices = (geometry_msgs::Point*)realloc(this->vertices, vertices_lengthT * sizeof(geometry_msgs::Point));
      vertices_length = vertices_lengthT;
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(geometry_msgs::Point));
      }
      uint32_t vertex_normals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertex_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertex_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertex_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertex_normals_length);
      if(vertex_normals_lengthT > vertex_normals_length)
        this->vertex_normals = (geometry_msgs::Point*)realloc(this->vertex_normals, vertex_normals_lengthT * sizeof(geometry_msgs::Point));
      vertex_normals_length = vertex_normals_lengthT;
      for( uint32_t i = 0; i < vertex_normals_length; i++){
      offset += this->st_vertex_normals.deserialize(inbuffer + offset);
        memcpy( &(this->vertex_normals[i]), &(this->st_vertex_normals), sizeof(geometry_msgs::Point));
      }
      uint32_t faces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      faces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->faces_length);
      if(faces_lengthT > faces_length)
        this->faces = (mesh_msgs::MeshTriangleIndices*)realloc(this->faces, faces_lengthT * sizeof(mesh_msgs::MeshTriangleIndices));
      faces_length = faces_lengthT;
      for( uint32_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(mesh_msgs::MeshTriangleIndices));
      }
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshGeometry"; };
    virtual const char * getMD5() override { return "9a7ed3efa2a35ef81abaf7dcc675ed20"; };

  };

}
#endif
