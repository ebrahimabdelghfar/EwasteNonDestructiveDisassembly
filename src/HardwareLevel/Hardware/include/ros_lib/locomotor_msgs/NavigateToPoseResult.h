#ifndef _ROS_locomotor_msgs_NavigateToPoseResult_h
#define _ROS_locomotor_msgs_NavigateToPoseResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "locomotor_msgs/ResultCode.h"

namespace locomotor_msgs
{

  class NavigateToPoseResult : public ros::Msg
  {
    public:
      typedef locomotor_msgs::ResultCode _result_code_type;
      _result_code_type result_code;

    NavigateToPoseResult():
      result_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->result_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->result_code.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "locomotor_msgs/NavigateToPoseResult"; };
    virtual const char * getMD5() override { return "c880febea4d3566bbda2f661c4a761c2"; };

  };

}
#endif
