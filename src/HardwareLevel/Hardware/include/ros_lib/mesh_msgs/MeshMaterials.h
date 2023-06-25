#ifndef _ROS_mesh_msgs_MeshMaterials_h
#define _ROS_mesh_msgs_MeshMaterials_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mesh_msgs/MeshFaceCluster.h"
#include "mesh_msgs/MeshMaterial.h"
#include "mesh_msgs/MeshVertexTexCoords.h"

namespace mesh_msgs
{

  class MeshMaterials : public ros::Msg
  {
    public:
      uint32_t clusters_length;
      typedef mesh_msgs::MeshFaceCluster _clusters_type;
      _clusters_type st_clusters;
      _clusters_type * clusters;
      uint32_t materials_length;
      typedef mesh_msgs::MeshMaterial _materials_type;
      _materials_type st_materials;
      _materials_type * materials;
      uint32_t cluster_materials_length;
      typedef uint32_t _cluster_materials_type;
      _cluster_materials_type st_cluster_materials;
      _cluster_materials_type * cluster_materials;
      uint32_t vertex_tex_coords_length;
      typedef mesh_msgs::MeshVertexTexCoords _vertex_tex_coords_type;
      _vertex_tex_coords_type st_vertex_tex_coords;
      _vertex_tex_coords_type * vertex_tex_coords;

    MeshMaterials():
      clusters_length(0), st_clusters(), clusters(nullptr),
      materials_length(0), st_materials(), materials(nullptr),
      cluster_materials_length(0), st_cluster_materials(), cluster_materials(nullptr),
      vertex_tex_coords_length(0), st_vertex_tex_coords(), vertex_tex_coords(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->clusters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->clusters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->clusters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->clusters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->clusters_length);
      for( uint32_t i = 0; i < clusters_length; i++){
      offset += this->clusters[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->materials_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->materials_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->materials_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->materials_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->materials_length);
      for( uint32_t i = 0; i < materials_length; i++){
      offset += this->materials[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cluster_materials_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cluster_materials_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cluster_materials_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cluster_materials_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_materials_length);
      for( uint32_t i = 0; i < cluster_materials_length; i++){
      *(outbuffer + offset + 0) = (this->cluster_materials[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cluster_materials[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cluster_materials[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cluster_materials[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cluster_materials[i]);
      }
      *(outbuffer + offset + 0) = (this->vertex_tex_coords_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertex_tex_coords_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertex_tex_coords_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertex_tex_coords_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertex_tex_coords_length);
      for( uint32_t i = 0; i < vertex_tex_coords_length; i++){
      offset += this->vertex_tex_coords[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t clusters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      clusters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->clusters_length);
      if(clusters_lengthT > clusters_length)
        this->clusters = (mesh_msgs::MeshFaceCluster*)realloc(this->clusters, clusters_lengthT * sizeof(mesh_msgs::MeshFaceCluster));
      clusters_length = clusters_lengthT;
      for( uint32_t i = 0; i < clusters_length; i++){
      offset += this->st_clusters.deserialize(inbuffer + offset);
        memcpy( &(this->clusters[i]), &(this->st_clusters), sizeof(mesh_msgs::MeshFaceCluster));
      }
      uint32_t materials_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->materials_length);
      if(materials_lengthT > materials_length)
        this->materials = (mesh_msgs::MeshMaterial*)realloc(this->materials, materials_lengthT * sizeof(mesh_msgs::MeshMaterial));
      materials_length = materials_lengthT;
      for( uint32_t i = 0; i < materials_length; i++){
      offset += this->st_materials.deserialize(inbuffer + offset);
        memcpy( &(this->materials[i]), &(this->st_materials), sizeof(mesh_msgs::MeshMaterial));
      }
      uint32_t cluster_materials_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cluster_materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cluster_materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cluster_materials_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cluster_materials_length);
      if(cluster_materials_lengthT > cluster_materials_length)
        this->cluster_materials = (uint32_t*)realloc(this->cluster_materials, cluster_materials_lengthT * sizeof(uint32_t));
      cluster_materials_length = cluster_materials_lengthT;
      for( uint32_t i = 0; i < cluster_materials_length; i++){
      this->st_cluster_materials =  ((uint32_t) (*(inbuffer + offset)));
      this->st_cluster_materials |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_cluster_materials |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_cluster_materials |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_cluster_materials);
        memcpy( &(this->cluster_materials[i]), &(this->st_cluster_materials), sizeof(uint32_t));
      }
      uint32_t vertex_tex_coords_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertex_tex_coords_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertex_tex_coords_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertex_tex_coords_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertex_tex_coords_length);
      if(vertex_tex_coords_lengthT > vertex_tex_coords_length)
        this->vertex_tex_coords = (mesh_msgs::MeshVertexTexCoords*)realloc(this->vertex_tex_coords, vertex_tex_coords_lengthT * sizeof(mesh_msgs::MeshVertexTexCoords));
      vertex_tex_coords_length = vertex_tex_coords_lengthT;
      for( uint32_t i = 0; i < vertex_tex_coords_length; i++){
      offset += this->st_vertex_tex_coords.deserialize(inbuffer + offset);
        memcpy( &(this->vertex_tex_coords[i]), &(this->st_vertex_tex_coords), sizeof(mesh_msgs::MeshVertexTexCoords));
      }
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshMaterials"; };
    virtual const char * getMD5() override { return "e151c9a065aae90d545559129a79a70a"; };

  };

}
#endif
