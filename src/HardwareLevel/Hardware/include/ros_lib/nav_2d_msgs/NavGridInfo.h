#ifndef _ROS_nav_2d_msgs_NavGridInfo_h
#define _ROS_nav_2d_msgs_NavGridInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nav_2d_msgs
{

  class NavGridInfo : public ros::Msg
  {
    public:
      typedef uint32_t _width_type;
      _width_type width;
      typedef uint32_t _height_type;
      _height_type height;
      typedef double _resolution_type;
      _resolution_type resolution;
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef double _origin_x_type;
      _origin_x_type origin_x;
      typedef double _origin_y_type;
      _origin_y_type origin_y;

    NavGridInfo():
      width(0),
      height(0),
      resolution(0),
      frame_id(""),
      origin_x(0),
      origin_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->resolution);
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      union {
        double real;
        uint64_t base;
      } u_origin_x;
      u_origin_x.real = this->origin_x;
      *(outbuffer + offset + 0) = (u_origin_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_origin_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_origin_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_origin_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_origin_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_origin_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_origin_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_origin_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->origin_x);
      union {
        double real;
        uint64_t base;
      } u_origin_y;
      u_origin_y.real = this->origin_y;
      *(outbuffer + offset + 0) = (u_origin_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_origin_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_origin_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_origin_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_origin_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_origin_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_origin_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_origin_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->origin_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      union {
        double real;
        uint64_t base;
      } u_origin_x;
      u_origin_x.base = 0;
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_origin_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->origin_x = u_origin_x.real;
      offset += sizeof(this->origin_x);
      union {
        double real;
        uint64_t base;
      } u_origin_y;
      u_origin_y.base = 0;
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_origin_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->origin_y = u_origin_y.real;
      offset += sizeof(this->origin_y);
     return offset;
    }

    virtual const char * getType() override { return "nav_2d_msgs/NavGridInfo"; };
    virtual const char * getMD5() override { return "061e7a10093a3d95bf6b212dff9d9715"; };

  };

}
#endif
