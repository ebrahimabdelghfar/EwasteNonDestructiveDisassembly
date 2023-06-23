#ifndef _ROS_locomotor_msgs_NavigateToPoseGoal_h
#define _ROS_locomotor_msgs_NavigateToPoseGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Pose2DStamped.h"

namespace locomotor_msgs
{

  class NavigateToPoseGoal : public ros::Msg
  {
    public:
      typedef nav_2d_msgs::Pose2DStamped _goal_type;
      _goal_type goal;

    NavigateToPoseGoal():
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "locomotor_msgs/NavigateToPoseGoal"; };
    virtual const char * getMD5() override { return "9b2d518adfd9df22ae3384278db3a616"; };

  };

}
#endif
