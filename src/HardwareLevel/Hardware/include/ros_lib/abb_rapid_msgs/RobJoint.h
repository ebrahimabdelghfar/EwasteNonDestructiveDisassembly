#ifndef _ROS_abb_rapid_msgs_RobJoint_h
#define _ROS_abb_rapid_msgs_RobJoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_msgs
{

  class RobJoint : public ros::Msg
  {
    public:
      typedef float _rax_1_type;
      _rax_1_type rax_1;
      typedef float _rax_2_type;
      _rax_2_type rax_2;
      typedef float _rax_3_type;
      _rax_3_type rax_3;
      typedef float _rax_4_type;
      _rax_4_type rax_4;
      typedef float _rax_5_type;
      _rax_5_type rax_5;
      typedef float _rax_6_type;
      _rax_6_type rax_6;

    RobJoint():
      rax_1(0),
      rax_2(0),
      rax_3(0),
      rax_4(0),
      rax_5(0),
      rax_6(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_rax_1;
      u_rax_1.real = this->rax_1;
      *(outbuffer + offset + 0) = (u_rax_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_1);
      union {
        float real;
        uint32_t base;
      } u_rax_2;
      u_rax_2.real = this->rax_2;
      *(outbuffer + offset + 0) = (u_rax_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_2);
      union {
        float real;
        uint32_t base;
      } u_rax_3;
      u_rax_3.real = this->rax_3;
      *(outbuffer + offset + 0) = (u_rax_3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_3);
      union {
        float real;
        uint32_t base;
      } u_rax_4;
      u_rax_4.real = this->rax_4;
      *(outbuffer + offset + 0) = (u_rax_4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_4);
      union {
        float real;
        uint32_t base;
      } u_rax_5;
      u_rax_5.real = this->rax_5;
      *(outbuffer + offset + 0) = (u_rax_5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_5);
      union {
        float real;
        uint32_t base;
      } u_rax_6;
      u_rax_6.real = this->rax_6;
      *(outbuffer + offset + 0) = (u_rax_6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rax_6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rax_6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rax_6.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rax_6);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_rax_1;
      u_rax_1.base = 0;
      u_rax_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_1 = u_rax_1.real;
      offset += sizeof(this->rax_1);
      union {
        float real;
        uint32_t base;
      } u_rax_2;
      u_rax_2.base = 0;
      u_rax_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_2 = u_rax_2.real;
      offset += sizeof(this->rax_2);
      union {
        float real;
        uint32_t base;
      } u_rax_3;
      u_rax_3.base = 0;
      u_rax_3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_3 = u_rax_3.real;
      offset += sizeof(this->rax_3);
      union {
        float real;
        uint32_t base;
      } u_rax_4;
      u_rax_4.base = 0;
      u_rax_4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_4 = u_rax_4.real;
      offset += sizeof(this->rax_4);
      union {
        float real;
        uint32_t base;
      } u_rax_5;
      u_rax_5.base = 0;
      u_rax_5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_5 = u_rax_5.real;
      offset += sizeof(this->rax_5);
      union {
        float real;
        uint32_t base;
      } u_rax_6;
      u_rax_6.base = 0;
      u_rax_6.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rax_6.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rax_6.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rax_6.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rax_6 = u_rax_6.real;
      offset += sizeof(this->rax_6);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/RobJoint"; };
    virtual const char * getMD5() override { return "24a88117c4b385974e50d44f6663eb2a"; };

  };

}
#endif
