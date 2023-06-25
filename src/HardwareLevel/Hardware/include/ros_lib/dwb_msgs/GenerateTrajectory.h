#ifndef _ROS_SERVICE_GenerateTrajectory_h
#define _ROS_SERVICE_GenerateTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Twist2D.h"
#include "dwb_msgs/Trajectory2D.h"
#include "geometry_msgs/Pose2D.h"

namespace dwb_msgs
{

static const char GENERATETRAJECTORY[] = "dwb_msgs/GenerateTrajectory";

  class GenerateTrajectoryRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _start_pose_type;
      _start_pose_type start_pose;
      typedef nav_2d_msgs::Twist2D _start_vel_type;
      _start_vel_type start_vel;
      typedef nav_2d_msgs::Twist2D _cmd_vel_type;
      _cmd_vel_type cmd_vel;

    GenerateTrajectoryRequest():
      start_pose(),
      start_vel(),
      cmd_vel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->start_pose.serialize(outbuffer + offset);
      offset += this->start_vel.serialize(outbuffer + offset);
      offset += this->cmd_vel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->start_pose.deserialize(inbuffer + offset);
      offset += this->start_vel.deserialize(inbuffer + offset);
      offset += this->cmd_vel.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GENERATETRAJECTORY; };
    virtual const char * getMD5() override { return "c12676b96c40b5308f43475d17c2db1c"; };

  };

  class GenerateTrajectoryResponse : public ros::Msg
  {
    public:
      typedef dwb_msgs::Trajectory2D _traj_type;
      _traj_type traj;

    GenerateTrajectoryResponse():
      traj()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->traj.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->traj.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GENERATETRAJECTORY; };
    virtual const char * getMD5() override { return "cfa75653fc81c4830452cf99eb524cb4"; };

  };

  class GenerateTrajectory {
    public:
    typedef GenerateTrajectoryRequest Request;
    typedef GenerateTrajectoryResponse Response;
  };

}
#endif
