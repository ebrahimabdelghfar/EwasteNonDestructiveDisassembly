#ifndef _ROS_mesh_msgs_VectorField_h
#define _ROS_mesh_msgs_VectorField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace mesh_msgs
{

  class VectorField : public ros::Msg
  {
    public:
      uint32_t positions_length;
      typedef geometry_msgs::Point _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      uint32_t vectors_length;
      typedef geometry_msgs::Vector3 _vectors_type;
      _vectors_type st_vectors;
      _vectors_type * vectors;

    VectorField():
      positions_length(0), st_positions(), positions(nullptr),
      vectors_length(0), st_vectors(), vectors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->positions[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vectors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vectors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vectors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vectors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectors_length);
      for( uint32_t i = 0; i < vectors_length; i++){
      offset += this->vectors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (geometry_msgs::Point*)realloc(this->positions, positions_lengthT * sizeof(geometry_msgs::Point));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->st_positions.deserialize(inbuffer + offset);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(geometry_msgs::Point));
      }
      uint32_t vectors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vectors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vectors_length);
      if(vectors_lengthT > vectors_length)
        this->vectors = (geometry_msgs::Vector3*)realloc(this->vectors, vectors_lengthT * sizeof(geometry_msgs::Vector3));
      vectors_length = vectors_lengthT;
      for( uint32_t i = 0; i < vectors_length; i++){
      offset += this->st_vectors.deserialize(inbuffer + offset);
        memcpy( &(this->vectors[i]), &(this->st_vectors), sizeof(geometry_msgs::Vector3));
      }
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/VectorField"; };
    virtual const char * getMD5() override { return "9da8d62df10048ede4a91e419a35679d"; };

  };

}
#endif
