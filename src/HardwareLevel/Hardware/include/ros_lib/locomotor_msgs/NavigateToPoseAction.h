#ifndef _ROS_locomotor_msgs_NavigateToPoseAction_h
#define _ROS_locomotor_msgs_NavigateToPoseAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "locomotor_msgs/NavigateToPoseActionGoal.h"
#include "locomotor_msgs/NavigateToPoseActionResult.h"
#include "locomotor_msgs/NavigateToPoseActionFeedback.h"

namespace locomotor_msgs
{

  class NavigateToPoseAction : public ros::Msg
  {
    public:
      typedef locomotor_msgs::NavigateToPoseActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef locomotor_msgs::NavigateToPoseActionResult _action_result_type;
      _action_result_type action_result;
      typedef locomotor_msgs::NavigateToPoseActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    NavigateToPoseAction():
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

    virtual const char * getType() override { return "locomotor_msgs/NavigateToPoseAction"; };
    virtual const char * getMD5() override { return "0dbc24d4a22f5002a78b774d243eb6b6"; };

  };

}
#endif
