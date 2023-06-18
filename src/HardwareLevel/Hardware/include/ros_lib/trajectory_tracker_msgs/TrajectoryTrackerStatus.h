#ifndef _ROS_trajectory_tracker_msgs_TrajectoryTrackerStatus_h
#define _ROS_trajectory_tracker_msgs_TrajectoryTrackerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace trajectory_tracker_msgs
{

  class TrajectoryTrackerStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_remains_type;
      _distance_remains_type distance_remains;
      typedef float _angle_remains_type;
      _angle_remains_type angle_remains;
      typedef int32_t _status_type;
      _status_type status;
      typedef std_msgs::Header _path_header_type;
      _path_header_type path_header;
      enum { NO_PATH =  0 };
      enum { FAR_FROM_PATH =  1 };
      enum { FOLLOWING =  2 };
      enum { GOAL =  3 };

    TrajectoryTrackerStatus():
      header(),
      distance_remains(0),
      angle_remains(0),
      status(0),
      path_header()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_remains;
      u_distance_remains.real = this->distance_remains;
      *(outbuffer + offset + 0) = (u_distance_remains.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_remains.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_remains.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_remains.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_remains);
      union {
        float real;
        uint32_t base;
      } u_angle_remains;
      u_angle_remains.real = this->angle_remains;
      *(outbuffer + offset + 0) = (u_angle_remains.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_remains.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_remains.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_remains.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_remains);
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->path_header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_remains;
      u_distance_remains.base = 0;
      u_distance_remains.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_remains.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_remains.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_remains.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_remains = u_distance_remains.real;
      offset += sizeof(this->distance_remains);
      union {
        float real;
        uint32_t base;
      } u_angle_remains;
      u_angle_remains.base = 0;
      u_angle_remains.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_remains.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_remains.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_remains.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_remains = u_angle_remains.real;
      offset += sizeof(this->angle_remains);
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->status = u_status.real;
      offset += sizeof(this->status);
      offset += this->path_header.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "trajectory_tracker_msgs/TrajectoryTrackerStatus"; };
    virtual const char * getMD5() override { return "5a0c51448c7daa5ed5d700318ba451e7"; };

  };

}
#endif
