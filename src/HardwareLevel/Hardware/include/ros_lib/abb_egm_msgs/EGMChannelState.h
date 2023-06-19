#ifndef _ROS_abb_egm_msgs_EGMChannelState_h
#define _ROS_abb_egm_msgs_EGMChannelState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_egm_msgs
{

  class EGMChannelState : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _active_type;
      _active_type active;
      typedef bool _egm_convergence_met_type;
      _egm_convergence_met_type egm_convergence_met;
      typedef uint8_t _egm_client_state_type;
      _egm_client_state_type egm_client_state;
      typedef uint8_t _motor_state_type;
      _motor_state_type motor_state;
      typedef uint8_t _rapid_execution_state_type;
      _rapid_execution_state_type rapid_execution_state;
      typedef double _utilization_rate_type;
      _utilization_rate_type utilization_rate;
      enum { EGM_UNDEFINED =  1 };
      enum { EGM_ERROR =  2 };
      enum { EGM_STOPPED =  3 };
      enum { EGM_RUNNING =  4 };
      enum { MOTORS_UNDEFINED =  1 };
      enum { MOTORS_ON =  2 };
      enum { MOTORS_OFF =  3 };
      enum { RAPID_UNDEFINED =  1 };
      enum { RAPID_STOPPED =  2 };
      enum { RAPID_RUNNING =  3 };

    EGMChannelState():
      name(""),
      active(0),
      egm_convergence_met(0),
      egm_client_state(0),
      motor_state(0),
      rapid_execution_state(0),
      utilization_rate(0)
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
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      union {
        bool real;
        uint8_t base;
      } u_egm_convergence_met;
      u_egm_convergence_met.real = this->egm_convergence_met;
      *(outbuffer + offset + 0) = (u_egm_convergence_met.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->egm_convergence_met);
      *(outbuffer + offset + 0) = (this->egm_client_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->egm_client_state);
      *(outbuffer + offset + 0) = (this->motor_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_state);
      *(outbuffer + offset + 0) = (this->rapid_execution_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rapid_execution_state);
      union {
        double real;
        uint64_t base;
      } u_utilization_rate;
      u_utilization_rate.real = this->utilization_rate;
      *(outbuffer + offset + 0) = (u_utilization_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_utilization_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_utilization_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_utilization_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_utilization_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_utilization_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_utilization_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_utilization_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->utilization_rate);
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
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
      union {
        bool real;
        uint8_t base;
      } u_egm_convergence_met;
      u_egm_convergence_met.base = 0;
      u_egm_convergence_met.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->egm_convergence_met = u_egm_convergence_met.real;
      offset += sizeof(this->egm_convergence_met);
      this->egm_client_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->egm_client_state);
      this->motor_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_state);
      this->rapid_execution_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rapid_execution_state);
      union {
        double real;
        uint64_t base;
      } u_utilization_rate;
      u_utilization_rate.base = 0;
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_utilization_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->utilization_rate = u_utilization_rate.real;
      offset += sizeof(this->utilization_rate);
     return offset;
    }

    virtual const char * getType() override { return "abb_egm_msgs/EGMChannelState"; };
    virtual const char * getMD5() override { return "bc28749df58cd58b7299c4217fd9899f"; };

  };

}
#endif
