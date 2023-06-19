#ifndef _ROS_abb_rapid_msgs_Pose_h
#define _ROS_abb_rapid_msgs_Pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/Pos.h"
#include "abb_rapid_msgs/Orient.h"

namespace abb_rapid_msgs
{

  class Pose : public ros::Msg
  {
    public:
      typedef abb_rapid_msgs::Pos _trans_type;
      _trans_type trans;
      typedef abb_rapid_msgs::Orient _rot_type;
      _rot_type rot;

    Pose():
      trans(),
      rot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->trans.serialize(outbuffer + offset);
      offset += this->rot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->trans.deserialize(inbuffer + offset);
      offset += this->rot.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/Pose"; };
    virtual const char * getMD5() override { return "94c76c2f70e3c86d018090698fefbfdc"; };

  };

}
#endif
