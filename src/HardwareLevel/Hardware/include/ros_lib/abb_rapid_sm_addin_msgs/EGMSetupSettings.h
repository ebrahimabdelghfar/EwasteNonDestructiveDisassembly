#ifndef _ROS_abb_rapid_sm_addin_msgs_EGMSetupSettings_h
#define _ROS_abb_rapid_sm_addin_msgs_EGMSetupSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_sm_addin_msgs
{

  class EGMSetupSettings : public ros::Msg
  {
    public:
      typedef bool _use_filtering_type;
      _use_filtering_type use_filtering;
      typedef float _comm_timeout_type;
      _comm_timeout_type comm_timeout;

    EGMSetupSettings():
      use_filtering(0),
      comm_timeout(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_filtering;
      u_use_filtering.real = this->use_filtering;
      *(outbuffer + offset + 0) = (u_use_filtering.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_filtering);
      union {
        float real;
        uint32_t base;
      } u_comm_timeout;
      u_comm_timeout.real = this->comm_timeout;
      *(outbuffer + offset + 0) = (u_comm_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_comm_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_comm_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_comm_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->comm_timeout);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_filtering;
      u_use_filtering.base = 0;
      u_use_filtering.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_filtering = u_use_filtering.real;
      offset += sizeof(this->use_filtering);
      union {
        float real;
        uint32_t base;
      } u_comm_timeout;
      u_comm_timeout.base = 0;
      u_comm_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_comm_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_comm_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_comm_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->comm_timeout = u_comm_timeout.real;
      offset += sizeof(this->comm_timeout);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_sm_addin_msgs/EGMSetupSettings"; };
    virtual const char * getMD5() override { return "13bb9a91c166ef61bfdd5d16c6d9ac65"; };

  };

}
#endif
