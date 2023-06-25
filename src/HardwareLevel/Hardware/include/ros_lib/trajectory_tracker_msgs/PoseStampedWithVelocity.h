#ifndef _ROS_trajectory_tracker_msgs_PoseStampedWithVelocity_h
#define _ROS_trajectory_tracker_msgs_PoseStampedWithVelocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"

namespace trajectory_tracker_msgs
{

  class PoseStampedWithVelocity : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef geometry_msgs::Vector3 _linear_velocity_type;
      _linear_velocity_type linear_velocity;

    PoseStampedWithVelocity():
      header(),
      pose(),
      linear_velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->linear_velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->linear_velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "trajectory_tracker_msgs/PoseStampedWithVelocity"; };
    virtual const char * getMD5() override { return "f2363b3be7115b83eeb8e9e4f3ce22e0"; };

  };

}
#endif
