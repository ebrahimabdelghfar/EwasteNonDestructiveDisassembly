#ifndef _ROS_abb_rapid_sm_addin_msgs_RuntimeState_h
#define _ROS_abb_rapid_sm_addin_msgs_RuntimeState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "abb_rapid_sm_addin_msgs/StateMachineState.h"

namespace abb_rapid_sm_addin_msgs
{

  class RuntimeState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t state_machines_length;
      typedef abb_rapid_sm_addin_msgs::StateMachineState _state_machines_type;
      _state_machines_type st_state_machines;
      _state_machines_type * state_machines;

    RuntimeState():
      header(),
      state_machines_length(0), st_state_machines(), state_machines(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->state_machines_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_machines_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_machines_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_machines_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_machines_length);
      for( uint32_t i = 0; i < state_machines_length; i++){
      offset += this->state_machines[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t state_machines_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      state_machines_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      state_machines_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      state_machines_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->state_machines_length);
      if(state_machines_lengthT > state_machines_length)
        this->state_machines = (abb_rapid_sm_addin_msgs::StateMachineState*)realloc(this->state_machines, state_machines_lengthT * sizeof(abb_rapid_sm_addin_msgs::StateMachineState));
      state_machines_length = state_machines_lengthT;
      for( uint32_t i = 0; i < state_machines_length; i++){
      offset += this->st_state_machines.deserialize(inbuffer + offset);
        memcpy( &(this->state_machines[i]), &(this->st_state_machines), sizeof(abb_rapid_sm_addin_msgs::StateMachineState));
      }
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/RuntimeState"; };
    virtual const char * getMD5() override { return "1f803b084f80e27cb1a45c04dc77c6e7"; };

  };

}
#endif
