#ifndef _ROS_moveit_task_constructor_msgs_SubSolution_h
#define _ROS_moveit_task_constructor_msgs_SubSolution_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/SolutionInfo.h"

namespace moveit_task_constructor_msgs
{

  class SubSolution : public ros::Msg
  {
    public:
      typedef moveit_task_constructor_msgs::SolutionInfo _info_type;
      _info_type info;
      uint32_t sub_solution_id_length;
      typedef uint32_t _sub_solution_id_type;
      _sub_solution_id_type st_sub_solution_id;
      _sub_solution_id_type * sub_solution_id;

    SubSolution():
      info(),
      sub_solution_id_length(0), st_sub_solution_id(), sub_solution_id(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sub_solution_id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_solution_id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_solution_id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_solution_id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_solution_id_length);
      for( uint32_t i = 0; i < sub_solution_id_length; i++){
      *(outbuffer + offset + 0) = (this->sub_solution_id[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_solution_id[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_solution_id[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_solution_id[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_solution_id[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
      uint32_t sub_solution_id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sub_solution_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sub_solution_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sub_solution_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sub_solution_id_length);
      if(sub_solution_id_lengthT > sub_solution_id_length)
        this->sub_solution_id = (uint32_t*)realloc(this->sub_solution_id, sub_solution_id_lengthT * sizeof(uint32_t));
      sub_solution_id_length = sub_solution_id_lengthT;
      for( uint32_t i = 0; i < sub_solution_id_length; i++){
      this->st_sub_solution_id =  ((uint32_t) (*(inbuffer + offset)));
      this->st_sub_solution_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_sub_solution_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_sub_solution_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_sub_solution_id);
        memcpy( &(this->sub_solution_id[i]), &(this->st_sub_solution_id), sizeof(uint32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/SubSolution"; };
    virtual const char * getMD5() override { return "cad7989816e3b99e3abb2b6661af1df0"; };

  };

}
#endif
