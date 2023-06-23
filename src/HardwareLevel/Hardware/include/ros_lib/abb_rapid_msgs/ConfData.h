#ifndef _ROS_abb_rapid_msgs_ConfData_h
#define _ROS_abb_rapid_msgs_ConfData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_msgs
{

  class ConfData : public ros::Msg
  {
    public:
      typedef float _cf1_type;
      _cf1_type cf1;
      typedef float _cf4_type;
      _cf4_type cf4;
      typedef float _cf6_type;
      _cf6_type cf6;
      typedef float _cfx_type;
      _cfx_type cfx;

    ConfData():
      cf1(0),
      cf4(0),
      cf6(0),
      cfx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cf1;
      u_cf1.real = this->cf1;
      *(outbuffer + offset + 0) = (u_cf1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cf1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cf1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cf1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cf1);
      union {
        float real;
        uint32_t base;
      } u_cf4;
      u_cf4.real = this->cf4;
      *(outbuffer + offset + 0) = (u_cf4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cf4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cf4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cf4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cf4);
      union {
        float real;
        uint32_t base;
      } u_cf6;
      u_cf6.real = this->cf6;
      *(outbuffer + offset + 0) = (u_cf6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cf6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cf6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cf6.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cf6);
      union {
        float real;
        uint32_t base;
      } u_cfx;
      u_cfx.real = this->cfx;
      *(outbuffer + offset + 0) = (u_cfx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cfx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cfx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cfx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cfx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_cf1;
      u_cf1.base = 0;
      u_cf1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cf1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cf1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cf1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cf1 = u_cf1.real;
      offset += sizeof(this->cf1);
      union {
        float real;
        uint32_t base;
      } u_cf4;
      u_cf4.base = 0;
      u_cf4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cf4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cf4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cf4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cf4 = u_cf4.real;
      offset += sizeof(this->cf4);
      union {
        float real;
        uint32_t base;
      } u_cf6;
      u_cf6.base = 0;
      u_cf6.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cf6.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cf6.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cf6.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cf6 = u_cf6.real;
      offset += sizeof(this->cf6);
      union {
        float real;
        uint32_t base;
      } u_cfx;
      u_cfx.base = 0;
      u_cfx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cfx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cfx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cfx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cfx = u_cfx.real;
      offset += sizeof(this->cfx);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/ConfData"; };
    virtual const char * getMD5() override { return "21f1129f94cd63dd0cdf33be2bddc75e"; };

  };

}
#endif
