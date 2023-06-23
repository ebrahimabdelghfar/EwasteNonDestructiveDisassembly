#ifndef _ROS_rm_msgs_EngineerFeedback_h
#define _ROS_rm_msgs_EngineerFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

  class EngineerFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _total_steps_type;
      _total_steps_type total_steps;
      typedef uint8_t _finished_step_type;
      _finished_step_type finished_step;
      typedef const char* _current_step_type;
      _current_step_type current_step;

    EngineerFeedback():
      total_steps(0),
      finished_step(0),
      current_step("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->total_steps >> (8 * 0)) & 0xFF;
      offset += sizeof(this->total_steps);
      *(outbuffer + offset + 0) = (this->finished_step >> (8 * 0)) & 0xFF;
      offset += sizeof(this->finished_step);
      uint32_t length_current_step = strlen(this->current_step);
      varToArr(outbuffer + offset, length_current_step);
      offset += 4;
      memcpy(outbuffer + offset, this->current_step, length_current_step);
      offset += length_current_step;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->total_steps =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->total_steps);
      this->finished_step =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->finished_step);
      uint32_t length_current_step;
      arrToVar(length_current_step, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_step; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_step-1]=0;
      this->current_step = (char *)(inbuffer + offset-1);
      offset += length_current_step;
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/EngineerFeedback"; };
    virtual const char * getMD5() override { return "87397c03e34e8b8835ff0de452ee02e3"; };

  };

}
#endif
