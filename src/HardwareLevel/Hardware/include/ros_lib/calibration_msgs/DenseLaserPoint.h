#ifndef _ROS_calibration_msgs_DenseLaserPoint_h
#define _ROS_calibration_msgs_DenseLaserPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace calibration_msgs
{

  class DenseLaserPoint : public ros::Msg
  {
    public:
      typedef double _scan_type;
      _scan_type scan;
      typedef double _ray_type;
      _ray_type ray;

    DenseLaserPoint():
      scan(0),
      ray(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_scan;
      u_scan.real = this->scan;
      *(outbuffer + offset + 0) = (u_scan.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_scan.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_scan.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_scan.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_scan.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->scan);
      union {
        double real;
        uint64_t base;
      } u_ray;
      u_ray.real = this->ray;
      *(outbuffer + offset + 0) = (u_ray.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ray.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ray.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ray.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ray.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ray.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ray.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ray.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ray);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_scan;
      u_scan.base = 0;
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_scan.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->scan = u_scan.real;
      offset += sizeof(this->scan);
      union {
        double real;
        uint64_t base;
      } u_ray;
      u_ray.base = 0;
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ray.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ray = u_ray.real;
      offset += sizeof(this->ray);
     return offset;
    }

    virtual const char * getType() override { return "calibration_msgs/DenseLaserPoint"; };
    virtual const char * getMD5() override { return "12821677bc3daf8fabbb485d5b0cc027"; };

  };

}
#endif
