#ifndef _ROS_moveit_task_constructor_msgs_StageStatistics_h
#define _ROS_moveit_task_constructor_msgs_StageStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_task_constructor_msgs
{

  class StageStatistics : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      uint32_t solved_length;
      typedef uint32_t _solved_type;
      _solved_type st_solved;
      _solved_type * solved;
      uint32_t failed_length;
      typedef uint32_t _failed_type;
      _failed_type st_failed;
      _failed_type * failed;
      typedef uint32_t _num_failed_type;
      _num_failed_type num_failed;
      typedef double _total_compute_time_type;
      _total_compute_time_type total_compute_time;

    StageStatistics():
      id(0),
      solved_length(0), st_solved(), solved(nullptr),
      failed_length(0), st_failed(), failed(nullptr),
      num_failed(0),
      total_compute_time(0)
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
      *(outbuffer + offset + 0) = (this->solved_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solved_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solved_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solved_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solved_length);
      for( uint32_t i = 0; i < solved_length; i++){
      *(outbuffer + offset + 0) = (this->solved[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solved[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solved[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solved[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solved[i]);
      }
      *(outbuffer + offset + 0) = (this->failed_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->failed_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->failed_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->failed_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->failed_length);
      for( uint32_t i = 0; i < failed_length; i++){
      *(outbuffer + offset + 0) = (this->failed[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->failed[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->failed[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->failed[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->failed[i]);
      }
      *(outbuffer + offset + 0) = (this->num_failed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_failed >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_failed >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_failed >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_failed);
      union {
        double real;
        uint64_t base;
      } u_total_compute_time;
      u_total_compute_time.real = this->total_compute_time;
      *(outbuffer + offset + 0) = (u_total_compute_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_compute_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_compute_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_compute_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_total_compute_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_total_compute_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_total_compute_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_total_compute_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->total_compute_time);
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
      uint32_t solved_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      solved_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      solved_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      solved_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->solved_length);
      if(solved_lengthT > solved_length)
        this->solved = (uint32_t*)realloc(this->solved, solved_lengthT * sizeof(uint32_t));
      solved_length = solved_lengthT;
      for( uint32_t i = 0; i < solved_length; i++){
      this->st_solved =  ((uint32_t) (*(inbuffer + offset)));
      this->st_solved |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_solved |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_solved |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_solved);
        memcpy( &(this->solved[i]), &(this->st_solved), sizeof(uint32_t));
      }
      uint32_t failed_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      failed_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      failed_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      failed_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->failed_length);
      if(failed_lengthT > failed_length)
        this->failed = (uint32_t*)realloc(this->failed, failed_lengthT * sizeof(uint32_t));
      failed_length = failed_lengthT;
      for( uint32_t i = 0; i < failed_length; i++){
      this->st_failed =  ((uint32_t) (*(inbuffer + offset)));
      this->st_failed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_failed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_failed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_failed);
        memcpy( &(this->failed[i]), &(this->st_failed), sizeof(uint32_t));
      }
      this->num_failed =  ((uint32_t) (*(inbuffer + offset)));
      this->num_failed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_failed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_failed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_failed);
      union {
        double real;
        uint64_t base;
      } u_total_compute_time;
      u_total_compute_time.base = 0;
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_total_compute_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->total_compute_time = u_total_compute_time.real;
      offset += sizeof(this->total_compute_time);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/StageStatistics"; };
    virtual const char * getMD5() override { return "a3065cf7e54eaf169fb84102f63f1ac2"; };

  };

}
#endif
