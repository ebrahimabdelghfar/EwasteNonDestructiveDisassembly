#ifndef _ROS_rm_msgs_MovingAverageData_h
#define _ROS_rm_msgs_MovingAverageData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class MovingAverageData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _real_pos_x_type;
      _real_pos_x_type real_pos_x;
      typedef double _real_pos_y_type;
      _real_pos_y_type real_pos_y;
      typedef double _real_pos_z_type;
      _real_pos_z_type real_pos_z;
      typedef double _real_vel_x_type;
      _real_vel_x_type real_vel_x;
      typedef double _real_vel_y_type;
      _real_vel_y_type real_vel_y;
      typedef double _real_vel_z_type;
      _real_vel_z_type real_vel_z;
      typedef double _filtered_pos_x_type;
      _filtered_pos_x_type filtered_pos_x;
      typedef double _filtered_pos_y_type;
      _filtered_pos_y_type filtered_pos_y;
      typedef double _filtered_pos_z_type;
      _filtered_pos_z_type filtered_pos_z;
      typedef double _filtered_vel_x_type;
      _filtered_vel_x_type filtered_vel_x;
      typedef double _filtered_vel_y_type;
      _filtered_vel_y_type filtered_vel_y;
      typedef double _filtered_vel_z_type;
      _filtered_vel_z_type filtered_vel_z;
      typedef double _filtered_center_x_type;
      _filtered_center_x_type filtered_center_x;
      typedef double _filtered_center_y_type;
      _filtered_center_y_type filtered_center_y;
      typedef double _filtered_center_z_type;
      _filtered_center_z_type filtered_center_z;
      typedef double _real_gyro_vel_type;
      _real_gyro_vel_type real_gyro_vel;
      typedef double _filtered_gyro_vel_type;
      _filtered_gyro_vel_type filtered_gyro_vel;

    MovingAverageData():
      header(),
      real_pos_x(0),
      real_pos_y(0),
      real_pos_z(0),
      real_vel_x(0),
      real_vel_y(0),
      real_vel_z(0),
      filtered_pos_x(0),
      filtered_pos_y(0),
      filtered_pos_z(0),
      filtered_vel_x(0),
      filtered_vel_y(0),
      filtered_vel_z(0),
      filtered_center_x(0),
      filtered_center_y(0),
      filtered_center_z(0),
      real_gyro_vel(0),
      filtered_gyro_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_real_pos_x;
      u_real_pos_x.real = this->real_pos_x;
      *(outbuffer + offset + 0) = (u_real_pos_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_pos_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_pos_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_pos_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_pos_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_pos_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_pos_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_pos_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_pos_x);
      union {
        double real;
        uint64_t base;
      } u_real_pos_y;
      u_real_pos_y.real = this->real_pos_y;
      *(outbuffer + offset + 0) = (u_real_pos_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_pos_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_pos_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_pos_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_pos_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_pos_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_pos_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_pos_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_pos_y);
      union {
        double real;
        uint64_t base;
      } u_real_pos_z;
      u_real_pos_z.real = this->real_pos_z;
      *(outbuffer + offset + 0) = (u_real_pos_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_pos_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_pos_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_pos_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_pos_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_pos_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_pos_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_pos_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_pos_z);
      union {
        double real;
        uint64_t base;
      } u_real_vel_x;
      u_real_vel_x.real = this->real_vel_x;
      *(outbuffer + offset + 0) = (u_real_vel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_vel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_vel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_vel_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_vel_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_vel_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_vel_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_vel_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_vel_x);
      union {
        double real;
        uint64_t base;
      } u_real_vel_y;
      u_real_vel_y.real = this->real_vel_y;
      *(outbuffer + offset + 0) = (u_real_vel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_vel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_vel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_vel_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_vel_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_vel_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_vel_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_vel_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_vel_y);
      union {
        double real;
        uint64_t base;
      } u_real_vel_z;
      u_real_vel_z.real = this->real_vel_z;
      *(outbuffer + offset + 0) = (u_real_vel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_vel_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_vel_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_vel_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_vel_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_vel_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_vel_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_vel_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_vel_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_x;
      u_filtered_pos_x.real = this->filtered_pos_x;
      *(outbuffer + offset + 0) = (u_filtered_pos_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_pos_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_pos_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_pos_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_pos_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_pos_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_pos_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_pos_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_pos_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_y;
      u_filtered_pos_y.real = this->filtered_pos_y;
      *(outbuffer + offset + 0) = (u_filtered_pos_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_pos_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_pos_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_pos_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_pos_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_pos_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_pos_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_pos_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_pos_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_z;
      u_filtered_pos_z.real = this->filtered_pos_z;
      *(outbuffer + offset + 0) = (u_filtered_pos_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_pos_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_pos_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_pos_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_pos_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_pos_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_pos_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_pos_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_pos_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_x;
      u_filtered_vel_x.real = this->filtered_vel_x;
      *(outbuffer + offset + 0) = (u_filtered_vel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_vel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_vel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_vel_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_vel_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_vel_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_vel_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_vel_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_vel_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_y;
      u_filtered_vel_y.real = this->filtered_vel_y;
      *(outbuffer + offset + 0) = (u_filtered_vel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_vel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_vel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_vel_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_vel_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_vel_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_vel_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_vel_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_vel_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_z;
      u_filtered_vel_z.real = this->filtered_vel_z;
      *(outbuffer + offset + 0) = (u_filtered_vel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_vel_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_vel_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_vel_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_vel_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_vel_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_vel_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_vel_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_vel_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_x;
      u_filtered_center_x.real = this->filtered_center_x;
      *(outbuffer + offset + 0) = (u_filtered_center_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_center_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_center_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_center_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_center_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_center_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_center_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_center_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_center_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_y;
      u_filtered_center_y.real = this->filtered_center_y;
      *(outbuffer + offset + 0) = (u_filtered_center_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_center_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_center_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_center_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_center_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_center_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_center_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_center_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_center_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_z;
      u_filtered_center_z.real = this->filtered_center_z;
      *(outbuffer + offset + 0) = (u_filtered_center_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_center_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_center_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_center_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_center_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_center_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_center_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_center_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_center_z);
      union {
        double real;
        uint64_t base;
      } u_real_gyro_vel;
      u_real_gyro_vel.real = this->real_gyro_vel;
      *(outbuffer + offset + 0) = (u_real_gyro_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_gyro_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_gyro_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_gyro_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real_gyro_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real_gyro_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real_gyro_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real_gyro_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real_gyro_vel);
      union {
        double real;
        uint64_t base;
      } u_filtered_gyro_vel;
      u_filtered_gyro_vel.real = this->filtered_gyro_vel;
      *(outbuffer + offset + 0) = (u_filtered_gyro_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_gyro_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_gyro_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_gyro_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_gyro_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_gyro_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_gyro_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_gyro_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_gyro_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_real_pos_x;
      u_real_pos_x.base = 0;
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_pos_x = u_real_pos_x.real;
      offset += sizeof(this->real_pos_x);
      union {
        double real;
        uint64_t base;
      } u_real_pos_y;
      u_real_pos_y.base = 0;
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_pos_y = u_real_pos_y.real;
      offset += sizeof(this->real_pos_y);
      union {
        double real;
        uint64_t base;
      } u_real_pos_z;
      u_real_pos_z.base = 0;
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_pos_z = u_real_pos_z.real;
      offset += sizeof(this->real_pos_z);
      union {
        double real;
        uint64_t base;
      } u_real_vel_x;
      u_real_vel_x.base = 0;
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_vel_x = u_real_vel_x.real;
      offset += sizeof(this->real_vel_x);
      union {
        double real;
        uint64_t base;
      } u_real_vel_y;
      u_real_vel_y.base = 0;
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_vel_y = u_real_vel_y.real;
      offset += sizeof(this->real_vel_y);
      union {
        double real;
        uint64_t base;
      } u_real_vel_z;
      u_real_vel_z.base = 0;
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_vel_z = u_real_vel_z.real;
      offset += sizeof(this->real_vel_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_x;
      u_filtered_pos_x.base = 0;
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_pos_x = u_filtered_pos_x.real;
      offset += sizeof(this->filtered_pos_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_y;
      u_filtered_pos_y.base = 0;
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_pos_y = u_filtered_pos_y.real;
      offset += sizeof(this->filtered_pos_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_pos_z;
      u_filtered_pos_z.base = 0;
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_pos_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_pos_z = u_filtered_pos_z.real;
      offset += sizeof(this->filtered_pos_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_x;
      u_filtered_vel_x.base = 0;
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_vel_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_vel_x = u_filtered_vel_x.real;
      offset += sizeof(this->filtered_vel_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_y;
      u_filtered_vel_y.base = 0;
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_vel_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_vel_y = u_filtered_vel_y.real;
      offset += sizeof(this->filtered_vel_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_vel_z;
      u_filtered_vel_z.base = 0;
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_vel_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_vel_z = u_filtered_vel_z.real;
      offset += sizeof(this->filtered_vel_z);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_x;
      u_filtered_center_x.base = 0;
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_center_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_center_x = u_filtered_center_x.real;
      offset += sizeof(this->filtered_center_x);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_y;
      u_filtered_center_y.base = 0;
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_center_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_center_y = u_filtered_center_y.real;
      offset += sizeof(this->filtered_center_y);
      union {
        double real;
        uint64_t base;
      } u_filtered_center_z;
      u_filtered_center_z.base = 0;
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_center_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_center_z = u_filtered_center_z.real;
      offset += sizeof(this->filtered_center_z);
      union {
        double real;
        uint64_t base;
      } u_real_gyro_vel;
      u_real_gyro_vel.base = 0;
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real_gyro_vel = u_real_gyro_vel.real;
      offset += sizeof(this->real_gyro_vel);
      union {
        double real;
        uint64_t base;
      } u_filtered_gyro_vel;
      u_filtered_gyro_vel.base = 0;
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_gyro_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_gyro_vel = u_filtered_gyro_vel.real;
      offset += sizeof(this->filtered_gyro_vel);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/MovingAverageData"; };
    virtual const char * getMD5() override { return "12bd9292dde1a0c07797d8236d7c8fa2"; };

  };

}
#endif
