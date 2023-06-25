#ifndef _ROS_SERVICE_DebugLocalPlan_h
#define _ROS_SERVICE_DebugLocalPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Path2D.h"
#include "nav_2d_msgs/Twist2D.h"
#include "dwb_msgs/LocalPlanEvaluation.h"
#include "nav_2d_msgs/Pose2DStamped.h"

namespace dwb_msgs
{

static const char DEBUGLOCALPLAN[] = "dwb_msgs/DebugLocalPlan";

  class DebugLocalPlanRequest : public ros::Msg
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

    DebugLocalPlanRequest():
      pose(),
      velocity(),
      global_plan(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->global_plan.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->global_plan.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return DEBUGLOCALPLAN; };
    virtual const char * getMD5() override { return "48a8bd4b9e49f5026c60a04a25b5e74a"; };

  };

  class DebugLocalPlanResponse : public ros::Msg
  {
    public:
      typedef dwb_msgs::LocalPlanEvaluation _results_type;
      _results_type results;

    DebugLocalPlanResponse():
      results()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->results.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->results.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return DEBUGLOCALPLAN; };
    virtual const char * getMD5() override { return "a386758bd988bd919d7a5a83bc925094"; };

  };

  class DebugLocalPlan {
    public:
    typedef DebugLocalPlanRequest Request;
    typedef DebugLocalPlanResponse Response;
  };

}
#endif
