#ifndef _ROS_rm_msgs_KalmanData_h
#define _ROS_rm_msgs_KalmanData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace rm_msgs
{

  class KalmanData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _real_detection_pose_type;
      _real_detection_pose_type real_detection_pose;
      typedef geometry_msgs::Pose _filtered_detection_pose_type;
      _filtered_detection_pose_type filtered_detection_pose;
      typedef geometry_msgs::Twist _real_detection_twist_type;
      _real_detection_twist_type real_detection_twist;
      typedef geometry_msgs::Twist _filtered_detection_twist_type;
      _filtered_detection_twist_type filtered_detection_twist;

    KalmanData():
      header(),
      real_detection_pose(),
      filtered_detection_pose(),
      real_detection_twist(),
      filtered_detection_twist()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->real_detection_pose.serialize(outbuffer + offset);
      offset += this->filtered_detection_pose.serialize(outbuffer + offset);
      offset += this->real_detection_twist.serialize(outbuffer + offset);
      offset += this->filtered_detection_twist.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->real_detection_pose.deserialize(inbuffer + offset);
      offset += this->filtered_detection_pose.deserialize(inbuffer + offset);
      offset += this->real_detection_twist.deserialize(inbuffer + offset);
      offset += this->filtered_detection_twist.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/KalmanData"; };
    virtual const char * getMD5() override { return "076b9f9dc5aab232f694a2e05a2a0a8c"; };

  };

}
#endif
