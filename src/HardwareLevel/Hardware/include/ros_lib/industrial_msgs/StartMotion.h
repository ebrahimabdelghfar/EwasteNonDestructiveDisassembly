#ifndef _ROS_SERVICE_StartMotion_h
#define _ROS_SERVICE_StartMotion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "industrial_msgs/ServiceReturnCode.h"

namespace industrial_msgs
{

static const char STARTMOTION[] = "industrial_msgs/StartMotion";

  class StartMotionRequest : public ros::Msg
  {
    public:

    StartMotionRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return STARTMOTION; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartMotionResponse : public ros::Msg
  {
    public:
      typedef industrial_msgs::ServiceReturnCode _code_type;
      _code_type code;

    StartMotionResponse():
      code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->code.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return STARTMOTION; };
    virtual const char * getMD5() override { return "50b1f38f75f5677e5692f3b3e7e1ea48"; };

  };

  class StartMotion {
    public:
    typedef StartMotionRequest Request;
    typedef StartMotionResponse Response;
  };

}
#endif
