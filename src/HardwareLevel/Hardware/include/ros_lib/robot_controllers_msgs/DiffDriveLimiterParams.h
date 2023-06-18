#ifndef _ROS_robot_controllers_msgs_DiffDriveLimiterParams_h
#define _ROS_robot_controllers_msgs_DiffDriveLimiterParams_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_controllers_msgs
{

  class DiffDriveLimiterParams : public ros::Msg
  {
    public:
      typedef double _max_linear_velocity_type;
      _max_linear_velocity_type max_linear_velocity;
      typedef double _max_linear_acceleration_type;
      _max_linear_acceleration_type max_linear_acceleration;
      typedef double _max_angular_velocity_type;
      _max_angular_velocity_type max_angular_velocity;
      typedef double _max_angular_acceleration_type;
      _max_angular_acceleration_type max_angular_acceleration;
      typedef double _max_wheel_velocity_type;
      _max_wheel_velocity_type max_wheel_velocity;
      typedef double _track_width_type;
      _track_width_type track_width;
      typedef bool _angular_velocity_limits_linear_velocity_type;
      _angular_velocity_limits_linear_velocity_type angular_velocity_limits_linear_velocity;
      typedef bool _scale_to_wheel_velocity_limits_type;
      _scale_to_wheel_velocity_limits_type scale_to_wheel_velocity_limits;

    DiffDriveLimiterParams():
      max_linear_velocity(0),
      max_linear_acceleration(0),
      max_angular_velocity(0),
      max_angular_acceleration(0),
      max_wheel_velocity(0),
      track_width(0),
      angular_velocity_limits_linear_velocity(0),
      scale_to_wheel_velocity_limits(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_max_linear_velocity;
      u_max_linear_velocity.real = this->max_linear_velocity;
      *(outbuffer + offset + 0) = (u_max_linear_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_linear_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_linear_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_linear_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_linear_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_linear_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_linear_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_linear_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_linear_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_linear_acceleration;
      u_max_linear_acceleration.real = this->max_linear_acceleration;
      *(outbuffer + offset + 0) = (u_max_linear_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_linear_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_linear_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_linear_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_linear_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_linear_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_linear_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_linear_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_linear_acceleration);
      union {
        double real;
        uint64_t base;
      } u_max_angular_velocity;
      u_max_angular_velocity.real = this->max_angular_velocity;
      *(outbuffer + offset + 0) = (u_max_angular_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_angular_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_angular_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_angular_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_angular_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_angular_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_angular_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_angular_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_angular_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_angular_acceleration;
      u_max_angular_acceleration.real = this->max_angular_acceleration;
      *(outbuffer + offset + 0) = (u_max_angular_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_angular_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_angular_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_angular_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_angular_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_angular_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_angular_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_angular_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_angular_acceleration);
      union {
        double real;
        uint64_t base;
      } u_max_wheel_velocity;
      u_max_wheel_velocity.real = this->max_wheel_velocity;
      *(outbuffer + offset + 0) = (u_max_wheel_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_wheel_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_wheel_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_wheel_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_wheel_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_wheel_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_wheel_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_wheel_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_wheel_velocity);
      union {
        double real;
        uint64_t base;
      } u_track_width;
      u_track_width.real = this->track_width;
      *(outbuffer + offset + 0) = (u_track_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_width.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_track_width.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_track_width.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_track_width.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_track_width.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->track_width);
      union {
        bool real;
        uint8_t base;
      } u_angular_velocity_limits_linear_velocity;
      u_angular_velocity_limits_linear_velocity.real = this->angular_velocity_limits_linear_velocity;
      *(outbuffer + offset + 0) = (u_angular_velocity_limits_linear_velocity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angular_velocity_limits_linear_velocity);
      union {
        bool real;
        uint8_t base;
      } u_scale_to_wheel_velocity_limits;
      u_scale_to_wheel_velocity_limits.real = this->scale_to_wheel_velocity_limits;
      *(outbuffer + offset + 0) = (u_scale_to_wheel_velocity_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->scale_to_wheel_velocity_limits);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_max_linear_velocity;
      u_max_linear_velocity.base = 0;
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_linear_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_linear_velocity = u_max_linear_velocity.real;
      offset += sizeof(this->max_linear_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_linear_acceleration;
      u_max_linear_acceleration.base = 0;
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_linear_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_linear_acceleration = u_max_linear_acceleration.real;
      offset += sizeof(this->max_linear_acceleration);
      union {
        double real;
        uint64_t base;
      } u_max_angular_velocity;
      u_max_angular_velocity.base = 0;
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_angular_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_angular_velocity = u_max_angular_velocity.real;
      offset += sizeof(this->max_angular_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_angular_acceleration;
      u_max_angular_acceleration.base = 0;
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_angular_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_angular_acceleration = u_max_angular_acceleration.real;
      offset += sizeof(this->max_angular_acceleration);
      union {
        double real;
        uint64_t base;
      } u_max_wheel_velocity;
      u_max_wheel_velocity.base = 0;
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_wheel_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_wheel_velocity = u_max_wheel_velocity.real;
      offset += sizeof(this->max_wheel_velocity);
      union {
        double real;
        uint64_t base;
      } u_track_width;
      u_track_width.base = 0;
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_track_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->track_width = u_track_width.real;
      offset += sizeof(this->track_width);
      union {
        bool real;
        uint8_t base;
      } u_angular_velocity_limits_linear_velocity;
      u_angular_velocity_limits_linear_velocity.base = 0;
      u_angular_velocity_limits_linear_velocity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angular_velocity_limits_linear_velocity = u_angular_velocity_limits_linear_velocity.real;
      offset += sizeof(this->angular_velocity_limits_linear_velocity);
      union {
        bool real;
        uint8_t base;
      } u_scale_to_wheel_velocity_limits;
      u_scale_to_wheel_velocity_limits.base = 0;
      u_scale_to_wheel_velocity_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->scale_to_wheel_velocity_limits = u_scale_to_wheel_velocity_limits.real;
      offset += sizeof(this->scale_to_wheel_velocity_limits);
     return offset;
    }

    virtual const char * getType() override { return "robot_controllers_msgs/DiffDriveLimiterParams"; };
    virtual const char * getMD5() override { return "c438ebbdf2d3d45fdfb67f5ba9e6ca3d"; };

  };

}
#endif
