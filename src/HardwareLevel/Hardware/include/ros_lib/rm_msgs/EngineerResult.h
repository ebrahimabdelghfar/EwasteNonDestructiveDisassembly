#ifndef _ROS_rm_msgs_EngineerResult_h
#define _ROS_rm_msgs_EngineerResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

  class EngineerResult : public ros::Msg
  {
    public:
      typedef bool _finish_type;
      _finish_type finish;

    EngineerResult():
      finish(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_finish;
      u_finish.real = this->finish;
      *(outbuffer + offset + 0) = (u_finish.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->finish);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_finish;
      u_finish.base = 0;
      u_finish.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->finish = u_finish.real;
      offset += sizeof(this->finish);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/EngineerResult"; };
    virtual const char * getMD5() override { return "474a58dbb494a45bb1ca99544cd64e45"; };

  };

}
#endif
