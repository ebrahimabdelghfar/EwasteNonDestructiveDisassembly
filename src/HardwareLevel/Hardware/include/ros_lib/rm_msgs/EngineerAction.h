#ifndef _ROS_rm_msgs_EngineerAction_h
#define _ROS_rm_msgs_EngineerAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rm_msgs/EngineerActionGoal.h"
#include "rm_msgs/EngineerActionResult.h"
#include "rm_msgs/EngineerActionFeedback.h"

namespace rm_msgs
{

  class EngineerAction : public ros::Msg
  {
    public:
      typedef rm_msgs::EngineerActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef rm_msgs::EngineerActionResult _action_result_type;
      _action_result_type action_result;
      typedef rm_msgs::EngineerActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    EngineerAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/EngineerAction"; };
    virtual const char * getMD5() override { return "ebffb26b957423ea8414f633c8eb9b77"; };

  };

}
#endif
