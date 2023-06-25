#ifndef _ROS_rm_msgs_LpData_h
#define _ROS_rm_msgs_LpData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class LpData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _real_type;
      _real_type real;
      typedef double _filtered_type;
      _filtered_type filtered;

    LpData():
      header(),
      real(0),
      filtered(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_real;
      u_real.real = this->real;
      *(outbuffer + offset + 0) = (u_real.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_real.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_real.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_real.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_real.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->real);
      union {
        double real;
        uint64_t base;
      } u_filtered;
      u_filtered.real = this->filtered;
      *(outbuffer + offset + 0) = (u_filtered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_real;
      u_real.base = 0;
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_real.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->real = u_real.real;
      offset += sizeof(this->real);
      union {
        double real;
        uint64_t base;
      } u_filtered;
      u_filtered.base = 0;
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered = u_filtered.real;
      offset += sizeof(this->filtered);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/LpData"; };
    virtual const char * getMD5() override { return "15bf1676ae28702eed3b9b7f8b20c577"; };

  };

}
#endif
