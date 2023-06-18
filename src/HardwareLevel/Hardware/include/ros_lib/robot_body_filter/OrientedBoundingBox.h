#ifndef _ROS_robot_body_filter_OrientedBoundingBox_h
#define _ROS_robot_body_filter_OrientedBoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Transform.h"

namespace robot_body_filter
{

  class OrientedBoundingBox : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _extents_type;
      _extents_type extents;
      typedef geometry_msgs::Transform _pose_type;
      _pose_type pose;

    OrientedBoundingBox():
      extents(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->extents.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->extents.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "robot_body_filter/OrientedBoundingBox"; };
    virtual const char * getMD5() override { return "23fbcbbbf48653ccd6241e4b01144f36"; };

  };

}
#endif
