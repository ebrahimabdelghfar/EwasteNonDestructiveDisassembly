#ifndef _ROS_SERVICE_GetRobotInfo_h
#define _ROS_SERVICE_GetRobotInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "industrial_msgs/ServiceReturnCode.h"
#include "industrial_msgs/DeviceInfo.h"

namespace industrial_msgs
{

static const char GETROBOTINFO[] = "industrial_msgs/GetRobotInfo";

  class GetRobotInfoRequest : public ros::Msg
  {
    public:

    GetRobotInfoRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETROBOTINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRobotInfoResponse : public ros::Msg
  {
    public:
      typedef industrial_msgs::DeviceInfo _controller_type;
      _controller_type controller;
      uint32_t robots_length;
      typedef industrial_msgs::DeviceInfo _robots_type;
      _robots_type st_robots;
      _robots_type * robots;
      typedef industrial_msgs::ServiceReturnCode _code_type;
      _code_type code;

    GetRobotInfoResponse():
      controller(),
      robots_length(0), st_robots(), robots(nullptr),
      code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->controller.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->robots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robots_length);
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->robots[i].serialize(outbuffer + offset);
      }
      offset += this->code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->controller.deserialize(inbuffer + offset);
      uint32_t robots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robots_length);
      if(robots_lengthT > robots_length)
        this->robots = (industrial_msgs::DeviceInfo*)realloc(this->robots, robots_lengthT * sizeof(industrial_msgs::DeviceInfo));
      robots_length = robots_lengthT;
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->st_robots.deserialize(inbuffer + offset);
        memcpy( &(this->robots[i]), &(this->st_robots), sizeof(industrial_msgs::DeviceInfo));
      }
      offset += this->code.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETROBOTINFO; };
    virtual const char * getMD5() override { return "5db3230b3e61c85a320b999ffd7f3b3f"; };

  };

  class GetRobotInfo {
    public:
    typedef GetRobotInfoRequest Request;
    typedef GetRobotInfoResponse Response;
  };

}
#endif
