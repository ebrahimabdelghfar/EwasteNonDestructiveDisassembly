#ifndef _ROS_moveit_task_constructor_msgs_SolutionInfo_h
#define _ROS_moveit_task_constructor_msgs_SolutionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/Marker.h"

namespace moveit_task_constructor_msgs
{

  class SolutionInfo : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef float _cost_type;
      _cost_type cost;
      typedef const char* _comment_type;
      _comment_type comment;
      typedef uint32_t _stage_id_type;
      _stage_id_type stage_id;
      uint32_t markers_length;
      typedef visualization_msgs::Marker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;

    SolutionInfo():
      id(0),
      cost(0),
      comment(""),
      stage_id(0),
      markers_length(0), st_markers(), markers(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_cost;
      u_cost.real = this->cost;
      *(outbuffer + offset + 0) = (u_cost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cost.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cost);
      uint32_t length_comment = strlen(this->comment);
      varToArr(outbuffer + offset, length_comment);
      offset += 4;
      memcpy(outbuffer + offset, this->comment, length_comment);
      offset += length_comment;
      *(outbuffer + offset + 0) = (this->stage_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stage_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stage_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stage_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stage_id);
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_cost;
      u_cost.base = 0;
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cost.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cost = u_cost.real;
      offset += sizeof(this->cost);
      uint32_t length_comment;
      arrToVar(length_comment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_comment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_comment-1]=0;
      this->comment = (char *)(inbuffer + offset-1);
      offset += length_comment;
      this->stage_id =  ((uint32_t) (*(inbuffer + offset)));
      this->stage_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stage_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stage_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stage_id);
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(markers_lengthT > markers_length)
        this->markers = (visualization_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(visualization_msgs::Marker));
      markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(visualization_msgs::Marker));
      }
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/SolutionInfo"; };
    virtual const char * getMD5() override { return "349cc436b667a16244a5d77757eec377"; };

  };

}
#endif
