#ifndef _ROS_locomotor_msgs_NavigateToPoseActionGoal_h
#define _ROS_locomotor_msgs_NavigateToPoseActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "locomotor_msgs/NavigateToPoseGoal.h"

namespace locomotor_msgs
{

  class NavigateToPoseActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef locomotor_msgs::NavigateToPoseGoal _goal_type;
      _goal_type goal;

    NavigateToPoseActionGoal():
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

    virtual const char * getType() override { return "locomotor_msgs/NavigateToPoseActionGoal"; };
    virtual const char * getMD5() override { return "b390967adbeff6462400a7a3784fd0d2"; };

  };

}
#endif
