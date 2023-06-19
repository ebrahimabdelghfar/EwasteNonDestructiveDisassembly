#ifndef _ROS_rm_msgs_ShootCmd_h
#define _ROS_rm_msgs_ShootCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rm_msgs
{

  class ShootCmd : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef uint8_t _speed_type;
      _speed_type speed;
      typedef double _hz_type;
      _hz_type hz;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      enum { STOP =  0 };
      enum { READY =  1 };
      enum { PUSH =  2 };
      enum { SPEED_ZERO_FOR_TEST =  0 };
      enum { SPEED_10M_PER_SECOND =  1 };
      enum { SPEED_15M_PER_SECOND =  2 };
      enum { SPEED_16M_PER_SECOND =  3 };
      enum { SPEED_18M_PER_SECOND =  4 };
      enum { SPEED_30M_PER_SECOND =  5 };

    ShootCmd():
      mode(0),
      speed(0),
      hz(0),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        double real;
        uint64_t base;
      } u_hz;
      u_hz.real = this->hz;
      *(outbuffer + offset + 0) = (u_hz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hz.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hz.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hz.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hz.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hz.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hz);
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
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      this->speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed);
      union {
        double real;
        uint64_t base;
      } u_hz;
      u_hz.base = 0;
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hz.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hz = u_hz.real;
      offset += sizeof(this->hz);
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

    virtual const char * getType() override { return "rm_msgs/ShootCmd"; };
    virtual const char * getMD5() override { return "b25a3c00a92bb8eead2eb72002d6d2f8"; };

  };

}
#endif
