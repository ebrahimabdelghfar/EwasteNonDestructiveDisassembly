#ifndef _ROS_robot_body_filter_SphereStamped_h
#define _ROS_robot_body_filter_SphereStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "robot_body_filter/Sphere.h"

namespace robot_body_filter
{

  class SphereStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef robot_body_filter::Sphere _sphere_type;
      _sphere_type sphere;

    SphereStamped():
      header(),
      sphere()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->sphere.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->sphere.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "robot_body_filter/SphereStamped"; };
    virtual const char * getMD5() override { return "b3bf80c24e3bf1e801648dc1419145c0"; };

  };

}
#endif
