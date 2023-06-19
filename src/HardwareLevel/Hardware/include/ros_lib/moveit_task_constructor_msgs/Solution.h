#ifndef _ROS_moveit_task_constructor_msgs_Solution_h
#define _ROS_moveit_task_constructor_msgs_Solution_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_msgs/PlanningScene.h"
#include "moveit_task_constructor_msgs/SubSolution.h"
#include "moveit_task_constructor_msgs/SubTrajectory.h"

namespace moveit_task_constructor_msgs
{

  class Solution : public ros::Msg
  {
    public:
      typedef const char* _task_id_type;
      _task_id_type task_id;
      typedef moveit_msgs::PlanningScene _start_scene_type;
      _start_scene_type start_scene;
      uint32_t sub_solution_length;
      typedef moveit_task_constructor_msgs::SubSolution _sub_solution_type;
      _sub_solution_type st_sub_solution;
      _sub_solution_type * sub_solution;
      uint32_t sub_trajectory_length;
      typedef moveit_task_constructor_msgs::SubTrajectory _sub_trajectory_type;
      _sub_trajectory_type st_sub_trajectory;
      _sub_trajectory_type * sub_trajectory;

    Solution():
      task_id(""),
      start_scene(),
      sub_solution_length(0), st_sub_solution(), sub_solution(nullptr),
      sub_trajectory_length(0), st_sub_trajectory(), sub_trajectory(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_task_id = strlen(this->task_id);
      varToArr(outbuffer + offset, length_task_id);
      offset += 4;
      memcpy(outbuffer + offset, this->task_id, length_task_id);
      offset += length_task_id;
      offset += this->start_scene.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sub_solution_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_solution_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_solution_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_solution_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_solution_length);
      for( uint32_t i = 0; i < sub_solution_length; i++){
      offset += this->sub_solution[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->sub_trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_trajectory_length);
      for( uint32_t i = 0; i < sub_trajectory_length; i++){
      offset += this->sub_trajectory[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_task_id;
      arrToVar(length_task_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_id-1]=0;
      this->task_id = (char *)(inbuffer + offset-1);
      offset += length_task_id;
      offset += this->start_scene.deserialize(inbuffer + offset);
      uint32_t sub_solution_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sub_solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sub_solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sub_solution_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sub_solution_length);
      if(sub_solution_lengthT > sub_solution_length)
        this->sub_solution = (moveit_task_constructor_msgs::SubSolution*)realloc(this->sub_solution, sub_solution_lengthT * sizeof(moveit_task_constructor_msgs::SubSolution));
      sub_solution_length = sub_solution_lengthT;
      for( uint32_t i = 0; i < sub_solution_length; i++){
      offset += this->st_sub_solution.deserialize(inbuffer + offset);
        memcpy( &(this->sub_solution[i]), &(this->st_sub_solution), sizeof(moveit_task_constructor_msgs::SubSolution));
      }
      uint32_t sub_trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sub_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sub_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sub_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sub_trajectory_length);
      if(sub_trajectory_lengthT > sub_trajectory_length)
        this->sub_trajectory = (moveit_task_constructor_msgs::SubTrajectory*)realloc(this->sub_trajectory, sub_trajectory_lengthT * sizeof(moveit_task_constructor_msgs::SubTrajectory));
      sub_trajectory_length = sub_trajectory_lengthT;
      for( uint32_t i = 0; i < sub_trajectory_length; i++){
      offset += this->st_sub_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->sub_trajectory[i]), &(this->st_sub_trajectory), sizeof(moveit_task_constructor_msgs::SubTrajectory));
      }
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/Solution"; };
    virtual const char * getMD5() override { return "c39ab61e32ceb9321529cb6abf39d904"; };

  };

}
#endif
