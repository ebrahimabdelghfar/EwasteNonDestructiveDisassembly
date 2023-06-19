#ifndef _ROS_abb_robot_msgs_RAPIDTaskState_h
#define _ROS_abb_robot_msgs_RAPIDTaskState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

  class RAPIDTaskState : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _activated_type;
      _activated_type activated;
      typedef uint8_t _execution_state_type;
      _execution_state_type execution_state;
      typedef bool _motion_task_type;
      _motion_task_type motion_task;
      enum { EXECUTION_STATE_UNKNOWN =  1 };
      enum { EXECUTION_STATE_READY =  2 };
      enum { EXECUTION_STATE_STOPPED =  3 };
      enum { EXECUTION_STATE_STARTED =  4 };
      enum { EXECUTION_STATE_UNINITIALIZED =  5 };

    RAPIDTaskState():
      name(""),
      activated(0),
      execution_state(0),
      motion_task(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_activated;
      u_activated.real = this->activated;
      *(outbuffer + offset + 0) = (u_activated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activated);
      *(outbuffer + offset + 0) = (this->execution_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->execution_state);
      union {
        bool real;
        uint8_t base;
      } u_motion_task;
      u_motion_task.real = this->motion_task;
      *(outbuffer + offset + 0) = (u_motion_task.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motion_task);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_activated;
      u_activated.base = 0;
      u_activated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activated = u_activated.real;
      offset += sizeof(this->activated);
      this->execution_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->execution_state);
      union {
        bool real;
        uint8_t base;
      } u_motion_task;
      u_motion_task.base = 0;
      u_motion_task.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motion_task = u_motion_task.real;
      offset += sizeof(this->motion_task);
     return offset;
    }

    virtual const char * getType() override { return "abb_robot_msgs/RAPIDTaskState"; };
    virtual const char * getMD5() override { return "37a1a82a542dcaea43aef8b824e26614"; };

  };

}
#endif
