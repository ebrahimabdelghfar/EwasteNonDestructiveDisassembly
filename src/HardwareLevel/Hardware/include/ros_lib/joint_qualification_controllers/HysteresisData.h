#ifndef _ROS_joint_qualification_controllers_HysteresisData_h
#define _ROS_joint_qualification_controllers_HysteresisData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace joint_qualification_controllers
{

  class HysteresisData : public ros::Msg
  {
    public:
      typedef const char* _joint_name_type;
      _joint_name_type joint_name;
      uint32_t time_up_length;
      typedef float _time_up_type;
      _time_up_type st_time_up;
      _time_up_type * time_up;
      uint32_t effort_up_length;
      typedef float _effort_up_type;
      _effort_up_type st_effort_up;
      _effort_up_type * effort_up;
      uint32_t position_up_length;
      typedef float _position_up_type;
      _position_up_type st_position_up;
      _position_up_type * position_up;
      uint32_t velocity_up_length;
      typedef float _velocity_up_type;
      _velocity_up_type st_velocity_up;
      _velocity_up_type * velocity_up;
      uint32_t time_down_length;
      typedef float _time_down_type;
      _time_down_type st_time_down;
      _time_down_type * time_down;
      uint32_t effort_down_length;
      typedef float _effort_down_type;
      _effort_down_type st_effort_down;
      _effort_down_type * effort_down;
      uint32_t position_down_length;
      typedef float _position_down_type;
      _position_down_type st_position_down;
      _position_down_type * position_down;
      uint32_t velocity_down_length;
      typedef float _velocity_down_type;
      _velocity_down_type st_velocity_down;
      _velocity_down_type * velocity_down;
      uint32_t arg_name_length;
      typedef char* _arg_name_type;
      _arg_name_type st_arg_name;
      _arg_name_type * arg_name;
      uint32_t arg_value_length;
      typedef float _arg_value_type;
      _arg_value_type st_arg_value;
      _arg_value_type * arg_value;

    HysteresisData():
      joint_name(""),
      time_up_length(0), st_time_up(), time_up(nullptr),
      effort_up_length(0), st_effort_up(), effort_up(nullptr),
      position_up_length(0), st_position_up(), position_up(nullptr),
      velocity_up_length(0), st_velocity_up(), velocity_up(nullptr),
      time_down_length(0), st_time_down(), time_down(nullptr),
      effort_down_length(0), st_effort_down(), effort_down(nullptr),
      position_down_length(0), st_position_down(), position_down(nullptr),
      velocity_down_length(0), st_velocity_down(), velocity_down(nullptr),
      arg_name_length(0), st_arg_name(), arg_name(nullptr),
      arg_value_length(0), st_arg_value(), arg_value(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      varToArr(outbuffer + offset, length_joint_name);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      *(outbuffer + offset + 0) = (this->time_up_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_up_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_up_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_up_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_up_length);
      for( uint32_t i = 0; i < time_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_time_upi;
      u_time_upi.real = this->time_up[i];
      *(outbuffer + offset + 0) = (u_time_upi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_upi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_upi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_upi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_up[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_up_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_up_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_up_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_up_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_up_length);
      for( uint32_t i = 0; i < effort_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_effort_upi;
      u_effort_upi.real = this->effort_up[i];
      *(outbuffer + offset + 0) = (u_effort_upi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effort_upi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effort_upi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effort_upi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_up[i]);
      }
      *(outbuffer + offset + 0) = (this->position_up_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_up_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_up_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_up_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_up_length);
      for( uint32_t i = 0; i < position_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_position_upi;
      u_position_upi.real = this->position_up[i];
      *(outbuffer + offset + 0) = (u_position_upi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_upi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_upi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_upi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_up[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_up_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_up_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_up_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_up_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_up_length);
      for( uint32_t i = 0; i < velocity_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_velocity_upi;
      u_velocity_upi.real = this->velocity_up[i];
      *(outbuffer + offset + 0) = (u_velocity_upi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_upi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_upi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_upi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_up[i]);
      }
      *(outbuffer + offset + 0) = (this->time_down_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_down_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_down_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_down_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_down_length);
      for( uint32_t i = 0; i < time_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_time_downi;
      u_time_downi.real = this->time_down[i];
      *(outbuffer + offset + 0) = (u_time_downi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_downi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_downi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_downi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_down[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_down_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_down_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_down_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_down_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_down_length);
      for( uint32_t i = 0; i < effort_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_effort_downi;
      u_effort_downi.real = this->effort_down[i];
      *(outbuffer + offset + 0) = (u_effort_downi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effort_downi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effort_downi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effort_downi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_down[i]);
      }
      *(outbuffer + offset + 0) = (this->position_down_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_down_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_down_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_down_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_down_length);
      for( uint32_t i = 0; i < position_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_position_downi;
      u_position_downi.real = this->position_down[i];
      *(outbuffer + offset + 0) = (u_position_downi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_downi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_downi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_downi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_down[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_down_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_down_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_down_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_down_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_down_length);
      for( uint32_t i = 0; i < velocity_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_velocity_downi;
      u_velocity_downi.real = this->velocity_down[i];
      *(outbuffer + offset + 0) = (u_velocity_downi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_downi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_downi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_downi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_down[i]);
      }
      *(outbuffer + offset + 0) = (this->arg_name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arg_name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arg_name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arg_name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg_name_length);
      for( uint32_t i = 0; i < arg_name_length; i++){
      uint32_t length_arg_namei = strlen(this->arg_name[i]);
      varToArr(outbuffer + offset, length_arg_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->arg_name[i], length_arg_namei);
      offset += length_arg_namei;
      }
      *(outbuffer + offset + 0) = (this->arg_value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->arg_value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->arg_value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->arg_value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg_value_length);
      for( uint32_t i = 0; i < arg_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_arg_valuei;
      u_arg_valuei.real = this->arg_value[i];
      *(outbuffer + offset + 0) = (u_arg_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arg_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arg_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arg_valuei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg_value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_joint_name;
      arrToVar(length_joint_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      uint32_t time_up_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_up_length);
      if(time_up_lengthT > time_up_length)
        this->time_up = (float*)realloc(this->time_up, time_up_lengthT * sizeof(float));
      time_up_length = time_up_lengthT;
      for( uint32_t i = 0; i < time_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_time_up;
      u_st_time_up.base = 0;
      u_st_time_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_time_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_time_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_time_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_time_up = u_st_time_up.real;
      offset += sizeof(this->st_time_up);
        memcpy( &(this->time_up[i]), &(this->st_time_up), sizeof(float));
      }
      uint32_t effort_up_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_up_length);
      if(effort_up_lengthT > effort_up_length)
        this->effort_up = (float*)realloc(this->effort_up, effort_up_lengthT * sizeof(float));
      effort_up_length = effort_up_lengthT;
      for( uint32_t i = 0; i < effort_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_effort_up;
      u_st_effort_up.base = 0;
      u_st_effort_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_effort_up = u_st_effort_up.real;
      offset += sizeof(this->st_effort_up);
        memcpy( &(this->effort_up[i]), &(this->st_effort_up), sizeof(float));
      }
      uint32_t position_up_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_up_length);
      if(position_up_lengthT > position_up_length)
        this->position_up = (float*)realloc(this->position_up, position_up_lengthT * sizeof(float));
      position_up_length = position_up_lengthT;
      for( uint32_t i = 0; i < position_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_position_up;
      u_st_position_up.base = 0;
      u_st_position_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_position_up = u_st_position_up.real;
      offset += sizeof(this->st_position_up);
        memcpy( &(this->position_up[i]), &(this->st_position_up), sizeof(float));
      }
      uint32_t velocity_up_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_up_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_up_length);
      if(velocity_up_lengthT > velocity_up_length)
        this->velocity_up = (float*)realloc(this->velocity_up, velocity_up_lengthT * sizeof(float));
      velocity_up_length = velocity_up_lengthT;
      for( uint32_t i = 0; i < velocity_up_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_velocity_up;
      u_st_velocity_up.base = 0;
      u_st_velocity_up.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity_up.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocity_up.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocity_up.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_velocity_up = u_st_velocity_up.real;
      offset += sizeof(this->st_velocity_up);
        memcpy( &(this->velocity_up[i]), &(this->st_velocity_up), sizeof(float));
      }
      uint32_t time_down_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_down_length);
      if(time_down_lengthT > time_down_length)
        this->time_down = (float*)realloc(this->time_down, time_down_lengthT * sizeof(float));
      time_down_length = time_down_lengthT;
      for( uint32_t i = 0; i < time_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_time_down;
      u_st_time_down.base = 0;
      u_st_time_down.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_time_down.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_time_down.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_time_down.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_time_down = u_st_time_down.real;
      offset += sizeof(this->st_time_down);
        memcpy( &(this->time_down[i]), &(this->st_time_down), sizeof(float));
      }
      uint32_t effort_down_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_down_length);
      if(effort_down_lengthT > effort_down_length)
        this->effort_down = (float*)realloc(this->effort_down, effort_down_lengthT * sizeof(float));
      effort_down_length = effort_down_lengthT;
      for( uint32_t i = 0; i < effort_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_effort_down;
      u_st_effort_down.base = 0;
      u_st_effort_down.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort_down.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort_down.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort_down.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_effort_down = u_st_effort_down.real;
      offset += sizeof(this->st_effort_down);
        memcpy( &(this->effort_down[i]), &(this->st_effort_down), sizeof(float));
      }
      uint32_t position_down_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_down_length);
      if(position_down_lengthT > position_down_length)
        this->position_down = (float*)realloc(this->position_down, position_down_lengthT * sizeof(float));
      position_down_length = position_down_lengthT;
      for( uint32_t i = 0; i < position_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_position_down;
      u_st_position_down.base = 0;
      u_st_position_down.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position_down.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position_down.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position_down.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_position_down = u_st_position_down.real;
      offset += sizeof(this->st_position_down);
        memcpy( &(this->position_down[i]), &(this->st_position_down), sizeof(float));
      }
      uint32_t velocity_down_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_down_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_down_length);
      if(velocity_down_lengthT > velocity_down_length)
        this->velocity_down = (float*)realloc(this->velocity_down, velocity_down_lengthT * sizeof(float));
      velocity_down_length = velocity_down_lengthT;
      for( uint32_t i = 0; i < velocity_down_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_velocity_down;
      u_st_velocity_down.base = 0;
      u_st_velocity_down.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity_down.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocity_down.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocity_down.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_velocity_down = u_st_velocity_down.real;
      offset += sizeof(this->st_velocity_down);
        memcpy( &(this->velocity_down[i]), &(this->st_velocity_down), sizeof(float));
      }
      uint32_t arg_name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      arg_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      arg_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      arg_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->arg_name_length);
      if(arg_name_lengthT > arg_name_length)
        this->arg_name = (char**)realloc(this->arg_name, arg_name_lengthT * sizeof(char*));
      arg_name_length = arg_name_lengthT;
      for( uint32_t i = 0; i < arg_name_length; i++){
      uint32_t length_st_arg_name;
      arrToVar(length_st_arg_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_arg_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_arg_name-1]=0;
      this->st_arg_name = (char *)(inbuffer + offset-1);
      offset += length_st_arg_name;
        memcpy( &(this->arg_name[i]), &(this->st_arg_name), sizeof(char*));
      }
      uint32_t arg_value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      arg_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      arg_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      arg_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->arg_value_length);
      if(arg_value_lengthT > arg_value_length)
        this->arg_value = (float*)realloc(this->arg_value, arg_value_lengthT * sizeof(float));
      arg_value_length = arg_value_lengthT;
      for( uint32_t i = 0; i < arg_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_arg_value;
      u_st_arg_value.base = 0;
      u_st_arg_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_arg_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_arg_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_arg_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_arg_value = u_st_arg_value.real;
      offset += sizeof(this->st_arg_value);
        memcpy( &(this->arg_value[i]), &(this->st_arg_value), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/HysteresisData"; };
    virtual const char * getMD5() override { return "55018edece2f193bc97f016db04a871b"; };

  };

}
#endif
