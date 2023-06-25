#ifndef _ROS_SERVICE_ScoreTrajectory_h
#define _ROS_SERVICE_ScoreTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Twist2D.h"
#include "nav_2d_msgs/Path2D.h"
#include "dwb_msgs/TrajectoryScore.h"
#include "nav_2d_msgs/Pose2DStamped.h"
#include "dwb_msgs/Trajectory2D.h"

namespace dwb_msgs
{

static const char SCORETRAJECTORY[] = "dwb_msgs/ScoreTrajectory";

  class ScoreTrajectoryRequest : public ros::Msg
  {
    public:
      typedef nav_2d_msgs::Pose2DStamped _pose_type;
      _pose_type pose;
      typedef nav_2d_msgs::Twist2D _velocity_type;
      _velocity_type velocity;
      typedef nav_2d_msgs::Path2D _global_plan_type;
      _global_plan_type global_plan;
      typedef nav_2d_msgs::Pose2DStamped _goal_type;
      _goal_type goal;
      typedef dwb_msgs::Trajectory2D _traj_type;
      _traj_type traj;

    ScoreTrajectoryRequest():
      pose(),
      velocity(),
      global_plan(),
      goal(),
      traj()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->global_plan.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      offset += this->traj.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->global_plan.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      offset += this->traj.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SCORETRAJECTORY; };
    virtual const char * getMD5() override { return "af4f903ab43c0b32f7ec1d0ded20f62b"; };

  };

  class ScoreTrajectoryResponse : public ros::Msg
  {
    public:
      typedef dwb_msgs::TrajectoryScore _score_type;
      _score_type score;

    ScoreTrajectoryResponse():
      score()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->score.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->score.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SCORETRAJECTORY; };
    virtual const char * getMD5() override { return "79d4637c00f492e5b6dd1b88aed58cd2"; };

  };

  class ScoreTrajectory {
    public:
    typedef ScoreTrajectoryRequest Request;
    typedef ScoreTrajectoryResponse Response;
  };

}
#endif
