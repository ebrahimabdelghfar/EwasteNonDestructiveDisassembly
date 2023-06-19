#ifndef _ROS_robotont_msgs_LaserScanSplit_h
#define _ROS_robotont_msgs_LaserScanSplit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace robotont_msgs
{

  class LaserScanSplit : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef double _leftMin_type;
      _leftMin_type leftMin;
      typedef double _centerMin_type;
      _centerMin_type centerMin;
      typedef double _rightMin_type;
      _rightMin_type rightMin;
      typedef double _leftMean_type;
      _leftMean_type leftMean;
      typedef double _centerMean_type;
      _centerMean_type centerMean;
      typedef double _rightMean_type;
      _rightMean_type rightMean;

    LaserScanSplit():
      stamp(),
      leftMin(0),
      centerMin(0),
      rightMin(0),
      leftMean(0),
      centerMean(0),
      rightMean(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_leftMin;
      u_leftMin.real = this->leftMin;
      *(outbuffer + offset + 0) = (u_leftMin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftMin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftMin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftMin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_leftMin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_leftMin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_leftMin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_leftMin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->leftMin);
      union {
        double real;
        uint64_t base;
      } u_centerMin;
      u_centerMin.real = this->centerMin;
      *(outbuffer + offset + 0) = (u_centerMin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_centerMin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_centerMin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_centerMin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_centerMin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_centerMin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_centerMin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_centerMin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->centerMin);
      union {
        double real;
        uint64_t base;
      } u_rightMin;
      u_rightMin.real = this->rightMin;
      *(outbuffer + offset + 0) = (u_rightMin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightMin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightMin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightMin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rightMin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rightMin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rightMin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rightMin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rightMin);
      union {
        double real;
        uint64_t base;
      } u_leftMean;
      u_leftMean.real = this->leftMean;
      *(outbuffer + offset + 0) = (u_leftMean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftMean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftMean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftMean.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_leftMean.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_leftMean.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_leftMean.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_leftMean.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->leftMean);
      union {
        double real;
        uint64_t base;
      } u_centerMean;
      u_centerMean.real = this->centerMean;
      *(outbuffer + offset + 0) = (u_centerMean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_centerMean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_centerMean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_centerMean.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_centerMean.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_centerMean.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_centerMean.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_centerMean.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->centerMean);
      union {
        double real;
        uint64_t base;
      } u_rightMean;
      u_rightMean.real = this->rightMean;
      *(outbuffer + offset + 0) = (u_rightMean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightMean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightMean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightMean.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rightMean.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rightMean.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rightMean.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rightMean.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rightMean);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_leftMin;
      u_leftMin.base = 0;
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_leftMin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->leftMin = u_leftMin.real;
      offset += sizeof(this->leftMin);
      union {
        double real;
        uint64_t base;
      } u_centerMin;
      u_centerMin.base = 0;
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_centerMin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->centerMin = u_centerMin.real;
      offset += sizeof(this->centerMin);
      union {
        double real;
        uint64_t base;
      } u_rightMin;
      u_rightMin.base = 0;
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rightMin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rightMin = u_rightMin.real;
      offset += sizeof(this->rightMin);
      union {
        double real;
        uint64_t base;
      } u_leftMean;
      u_leftMean.base = 0;
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_leftMean.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->leftMean = u_leftMean.real;
      offset += sizeof(this->leftMean);
      union {
        double real;
        uint64_t base;
      } u_centerMean;
      u_centerMean.base = 0;
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_centerMean.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->centerMean = u_centerMean.real;
      offset += sizeof(this->centerMean);
      union {
        double real;
        uint64_t base;
      } u_rightMean;
      u_rightMean.base = 0;
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rightMean.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rightMean = u_rightMean.real;
      offset += sizeof(this->rightMean);
     return offset;
    }

    virtual const char * getType() override { return "robotont_msgs/LaserScanSplit"; };
    virtual const char * getMD5() override { return "e8be98bfd4e98a5f589a43bafb13b609"; };

  };

}
#endif
