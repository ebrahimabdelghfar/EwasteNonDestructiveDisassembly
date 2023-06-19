#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionAction_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionActionGoal.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionActionResult.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionActionFeedback.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionAction : public ros::Msg
  {
    public:
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionActionResult _action_result_type;
      _action_result_type action_result;
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ExecuteTaskSolutionAction():
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

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionAction"; };
    virtual const char * getMD5() override { return "27e6a8ccaf711ede701d11c7d5afc724"; };

  };

}
#endif
