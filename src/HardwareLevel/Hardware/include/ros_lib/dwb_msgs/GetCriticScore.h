#ifndef _ROS_SERVICE_GetCriticScore_h
#define _ROS_SERVICE_GetCriticScore_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Twist2D.h"
#include "nav_2d_msgs/Path2D.h"
#include "nav_2d_msgs/Pose2DStamped.h"
#include "dwb_msgs/CriticScore.h"
#include "dwb_msgs/Trajectory2D.h"

namespace dwb_msgs
{

static const char GETCRITICSCORE[] = "dwb_msgs/GetCriticScore";

  class GetCriticScoreRequest : public ros::Msg
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
      typedef const char* _critic_name_type;
      _critic_name_type critic_name;

    GetCriticScoreRequest():
      pose(),
      velocity(),
      global_plan(),
      goal(),
      traj(),
      critic_name("")
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
      uint32_t length_critic_name = strlen(this->critic_name);
      varToArr(outbuffer + offset, length_critic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->critic_name, length_critic_name);
      offset += length_critic_name;
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
      uint32_t length_critic_name;
      arrToVar(length_critic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_critic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_critic_name-1]=0;
      this->critic_name = (char *)(inbuffer + offset-1);
      offset += length_critic_name;
     return offset;
    }

    virtual const char * getType() override { return GETCRITICSCORE; };
    virtual const char * getMD5() override { return "3fa15a34e918526f849ca1e20ce4e50a"; };

  };

  class GetCriticScoreResponse : public ros::Msg
  {
    public:
      typedef dwb_msgs::CriticScore _score_type;
      _score_type score;

    GetCriticScoreResponse():
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

    virtual const char * getType() override { return GETCRITICSCORE; };
    virtual const char * getMD5() override { return "85cd9210199e99fbf9e008c47a7fcf65"; };

  };

  class GetCriticScore {
    public:
    typedef GetCriticScoreRequest Request;
    typedef GetCriticScoreResponse Response;
  };

}
#endif
