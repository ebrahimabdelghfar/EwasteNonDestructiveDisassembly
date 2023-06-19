#ifndef _ROS_rm_msgs_SuperCapacitor_h
#define _ROS_rm_msgs_SuperCapacitor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rm_msgs
{

  class SuperCapacitor : public ros::Msg
  {
    public:
      typedef float _capacity_type;
      _capacity_type capacity;
      typedef float _limit_power_type;
      _limit_power_type limit_power;
      typedef float _chassis_power_type;
      _chassis_power_type chassis_power;
      typedef uint16_t _chassis_power_buffer_type;
      _chassis_power_buffer_type chassis_power_buffer;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;

    SuperCapacitor():
      capacity(0),
      limit_power(0),
      chassis_power(0),
      chassis_power_buffer(0),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_capacity;
      u_capacity.real = this->capacity;
      *(outbuffer + offset + 0) = (u_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->capacity);
      union {
        float real;
        uint32_t base;
      } u_limit_power;
      u_limit_power.real = this->limit_power;
      *(outbuffer + offset + 0) = (u_limit_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_limit_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_limit_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_limit_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limit_power);
      union {
        float real;
        uint32_t base;
      } u_chassis_power;
      u_chassis_power.real = this->chassis_power;
      *(outbuffer + offset + 0) = (u_chassis_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_chassis_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_chassis_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_chassis_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->chassis_power);
      *(outbuffer + offset + 0) = (this->chassis_power_buffer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->chassis_power_buffer >> (8 * 1)) & 0xFF;
      offset += sizeof(this->chassis_power_buffer);
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_capacity;
      u_capacity.base = 0;
      u_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->capacity = u_capacity.real;
      offset += sizeof(this->capacity);
      union {
        float real;
        uint32_t base;
      } u_limit_power;
      u_limit_power.base = 0;
      u_limit_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_limit_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_limit_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_limit_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->limit_power = u_limit_power.real;
      offset += sizeof(this->limit_power);
      union {
        float real;
        uint32_t base;
      } u_chassis_power;
      u_chassis_power.base = 0;
      u_chassis_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_chassis_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_chassis_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_chassis_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->chassis_power = u_chassis_power.real;
      offset += sizeof(this->chassis_power);
      this->chassis_power_buffer =  ((uint16_t) (*(inbuffer + offset)));
      this->chassis_power_buffer |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->chassis_power_buffer);
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/SuperCapacitor"; };
    virtual const char * getMD5() override { return "95558de4e002ee575de7525116e2b0a3"; };

  };

}
#endif
