#ifndef _ROS_mesh_msgs_MeshFaceCluster_h
#define _ROS_mesh_msgs_MeshFaceCluster_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mesh_msgs
{

  class MeshFaceCluster : public ros::Msg
  {
    public:
      uint32_t face_indices_length;
      typedef uint32_t _face_indices_type;
      _face_indices_type st_face_indices;
      _face_indices_type * face_indices;
      typedef const char* _label_type;
      _label_type label;

    MeshFaceCluster():
      face_indices_length(0), st_face_indices(), face_indices(nullptr),
      label("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->face_indices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->face_indices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->face_indices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->face_indices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->face_indices_length);
      for( uint32_t i = 0; i < face_indices_length; i++){
      *(outbuffer + offset + 0) = (this->face_indices[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->face_indices[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->face_indices[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->face_indices[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->face_indices[i]);
      }
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t face_indices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      face_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      face_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      face_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->face_indices_length);
      if(face_indices_lengthT > face_indices_length)
        this->face_indices = (uint32_t*)realloc(this->face_indices, face_indices_lengthT * sizeof(uint32_t));
      face_indices_length = face_indices_lengthT;
      for( uint32_t i = 0; i < face_indices_length; i++){
      this->st_face_indices =  ((uint32_t) (*(inbuffer + offset)));
      this->st_face_indices |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_face_indices |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_face_indices |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_face_indices);
        memcpy( &(this->face_indices[i]), &(this->st_face_indices), sizeof(uint32_t));
      }
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshFaceCluster"; };
    virtual const char * getMD5() override { return "9e0f40b9dcf1de10d00e57182c9d138f"; };

  };

}
#endif
