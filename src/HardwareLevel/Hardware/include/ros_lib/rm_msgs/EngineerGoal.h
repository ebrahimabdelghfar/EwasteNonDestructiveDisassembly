#ifndef _ROS_rm_msgs_EngineerGoal_h
#define _ROS_rm_msgs_EngineerGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

  class EngineerGoal : public ros::Msg
  {
    public:
      typedef const char* _step_queue_name_type;
      _step_queue_name_type step_queue_name;

    EngineerGoal():
      step_queue_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_step_queue_name = strlen(this->step_queue_name);
      varToArr(outbuffer + offset, length_step_queue_name);
      offset += 4;
      memcpy(outbuffer + offset, this->step_queue_name, length_step_queue_name);
      offset += length_step_queue_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_step_queue_name;
      arrToVar(length_step_queue_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_step_queue_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_step_queue_name-1]=0;
      this->step_queue_name = (char *)(inbuffer + offset-1);
      offset += length_step_queue_name;
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/EngineerGoal"; };
    virtual const char * getMD5() override { return "e30ffeaaa0cfd516d274467b24b53a8a"; };

  };

}
#endif
