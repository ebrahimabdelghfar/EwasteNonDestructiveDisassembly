#ifndef _ROS_abb_rapid_msgs_ExtJoint_h
#define _ROS_abb_rapid_msgs_ExtJoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_msgs
{

  class ExtJoint : public ros::Msg
  {
    public:
      typedef float _eax_a_type;
      _eax_a_type eax_a;
      typedef float _eax_b_type;
      _eax_b_type eax_b;
      typedef float _eax_c_type;
      _eax_c_type eax_c;
      typedef float _eax_d_type;
      _eax_d_type eax_d;
      typedef float _eax_e_type;
      _eax_e_type eax_e;
      typedef float _eax_f_type;
      _eax_f_type eax_f;

    ExtJoint():
      eax_a(0),
      eax_b(0),
      eax_c(0),
      eax_d(0),
      eax_e(0),
      eax_f(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_eax_a;
      u_eax_a.real = this->eax_a;
      *(outbuffer + offset + 0) = (u_eax_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_a.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_a.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_a.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_a);
      union {
        float real;
        uint32_t base;
      } u_eax_b;
      u_eax_b.real = this->eax_b;
      *(outbuffer + offset + 0) = (u_eax_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_b.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_b);
      union {
        float real;
        uint32_t base;
      } u_eax_c;
      u_eax_c.real = this->eax_c;
      *(outbuffer + offset + 0) = (u_eax_c.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_c.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_c.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_c.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_c);
      union {
        float real;
        uint32_t base;
      } u_eax_d;
      u_eax_d.real = this->eax_d;
      *(outbuffer + offset + 0) = (u_eax_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_d.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_d);
      union {
        float real;
        uint32_t base;
      } u_eax_e;
      u_eax_e.real = this->eax_e;
      *(outbuffer + offset + 0) = (u_eax_e.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_e.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_e.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_e.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_e);
      union {
        float real;
        uint32_t base;
      } u_eax_f;
      u_eax_f.real = this->eax_f;
      *(outbuffer + offset + 0) = (u_eax_f.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eax_f.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eax_f.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eax_f.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eax_f);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_eax_a;
      u_eax_a.base = 0;
      u_eax_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_a = u_eax_a.real;
      offset += sizeof(this->eax_a);
      union {
        float real;
        uint32_t base;
      } u_eax_b;
      u_eax_b.base = 0;
      u_eax_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_b = u_eax_b.real;
      offset += sizeof(this->eax_b);
      union {
        float real;
        uint32_t base;
      } u_eax_c;
      u_eax_c.base = 0;
      u_eax_c.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_c.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_c.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_c.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_c = u_eax_c.real;
      offset += sizeof(this->eax_c);
      union {
        float real;
        uint32_t base;
      } u_eax_d;
      u_eax_d.base = 0;
      u_eax_d.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_d.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_d.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_d.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_d = u_eax_d.real;
      offset += sizeof(this->eax_d);
      union {
        float real;
        uint32_t base;
      } u_eax_e;
      u_eax_e.base = 0;
      u_eax_e.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_e.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_e.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_e.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_e = u_eax_e.real;
      offset += sizeof(this->eax_e);
      union {
        float real;
        uint32_t base;
      } u_eax_f;
      u_eax_f.base = 0;
      u_eax_f.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eax_f.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eax_f.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eax_f.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->eax_f = u_eax_f.real;
      offset += sizeof(this->eax_f);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/ExtJoint"; };
    virtual const char * getMD5() override { return "f8550d9e82bcfae84c73de38fde07b03"; };

  };

}
#endif
