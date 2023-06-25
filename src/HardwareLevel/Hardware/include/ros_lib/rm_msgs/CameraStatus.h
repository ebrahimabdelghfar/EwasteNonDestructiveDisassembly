#ifndef _ROS_SERVICE_CameraStatus_h
#define _ROS_SERVICE_CameraStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

static const char CAMERASTATUS[] = "rm_msgs/CameraStatus";

  class CameraStatusRequest : public ros::Msg
  {
    public:
      typedef bool _imu_request_type;
      _imu_request_type imu_request;

    CameraStatusRequest():
      imu_request(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_imu_request;
      u_imu_request.real = this->imu_request;
      *(outbuffer + offset + 0) = (u_imu_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_request);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_imu_request;
      u_imu_request.base = 0;
      u_imu_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->imu_request = u_imu_request.real;
      offset += sizeof(this->imu_request);
     return offset;
    }

    virtual const char * getType() override { return CAMERASTATUS; };
    virtual const char * getMD5() override { return "a72b7d7d4a1abf19c22f6b9c76c75520"; };

  };

  class CameraStatusResponse : public ros::Msg
  {
    public:
      typedef bool _is_open_type;
      _is_open_type is_open;

    CameraStatusResponse():
      is_open(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_open;
      u_is_open.real = this->is_open;
      *(outbuffer + offset + 0) = (u_is_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_open);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_open;
      u_is_open.base = 0;
      u_is_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_open = u_is_open.real;
      offset += sizeof(this->is_open);
     return offset;
    }

    virtual const char * getType() override { return CAMERASTATUS; };
    virtual const char * getMD5() override { return "46713fbdaf364c45f5b76eadfde2f685"; };

  };

  class CameraStatus {
    public:
    typedef CameraStatusRequest Request;
    typedef CameraStatusResponse Response;
  };

}
#endif
