#ifndef _ROS_industrial_msgs_DeviceInfo_h
#define _ROS_industrial_msgs_DeviceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace industrial_msgs
{

  class DeviceInfo : public ros::Msg
  {
    public:
      typedef const char* _model_type;
      _model_type model;
      typedef const char* _serial_number_type;
      _serial_number_type serial_number;
      typedef const char* _hw_version_type;
      _hw_version_type hw_version;
      typedef const char* _sw_version_type;
      _sw_version_type sw_version;
      typedef const char* _address_type;
      _address_type address;

    DeviceInfo():
      model(""),
      serial_number(""),
      hw_version(""),
      sw_version(""),
      address("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      uint32_t length_serial_number = strlen(this->serial_number);
      varToArr(outbuffer + offset, length_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      uint32_t length_hw_version = strlen(this->hw_version);
      varToArr(outbuffer + offset, length_hw_version);
      offset += 4;
      memcpy(outbuffer + offset, this->hw_version, length_hw_version);
      offset += length_hw_version;
      uint32_t length_sw_version = strlen(this->sw_version);
      varToArr(outbuffer + offset, length_sw_version);
      offset += 4;
      memcpy(outbuffer + offset, this->sw_version, length_sw_version);
      offset += length_sw_version;
      uint32_t length_address = strlen(this->address);
      varToArr(outbuffer + offset, length_address);
      offset += 4;
      memcpy(outbuffer + offset, this->address, length_address);
      offset += length_address;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      uint32_t length_serial_number;
      arrToVar(length_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
      uint32_t length_hw_version;
      arrToVar(length_hw_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hw_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hw_version-1]=0;
      this->hw_version = (char *)(inbuffer + offset-1);
      offset += length_hw_version;
      uint32_t length_sw_version;
      arrToVar(length_sw_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sw_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sw_version-1]=0;
      this->sw_version = (char *)(inbuffer + offset-1);
      offset += length_sw_version;
      uint32_t length_address;
      arrToVar(length_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_address-1]=0;
      this->address = (char *)(inbuffer + offset-1);
      offset += length_address;
     return offset;
    }

    virtual const char * getType() override { return "industrial_msgs/DeviceInfo"; };
    virtual const char * getMD5() override { return "373ed7fa0fac92d443be9cd5198e80f0"; };

  };

}
#endif
