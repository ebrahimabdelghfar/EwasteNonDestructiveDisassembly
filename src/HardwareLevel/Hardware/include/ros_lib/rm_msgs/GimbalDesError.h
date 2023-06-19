#ifndef _ROS_rm_msgs_GimbalDesError_h
#define _ROS_rm_msgs_GimbalDesError_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace rm_msgs
{

  class GimbalDesError : public ros::Msg
  {
    public:
      typedef double _error_type;
      _error_type error;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;

    GimbalDesError():
      error(0),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error);
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
        double real;
        uint64_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error = u_error.real;
      offset += sizeof(this->error);
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

    virtual const char * getType() override { return "rm_msgs/GimbalDesError"; };
    virtual const char * getMD5() override { return "c15e035802d91010fb6b362d3c220fdc"; };

  };

}
#endif
