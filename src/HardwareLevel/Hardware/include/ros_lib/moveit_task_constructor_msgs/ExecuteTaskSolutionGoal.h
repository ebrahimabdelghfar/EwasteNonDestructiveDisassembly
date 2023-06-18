#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionGoal_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/Solution.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionGoal : public ros::Msg
  {
    public:
      typedef moveit_task_constructor_msgs::Solution _solution_type;
      _solution_type solution;

    ExecuteTaskSolutionGoal():
      solution()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionGoal"; };
    virtual const char * getMD5() override { return "aad257f66fea4a1eecca53af1b00bae3"; };

  };

}
#endif
