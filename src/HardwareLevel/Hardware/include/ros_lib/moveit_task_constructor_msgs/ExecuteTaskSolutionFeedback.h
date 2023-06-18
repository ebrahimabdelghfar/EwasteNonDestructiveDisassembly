#ifndef _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionFeedback_h
#define _ROS_moveit_task_constructor_msgs_ExecuteTaskSolutionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_task_constructor_msgs
{

  class ExecuteTaskSolutionFeedback : public ros::Msg
  {
    public:
      typedef uint32_t _sub_id_type;
      _sub_id_type sub_id;
      typedef uint32_t _sub_no_type;
      _sub_no_type sub_no;

    ExecuteTaskSolutionFeedback():
      sub_id(0),
      sub_no(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sub_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_id);
      *(outbuffer + offset + 0) = (this->sub_no >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_no >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_no >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_no >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_no);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->sub_id =  ((uint32_t) (*(inbuffer + offset)));
      this->sub_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sub_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sub_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sub_id);
      this->sub_no =  ((uint32_t) (*(inbuffer + offset)));
      this->sub_no |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sub_no |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sub_no |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sub_no);
     return offset;
    }

    virtual const char * getType() override { return "moveit_task_constructor_msgs/ExecuteTaskSolutionFeedback"; };
    virtual const char * getMD5() override { return "5b60fd9ace7afa0cb3eb2c409d0732ed"; };

  };

}
#endif
