#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionResult_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "moveit_task_constructor_msgs/ExecuteTaskSolutionResult.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef moveit_task_constructor_msgs::ExecuteTaskSolutionResult _result_type;
      _result_type result;

    ExecuteTaskSolutionActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionActionResult"; };
    virtual const char * getMD5() override { return "2a052ef9772722c8338e057a61e60639"; };

  };

}
#endif
