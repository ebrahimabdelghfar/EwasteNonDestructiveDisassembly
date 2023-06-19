#ifndef _ROS_SERVICE_CmdJointTrajectory_h
#define _ROS_SERVICE_CmdJointTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "industrial_msgs/ServiceReturnCode.h"
#include "trajectory_msgs/JointTrajectory.h"

namespace industrial_msgs
{

static const char CMDJOINTTRAJECTORY[] = "industrial_msgs/CmdJointTrajectory";

  class CmdJointTrajectoryRequest : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;

    CmdJointTrajectoryRequest():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CMDJOINTTRAJECTORY; };
    virtual const char * getMD5() override { return "2a0eff76c870e8595636c2a562ca298e"; };

  };

  class CmdJointTrajectoryResponse : public ros::Msg
  {
    public:
      typedef industrial_msgs::ServiceReturnCode _code_type;
      _code_type code;

    CmdJointTrajectoryResponse():
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

    virtual const char * getType() override { return CMDJOINTTRAJECTORY; };
    virtual const char * getMD5() override { return "50b1f38f75f5677e5692f3b3e7e1ea48"; };

  };

  class CmdJointTrajectory {
    public:
    typedef CmdJointTrajectoryRequest Request;
    typedef CmdJointTrajectoryResponse Response;
  };

}
#endif
