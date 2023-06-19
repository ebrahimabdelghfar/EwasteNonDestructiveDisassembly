#ifndef _ROS_joint_qualification_controllers_CounterbalanceTestData_h
#define _ROS_joint_qualification_controllers_CounterbalanceTestData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/CBRunData.h"

namespace joint_qualification_controllers
{

  class CounterbalanceTestData : public ros::Msg
  {
    public:
      typedef const char* _lift_joint_type;
      _lift_joint_type lift_joint;
      typedef const char* _flex_joint_type;
      _flex_joint_type flex_joint;
      typedef float _lift_amplitude_type;
      _lift_amplitude_type lift_amplitude;
      typedef float _flex_amplitude_type;
      _flex_amplitude_type flex_amplitude;
      typedef bool _timeout_hit_type;
      _timeout_hit_type timeout_hit;
      typedef bool _flex_test_type;
      _flex_test_type flex_test;
      uint32_t arg_name_length;
      typedef char* _arg_name_type;
      _arg_name_type st_arg_name;
      _arg_name_type * arg_name;
      uint32_t arg_value_length;
      typedef float _arg_value_type;
      _arg_value_type st_arg_value;
      _arg_value_type * arg_value;
      uint32_t lift_data_length;
      typedef joint_qualification_controllers::CBRunData _lift_data_type;
      _lift_data_type st_lift_data;
      _lift_data_type * lift_data;

    CounterbalanceTestData():
      lift_joint(""),
      flex_joint(""),
      lift_amplitude(0),
      flex_amplitude(0),
      timeout_hit(0),
      flex_test(0),
      arg_name_length(0), st_arg_name(), arg_name(nullptr),
      arg_value_length(0), st_arg_value(), arg_value(nullptr),
      lift_data_length(0), st_lift_data(), lift_data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_lift_joint = strlen(this->lift_joint);
      varToArr(outbuffer + offset, length_lift_joint);
      offset += 4;
      memcpy(outbuffer + offset, this->lift_joint, length_lift_joint);
      offset += length_lift_joint;
      uint32_t length_flex_joint = strlen(this->flex_joint);
      varToArr(outbuffer + offset, length_flex_joint);
      offset += 4;
      memcpy(outbuffer + offset, this->flex_joint, length_flex_joint);
      offset += length_flex_joint;
      union {
        float real;
        uint32_t base;
      } u_lift_amplitude;
      u_lift_amplitude.real = this->lift_amplitude;
      *(outbuffer + offset + 0) = (u_lift_amplitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lift_amplitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lift_amplitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lift_amplitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lift_amplitude);
      union {
        float real;
        uint32_t base;
      } u_flex_amplitude;
      u_flex_amplitude.real = this->flex_amplitude;
      *(outbuffer + offset + 0) = (u_flex_amplitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flex_amplitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flex_amplitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flex_amplitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flex_amplitude);
      union {
        bool real;
        uint8_t base;
      } u_timeout_hit;
      u_timeout_hit.real = this->timeout_hit;
      *(outbuffer + offset + 0) = (u_timeout_hit.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->timeout_hit);
      union {
        bool real;
        uint8_t base;
      } u_flex_test;
      u_flex_test.real = this->flex_test;
      *(outbuffer + offset + 0) = (u_flex_test.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flex_test);
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
      *(outbuffer + offset + 0) = (this->lift_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lift_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lift_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lift_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lift_data_length);
      for( uint32_t i = 0; i < lift_data_length; i++){
      offset += this->lift_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_lift_joint;
      arrToVar(length_lift_joint, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lift_joint; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lift_joint-1]=0;
      this->lift_joint = (char *)(inbuffer + offset-1);
      offset += length_lift_joint;
      uint32_t length_flex_joint;
      arrToVar(length_flex_joint, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_flex_joint; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_flex_joint-1]=0;
      this->flex_joint = (char *)(inbuffer + offset-1);
      offset += length_flex_joint;
      union {
        float real;
        uint32_t base;
      } u_lift_amplitude;
      u_lift_amplitude.base = 0;
      u_lift_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lift_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lift_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lift_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lift_amplitude = u_lift_amplitude.real;
      offset += sizeof(this->lift_amplitude);
      union {
        float real;
        uint32_t base;
      } u_flex_amplitude;
      u_flex_amplitude.base = 0;
      u_flex_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flex_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flex_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flex_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flex_amplitude = u_flex_amplitude.real;
      offset += sizeof(this->flex_amplitude);
      union {
        bool real;
        uint8_t base;
      } u_timeout_hit;
      u_timeout_hit.base = 0;
      u_timeout_hit.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->timeout_hit = u_timeout_hit.real;
      offset += sizeof(this->timeout_hit);
      union {
        bool real;
        uint8_t base;
      } u_flex_test;
      u_flex_test.base = 0;
      u_flex_test.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flex_test = u_flex_test.real;
      offset += sizeof(this->flex_test);
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
      uint32_t lift_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lift_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lift_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lift_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lift_data_length);
      if(lift_data_lengthT > lift_data_length)
        this->lift_data = (joint_qualification_controllers::CBRunData*)realloc(this->lift_data, lift_data_lengthT * sizeof(joint_qualification_controllers::CBRunData));
      lift_data_length = lift_data_lengthT;
      for( uint32_t i = 0; i < lift_data_length; i++){
      offset += this->st_lift_data.deserialize(inbuffer + offset);
        memcpy( &(this->lift_data[i]), &(this->st_lift_data), sizeof(joint_qualification_controllers::CBRunData));
      }
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/CounterbalanceTestData"; };
    virtual const char * getMD5() override { return "ab80d40971aa9176fd2c9fb75aeb93cf"; };

  };

}
#endif
