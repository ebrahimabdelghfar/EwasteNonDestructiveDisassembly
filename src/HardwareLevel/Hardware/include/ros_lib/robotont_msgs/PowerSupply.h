#ifndef _ROS_robotont_msgs_PowerSupply_h
#define _ROS_robotont_msgs_PowerSupply_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotont_msgs
{

  class PowerSupply : public ros::Msg
  {
    public:
      typedef float _current_type;
      _current_type current;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef bool _estop_pressed_type;
      _estop_pressed_type estop_pressed;

    PowerSupply():
      current(0),
      voltage(0),
      estop_pressed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        bool real;
        uint8_t base;
      } u_estop_pressed;
      u_estop_pressed.real = this->estop_pressed;
      *(outbuffer + offset + 0) = (u_estop_pressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_pressed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        bool real;
        uint8_t base;
      } u_estop_pressed;
      u_estop_pressed.base = 0;
      u_estop_pressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_pressed = u_estop_pressed.real;
      offset += sizeof(this->estop_pressed);
     return offset;
    }

    virtual const char * getType() override { return "robotont_msgs/PowerSupply"; };
    virtual const char * getMD5() override { return "77b9b8496ff236da784fb46719fa61bb"; };

  };

}
#endif
