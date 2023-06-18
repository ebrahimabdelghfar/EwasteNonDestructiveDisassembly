#ifndef _ROS_moveit_task_constructor_msgs_TaskStatistics_h
#define _ROS_moveit_task_constructor_msgs_TaskStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/StageStatistics.h"

namespace moveit_task_constructor_msgs
{

  class TaskStatistics : public ros::Msg
  {
    public:
      typedef const char* _task_id_type;
      _task_id_type task_id;
      uint32_t stages_length;
      typedef moveit_task_constructor_msgs::StageStatistics _stages_type;
      _stages_type st_stages;
      _stages_type * stages;

    TaskStatistics():
      task_id(""),
      stages_length(0), st_stages(), stages(nullptr)
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
      *(outbuffer + offset + 0) = (this->stages_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stages_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stages_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stages_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stages_length);
      for( uint32_t i = 0; i < stages_length; i++){
      offset += this->stages[i].serialize(outbuffer + offset);
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
      uint32_t stages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stages_length);
      if(stages_lengthT > stages_length)
        this->stages = (moveit_task_constructor_msgs::StageStatistics*)realloc(this->stages, stages_lengthT * sizeof(moveit_task_constructor_msgs::StageStatistics));
      stages_length = stages_lengthT;
      for( uint32_t i = 0; i < stages_length; i++){
      offset += this->st_stages.deserialize(inbuffer + offset);
        memcpy( &(this->stages[i]), &(this->st_stages), sizeof(moveit_task_constructor_msgs::StageStatistics));
      }
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/TaskStatistics"; };
    virtual const char * getMD5() override { return "f18c50166b7446a7ec6179ed1d6aa3d1"; };

  };

}
#endif
