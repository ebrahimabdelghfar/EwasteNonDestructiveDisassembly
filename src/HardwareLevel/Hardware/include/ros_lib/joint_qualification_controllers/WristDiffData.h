#ifndef _ROS_joint_qualification_controllers_WristDiffData_h
#define _ROS_joint_qualification_controllers_WristDiffData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/WristRollTurn.h"

namespace joint_qualification_controllers
{

  class WristDiffData : public ros::Msg
  {
    public:
      typedef const char* _flex_joint_type;
      _flex_joint_type flex_joint;
      typedef const char* _roll_joint_type;
      _roll_joint_type roll_joint;
      uint32_t flex_pid_length;
      typedef float _flex_pid_type;
      _flex_pid_type st_flex_pid;
      _flex_pid_type * flex_pid;
      uint32_t roll_pid_length;
      typedef float _roll_pid_type;
      _roll_pid_type st_roll_pid;
      _roll_pid_type * roll_pid;
      uint32_t arg_name_length;
      typedef char* _arg_name_type;
      _arg_name_type st_arg_name;
      _arg_name_type * arg_name;
      uint32_t arg_value_length;
      typedef float _arg_value_type;
      _arg_value_type st_arg_value;
      _arg_value_type * arg_value;
      typedef joint_qualification_controllers::WristRollTurn _left_turn_type;
      _left_turn_type left_turn;
      typedef joint_qualification_controllers::WristRollTurn _right_turn_type;
      _right_turn_type right_turn;
      typedef bool _timeout_type;
      _timeout_type timeout;

    WristDiffData():
      flex_joint(""),
      roll_joint(""),
      flex_pid_length(0), st_flex_pid(), flex_pid(nullptr),
      roll_pid_length(0), st_roll_pid(), roll_pid(nullptr),
      arg_name_length(0), st_arg_name(), arg_name(nullptr),
      arg_value_length(0), st_arg_value(), arg_value(nullptr),
      left_turn(),
      right_turn(),
      timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_flex_joint = strlen(this->flex_joint);
      varToArr(outbuffer + offset, length_flex_joint);
      offset += 4;
      memcpy(outbuffer + offset, this->flex_joint, length_flex_joint);
      offset += length_flex_joint;
      uint32_t length_roll_joint = strlen(this->roll_joint);
      varToArr(outbuffer + offset, length_roll_joint);
      offset += 4;
      memcpy(outbuffer + offset, this->roll_joint, length_roll_joint);
      offset += length_roll_joint;
      *(outbuffer + offset + 0) = (this->flex_pid_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flex_pid_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flex_pid_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flex_pid_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flex_pid_length);
      for( uint32_t i = 0; i < flex_pid_length; i++){
      union {
        float real;
        uint32_t base;
      } u_flex_pidi;
      u_flex_pidi.real = this->flex_pid[i];
      *(outbuffer + offset + 0) = (u_flex_pidi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flex_pidi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flex_pidi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flex_pidi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flex_pid[i]);
      }
      *(outbuffer + offset + 0) = (this->roll_pid_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->roll_pid_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->roll_pid_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->roll_pid_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_pid_length);
      for( uint32_t i = 0; i < roll_pid_length; i++){
      union {
        float real;
        uint32_t base;
      } u_roll_pidi;
      u_roll_pidi.real = this->roll_pid[i];
      *(outbuffer + offset + 0) = (u_roll_pidi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_pidi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_pidi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_pidi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_pid[i]);
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
      offset += this->left_turn.serialize(outbuffer + offset);
      offset += this->right_turn.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_flex_joint;
      arrToVar(length_flex_joint, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_flex_joint; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_flex_joint-1]=0;
      this->flex_joint = (char *)(inbuffer + offset-1);
      offset += length_flex_joint;
      uint32_t length_roll_joint;
      arrToVar(length_roll_joint, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_roll_joint; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_roll_joint-1]=0;
      this->roll_joint = (char *)(inbuffer + offset-1);
      offset += length_roll_joint;
      uint32_t flex_pid_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      flex_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      flex_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      flex_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->flex_pid_length);
      if(flex_pid_lengthT > flex_pid_length)
        this->flex_pid = (float*)realloc(this->flex_pid, flex_pid_lengthT * sizeof(float));
      flex_pid_length = flex_pid_lengthT;
      for( uint32_t i = 0; i < flex_pid_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_flex_pid;
      u_st_flex_pid.base = 0;
      u_st_flex_pid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_flex_pid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_flex_pid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_flex_pid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_flex_pid = u_st_flex_pid.real;
      offset += sizeof(this->st_flex_pid);
        memcpy( &(this->flex_pid[i]), &(this->st_flex_pid), sizeof(float));
      }
      uint32_t roll_pid_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      roll_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      roll_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      roll_pid_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->roll_pid_length);
      if(roll_pid_lengthT > roll_pid_length)
        this->roll_pid = (float*)realloc(this->roll_pid, roll_pid_lengthT * sizeof(float));
      roll_pid_length = roll_pid_lengthT;
      for( uint32_t i = 0; i < roll_pid_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_roll_pid;
      u_st_roll_pid.base = 0;
      u_st_roll_pid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_roll_pid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_roll_pid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_roll_pid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_roll_pid = u_st_roll_pid.real;
      offset += sizeof(this->st_roll_pid);
        memcpy( &(this->roll_pid[i]), &(this->st_roll_pid), sizeof(float));
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
      offset += this->left_turn.deserialize(inbuffer + offset);
      offset += this->right_turn.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/WristDiffData"; };
    virtual const char * getMD5() override { return "b5450bf7a09b17c68a893b9c02e710f1"; };

  };

}
#endif
