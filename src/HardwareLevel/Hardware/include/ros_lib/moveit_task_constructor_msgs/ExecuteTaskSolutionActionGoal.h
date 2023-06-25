#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionGoal_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionGoal.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionGoal _goal_type;
      _goal_type goal;

    ExecuteTaskSolutionActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionActionGoal"; };
    virtual const char * getMD5() override { return "ccb3255f3a67433df4332369c8e2fbf9"; };

  };

}
#endif
