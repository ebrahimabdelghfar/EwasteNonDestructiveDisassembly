#ifndef _ROS_rm_msgs_GimbalCmd_h
#define _ROS_rm_msgs_GimbalCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/PointStamped.h"

namespace rm_msgs
{

  class GimbalCmd : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef double _rate_yaw_type;
      _rate_yaw_type rate_yaw;
      typedef double _rate_pitch_type;
      _rate_pitch_type rate_pitch;
      typedef double _bullet_speed_type;
      _bullet_speed_type bullet_speed;
      typedef geometry_msgs::PointStamped _target_pos_type;
      _target_pos_type target_pos;
      enum { RATE =  0 };
      enum { TRACK =  1 };
      enum { DIRECT =  2 };

    GimbalCmd():
      stamp(),
      mode(0),
      rate_yaw(0),
      rate_pitch(0),
      bullet_speed(0),
      target_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        double real;
        uint64_t base;
      } u_rate_yaw;
      u_rate_yaw.real = this->rate_yaw;
      *(outbuffer + offset + 0) = (u_rate_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rate_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rate_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rate_yaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rate_yaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rate_yaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rate_yaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rate_yaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rate_yaw);
      union {
        double real;
        uint64_t base;
      } u_rate_pitch;
      u_rate_pitch.real = this->rate_pitch;
      *(outbuffer + offset + 0) = (u_rate_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rate_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rate_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rate_pitch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rate_pitch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rate_pitch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rate_pitch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rate_pitch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rate_pitch);
      union {
        double real;
        uint64_t base;
      } u_bullet_speed;
      u_bullet_speed.real = this->bullet_speed;
      *(outbuffer + offset + 0) = (u_bullet_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bullet_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bullet_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bullet_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_bullet_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_bullet_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_bullet_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_bullet_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bullet_speed);
      offset += this->target_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      union {
        double real;
        uint64_t base;
      } u_rate_yaw;
      u_rate_yaw.base = 0;
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rate_yaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rate_yaw = u_rate_yaw.real;
      offset += sizeof(this->rate_yaw);
      union {
        double real;
        uint64_t base;
      } u_rate_pitch;
      u_rate_pitch.base = 0;
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rate_pitch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rate_pitch = u_rate_pitch.real;
      offset += sizeof(this->rate_pitch);
      union {
        double real;
        uint64_t base;
      } u_bullet_speed;
      u_bullet_speed.base = 0;
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_bullet_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->bullet_speed = u_bullet_speed.real;
      offset += sizeof(this->bullet_speed);
      offset += this->target_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/GimbalCmd"; };
    virtual const char * getMD5() override { return "8bed4be5d11eafc7b7a7b054096b4208"; };

  };

}
#endif
