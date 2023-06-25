#ifndef _ROS_abb_rapid_msgs_Orient_h
#define _ROS_abb_rapid_msgs_Orient_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_msgs
{

  class Orient : public ros::Msg
  {
    public:
      typedef float _q1_type;
      _q1_type q1;
      typedef float _q2_type;
      _q2_type q2;
      typedef float _q3_type;
      _q3_type q3;
      typedef float _q4_type;
      _q4_type q4;

    Orient():
      q1(0),
      q2(0),
      q3(0),
      q4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_q1;
      u_q1.real = this->q1;
      *(outbuffer + offset + 0) = (u_q1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q1);
      union {
        float real;
        uint32_t base;
      } u_q2;
      u_q2.real = this->q2;
      *(outbuffer + offset + 0) = (u_q2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q2);
      union {
        float real;
        uint32_t base;
      } u_q3;
      u_q3.real = this->q3;
      *(outbuffer + offset + 0) = (u_q3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q3);
      union {
        float real;
        uint32_t base;
      } u_q4;
      u_q4.real = this->q4;
      *(outbuffer + offset + 0) = (u_q4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_q1;
      u_q1.base = 0;
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q1 = u_q1.real;
      offset += sizeof(this->q1);
      union {
        float real;
        uint32_t base;
      } u_q2;
      u_q2.base = 0;
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q2 = u_q2.real;
      offset += sizeof(this->q2);
      union {
        float real;
        uint32_t base;
      } u_q3;
      u_q3.base = 0;
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q3 = u_q3.real;
      offset += sizeof(this->q3);
      union {
        float real;
        uint32_t base;
      } u_q4;
      u_q4.base = 0;
      u_q4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q4 = u_q4.real;
      offset += sizeof(this->q4);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/Orient"; };
    virtual const char * getMD5() override { return "69cec82442f682ecfe3c0ec1306ced82"; };

  };

}
#endif
