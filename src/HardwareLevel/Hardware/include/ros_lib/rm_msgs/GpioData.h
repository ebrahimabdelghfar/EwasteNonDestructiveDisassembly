#ifndef _ROS_rm_msgs_GpioData_h
#define _ROS_rm_msgs_GpioData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class GpioData : public ros::Msg
  {
    public:
      uint32_t gpio_name_length;
      typedef char* _gpio_name_type;
      _gpio_name_type st_gpio_name;
      _gpio_name_type * gpio_name;
      uint32_t gpio_state_length;
      typedef bool _gpio_state_type;
      _gpio_state_type st_gpio_state;
      _gpio_state_type * gpio_state;
      uint32_t gpio_type_length;
      typedef char* _gpio_type_type;
      _gpio_type_type st_gpio_type;
      _gpio_type_type * gpio_type;
      typedef std_msgs::Header _header_type;
      _header_type header;

    GpioData():
      gpio_name_length(0), st_gpio_name(), gpio_name(nullptr),
      gpio_state_length(0), st_gpio_state(), gpio_state(nullptr),
      gpio_type_length(0), st_gpio_type(), gpio_type(nullptr),
      header()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gpio_name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gpio_name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gpio_name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gpio_name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gpio_name_length);
      for( uint32_t i = 0; i < gpio_name_length; i++){
      uint32_t length_gpio_namei = strlen(this->gpio_name[i]);
      varToArr(outbuffer + offset, length_gpio_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->gpio_name[i], length_gpio_namei);
      offset += length_gpio_namei;
      }
      *(outbuffer + offset + 0) = (this->gpio_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gpio_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gpio_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gpio_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gpio_state_length);
      for( uint32_t i = 0; i < gpio_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_gpio_statei;
      u_gpio_statei.real = this->gpio_state[i];
      *(outbuffer + offset + 0) = (u_gpio_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gpio_state[i]);
      }
      *(outbuffer + offset + 0) = (this->gpio_type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gpio_type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gpio_type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gpio_type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gpio_type_length);
      for( uint32_t i = 0; i < gpio_type_length; i++){
      uint32_t length_gpio_typei = strlen(this->gpio_type[i]);
      varToArr(outbuffer + offset, length_gpio_typei);
      offset += 4;
      memcpy(outbuffer + offset, this->gpio_type[i], length_gpio_typei);
      offset += length_gpio_typei;
      }
      offset += this->header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t gpio_name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gpio_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gpio_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gpio_name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gpio_name_length);
      if(gpio_name_lengthT > gpio_name_length)
        this->gpio_name = (char**)realloc(this->gpio_name, gpio_name_lengthT * sizeof(char*));
      gpio_name_length = gpio_name_lengthT;
      for( uint32_t i = 0; i < gpio_name_length; i++){
      uint32_t length_st_gpio_name;
      arrToVar(length_st_gpio_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_gpio_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_gpio_name-1]=0;
      this->st_gpio_name = (char *)(inbuffer + offset-1);
      offset += length_st_gpio_name;
        memcpy( &(this->gpio_name[i]), &(this->st_gpio_name), sizeof(char*));
      }
      uint32_t gpio_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gpio_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gpio_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gpio_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gpio_state_length);
      if(gpio_state_lengthT > gpio_state_length)
        this->gpio_state = (bool*)realloc(this->gpio_state, gpio_state_lengthT * sizeof(bool));
      gpio_state_length = gpio_state_lengthT;
      for( uint32_t i = 0; i < gpio_state_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_gpio_state;
      u_st_gpio_state.base = 0;
      u_st_gpio_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_gpio_state = u_st_gpio_state.real;
      offset += sizeof(this->st_gpio_state);
        memcpy( &(this->gpio_state[i]), &(this->st_gpio_state), sizeof(bool));
      }
      uint32_t gpio_type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gpio_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gpio_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gpio_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gpio_type_length);
      if(gpio_type_lengthT > gpio_type_length)
        this->gpio_type = (char**)realloc(this->gpio_type, gpio_type_lengthT * sizeof(char*));
      gpio_type_length = gpio_type_lengthT;
      for( uint32_t i = 0; i < gpio_type_length; i++){
      uint32_t length_st_gpio_type;
      arrToVar(length_st_gpio_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_gpio_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_gpio_type-1]=0;
      this->st_gpio_type = (char *)(inbuffer + offset-1);
      offset += length_st_gpio_type;
        memcpy( &(this->gpio_type[i]), &(this->st_gpio_type), sizeof(char*));
      }
      offset += this->header.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/GpioData"; };
    virtual const char * getMD5() override { return "3fe8cd60950d5fefbee2922d797a1b51"; };

  };

}
#endif
