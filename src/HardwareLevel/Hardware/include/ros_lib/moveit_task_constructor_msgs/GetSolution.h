#ifndef _ROS_SERVICE_GetSolution_h
#define _ROS_SERVICE_GetSolution_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "moveit_task_constructor_msgs/Solution.h"

namespace moveit_task_constructor_msgs
{

static const char GETSOLUTION[] = "moveit_task_constructor_msgs/GetSolution";

  class GetSolutionRequest : public ros::Msg
  {
    public:
      typedef uint32_t _solution_id_type;
      _solution_id_type solution_id;

    GetSolutionRequest():
      solution_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->solution_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->solution_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->solution_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->solution_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->solution_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->solution_id =  ((uint32_t) (*(inbuffer + offset)));
      this->solution_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->solution_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->solution_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->solution_id);
     return offset;
    }

    virtual const char * getType() override { return GETSOLUTION; };
    virtual const char * getMD5() override { return "004aed0f49ddbcbc97f8b44e284b1729"; };

  };

  class GetSolutionResponse : public ros::Msg
  {
    public:
      typedef moveit_task_constructor_msgs::Solution _solution_type;
      _solution_type solution;

    GetSolutionResponse():
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

    virtual const char * getType() override { return GETSOLUTION; };
    virtual const char * getMD5() override { return "aad257f66fea4a1eecca53af1b00bae3"; };

  };

  class GetSolution {
    public:
    typedef GetSolutionRequest Request;
    typedef GetSolutionResponse Response;
  };

}
#endif
