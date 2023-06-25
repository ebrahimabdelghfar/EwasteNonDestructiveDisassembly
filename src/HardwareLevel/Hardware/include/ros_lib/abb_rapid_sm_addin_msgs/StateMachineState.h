#ifndef _ROS_abb_rapid_sm_addin_msgs_StateMachineState_h
#define _ROS_abb_rapid_sm_addin_msgs_StateMachineState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_sm_addin_msgs
{

  class StateMachineState : public ros::Msg
  {
    public:
      typedef const char* _rapid_task_type;
      _rapid_task_type rapid_task;
      typedef uint8_t _sm_state_type;
      _sm_state_type sm_state;
      typedef uint8_t _egm_action_type;
      _egm_action_type egm_action;
      enum { SM_STATE_UNKNOWN =  1 };
      enum { SM_STATE_IDLE =  2 };
      enum { SM_STATE_INITIALIZE =  3 };
      enum { SM_STATE_RUN_RAPID_ROUTINE =  4 };
      enum { SM_STATE_RUN_EGM_ROUTINE =  5 };
      enum { EGM_ACTION_UNKNOWN =  1 };
      enum { EGM_ACTION_NONE =  2 };
      enum { EGM_ACTION_RUN_JOINT =  3 };
      enum { EGM_ACTION_RUN_POSE =  4 };
      enum { EGM_ACTION_STOP =  5 };
      enum { EGM_ACTION_START_STREAM =  6 };
      enum { EGM_ACTION_STOP_STREAM =  7 };

    StateMachineState():
      rapid_task(""),
      sm_state(0),
      egm_action(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_rapid_task = strlen(this->rapid_task);
      varToArr(outbuffer + offset, length_rapid_task);
      offset += 4;
      memcpy(outbuffer + offset, this->rapid_task, length_rapid_task);
      offset += length_rapid_task;
      *(outbuffer + offset + 0) = (this->sm_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sm_state);
      *(outbuffer + offset + 0) = (this->egm_action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->egm_action);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_rapid_task;
      arrToVar(length_rapid_task, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rapid_task; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rapid_task-1]=0;
      this->rapid_task = (char *)(inbuffer + offset-1);
      offset += length_rapid_task;
      this->sm_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sm_state);
      this->egm_action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->egm_action);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/StateMachineState"; };
    virtual const char * getMD5() override { return "de6354e383149183de9c15ab3d871c7b"; };

  };

}
#endif
