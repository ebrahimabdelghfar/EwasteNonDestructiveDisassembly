#ifndef _ROS_locomotor_msgs_NavigationState_h
#define _ROS_locomotor_msgs_NavigationState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Pose2DStamped.h"
#include "nav_2d_msgs/Twist2DStamped.h"
#include "nav_2d_msgs/Path2D.h"

namespace locomotor_msgs
{

  class NavigationState : public ros::Msg
  {
    public:
      typedef nav_2d_msgs::Pose2DStamped _global_pose_type;
      _global_pose_type global_pose;
      typedef nav_2d_msgs::Pose2DStamped _local_pose_type;
      _local_pose_type local_pose;
      typedef nav_2d_msgs::Pose2DStamped _goal_type;
      _goal_type goal;
      typedef nav_2d_msgs::Twist2DStamped _current_velocity_type;
      _current_velocity_type current_velocity;
      typedef nav_2d_msgs::Twist2DStamped _command_velocity_type;
      _command_velocity_type command_velocity;
      typedef nav_2d_msgs::Path2D _global_plan_type;
      _global_plan_type global_plan;

    NavigationState():
      global_pose(),
      local_pose(),
      goal(),
      current_velocity(),
      command_velocity(),
      global_plan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->global_pose.serialize(outbuffer + offset);
      offset += this->local_pose.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->current_velocity.serialize(outbuffer + offset);
      offset += this->command_velocity.serialize(outbuffer + offset);
      offset += this->global_plan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->global_pose.deserialize(inbuffer + offset);
      offset += this->local_pose.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->current_velocity.deserialize(inbuffer + offset);
      offset += this->command_velocity.deserialize(inbuffer + offset);
      offset += this->global_plan.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "locomotor_msgs/NavigationState"; };
    virtual const char * getMD5() override { return "3518ca42eb49bbf8de6cf123dcd80e4a"; };

  };

}
#endif
