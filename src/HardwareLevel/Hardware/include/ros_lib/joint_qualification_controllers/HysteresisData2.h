#ifndef _ROS_joint_qualification_controllers_HysteresisData2_h
#define _ROS_joint_qualification_controllers_HysteresisData2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/HysteresisRun.h"

namespace joint_qualification_controllers
{

  class HysteresisData2 : public ros::Msg
  {
    public:
      typedef const char* _joint_name_type;
      _joint_name_type joint_name;
      uint32_t runs_length;
      typedef joint_qualification_controllers::HysteresisRun _runs_type;
      _runs_type st_runs;
      _runs_type * runs;
      uint32_t arg_name_length;
      typedef char* _arg_name_type;
      _arg_name_type st_arg_name;
      _arg_name_type * arg_name;
      uint32_t arg_value_length;
      typedef float _arg_value_type;
      _arg_value_type st_arg_value;
      _arg_value_type * arg_value;

    HysteresisData2():
      joint_name(""),
      runs_length(0), st_runs(), runs(nullptr),
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
      *(outbuffer + offset + 0) = (this->runs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->runs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->runs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->runs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->runs_length);
      for( uint32_t i = 0; i < runs_length; i++){
      offset += this->runs[i].serialize(outbuffer + offset);
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
      uint32_t runs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->runs_length);
      if(runs_lengthT > runs_length)
        this->runs = (joint_qualification_controllers::HysteresisRun*)realloc(this->runs, runs_lengthT * sizeof(joint_qualification_controllers::HysteresisRun));
      runs_length = runs_lengthT;
      for( uint32_t i = 0; i < runs_length; i++){
      offset += this->st_runs.deserialize(inbuffer + offset);
        memcpy( &(this->runs[i]), &(this->st_runs), sizeof(joint_qualification_controllers::HysteresisRun));
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

    virtual const char * getType() override { return "joint_qualification_controllers/HysteresisData2"; };
    virtual const char * getMD5() override { return "e58eacdd7f3ac3c02f9d494da1e59355"; };

  };

}
#endif
