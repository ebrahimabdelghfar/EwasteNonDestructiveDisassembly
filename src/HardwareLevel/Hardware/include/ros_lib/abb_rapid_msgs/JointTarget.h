#ifndef _ROS_abb_rapid_msgs_JointTarget_h
#define _ROS_abb_rapid_msgs_JointTarget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/RobJoint.h"
#include "abb_rapid_msgs/ExtJoint.h"

namespace abb_rapid_msgs
{

  class JointTarget : public ros::Msg
  {
    public:
      typedef abb_rapid_msgs::RobJoint _robax_type;
      _robax_type robax;
      typedef abb_rapid_msgs::ExtJoint _extax_type;
      _extax_type extax;

    JointTarget():
      robax(),
      extax()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->robax.serialize(outbuffer + offset);
      offset += this->extax.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->robax.deserialize(inbuffer + offset);
      offset += this->extax.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/JointTarget"; };
    virtual const char * getMD5() override { return "a80f8974c2ebed9e2ef462fcc2a28a38"; };

  };

}
#endif
