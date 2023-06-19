#ifndef _ROS_robot_body_filter_OrientedBoundingBoxStamped_h
#define _ROS_robot_body_filter_OrientedBoundingBoxStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "robot_body_filter/OrientedBoundingBox.h"

namespace robot_body_filter
{

  class OrientedBoundingBoxStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef robot_body_filter::OrientedBoundingBox _obb_type;
      _obb_type obb;

    OrientedBoundingBoxStamped():
      header(),
      obb()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->obb.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->obb.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "robot_body_filter/OrientedBoundingBoxStamped"; };
    virtual const char * getMD5() override { return "9db71e3e8567a7e001e55f01b76b7128"; };

  };

}
#endif
