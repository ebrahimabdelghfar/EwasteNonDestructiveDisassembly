#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionFeedback_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionFeedback.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionFeedback _feedback_type;
      _feedback_type feedback;

    ExecuteTaskSolutionActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionActionFeedback"; };
    virtual const char * getMD5() override { return "dd1a3030c1378bc88ff906ef1edbf8b4"; };

  };

}
#endif
