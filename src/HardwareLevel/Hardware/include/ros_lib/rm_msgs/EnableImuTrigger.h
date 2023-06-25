#ifndef _ROS_SERVICE_EnableImuTrigger_h
#define _ROS_SERVICE_EnableImuTrigger_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

static const char ENABLEIMUTRIGGER[] = "rm_msgs/EnableImuTrigger";

  class EnableImuTriggerRequest : public ros::Msg
  {
    public:
      typedef const char* _imu_name_type;
      _imu_name_type imu_name;
      typedef bool _enable_trigger_type;
      _enable_trigger_type enable_trigger;

    EnableImuTriggerRequest():
      imu_name(""),
      enable_trigger(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_imu_name = strlen(this->imu_name);
      varToArr(outbuffer + offset, length_imu_name);
      offset += 4;
      memcpy(outbuffer + offset, this->imu_name, length_imu_name);
      offset += length_imu_name;
      union {
        bool real;
        uint8_t base;
      } u_enable_trigger;
      u_enable_trigger.real = this->enable_trigger;
      *(outbuffer + offset + 0) = (u_enable_trigger.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_trigger);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_imu_name;
      arrToVar(length_imu_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imu_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imu_name-1]=0;
      this->imu_name = (char *)(inbuffer + offset-1);
      offset += length_imu_name;
      union {
        bool real;
        uint8_t base;
      } u_enable_trigger;
      u_enable_trigger.base = 0;
      u_enable_trigger.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_trigger = u_enable_trigger.real;
      offset += sizeof(this->enable_trigger);
     return offset;
    }

    virtual const char * getType() override { return ENABLEIMUTRIGGER; };
    virtual const char * getMD5() override { return "a69c0d0d9957c038763bb859200c8069"; };

  };

  class EnableImuTriggerResponse : public ros::Msg
  {
    public:
      typedef bool _is_success_type;
      _is_success_type is_success;

    EnableImuTriggerResponse():
      is_success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_success;
      u_is_success.real = this->is_success;
      *(outbuffer + offset + 0) = (u_is_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_success;
      u_is_success.base = 0;
      u_is_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_success = u_is_success.real;
      offset += sizeof(this->is_success);
     return offset;
    }

    virtual const char * getType() override { return ENABLEIMUTRIGGER; };
    virtual const char * getMD5() override { return "fa3e942e5cfe76a6a46f20a0780b2cf3"; };

  };

  class EnableImuTrigger {
    public:
    typedef EnableImuTriggerRequest Request;
    typedef EnableImuTriggerResponse Response;
  };

}
#endif
