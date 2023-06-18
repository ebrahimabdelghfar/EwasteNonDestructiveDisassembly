#ifndef _ROS_moveit_task_constructor_msgs_SubTrajectory_h
#define _ROS_moveit_task_constructor_msgs_SubTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/SolutionInfo.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/PlanningScene.h"

namespace moveit_task_constructor_msgs
{

  class SubTrajectory : public ros::Msg
  {
    public:
      typedef moveit_task_constructor_msgs::SolutionInfo _info_type;
      _info_type info;
      typedef moveit_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef moveit_msgs::PlanningScene _scene_diff_type;
      _scene_diff_type scene_diff;

    SubTrajectory():
      info(),
      trajectory(),
      scene_diff()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->scene_diff.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->scene_diff.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/SubTrajectory"; };
    virtual const char * getMD5() override { return "3d070b169c200b77ad502a38faf1889b"; };

  };

}
#endif
