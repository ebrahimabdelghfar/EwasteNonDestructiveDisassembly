#ifndef _ROS_abb_rapid_msgs_LoadData_h
#define _ROS_abb_rapid_msgs_LoadData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/Pos.h"
#include "abb_rapid_msgs/Orient.h"

namespace abb_rapid_msgs
{

  class LoadData : public ros::Msg
  {
    public:
      typedef float _mass_type;
      _mass_type mass;
      typedef abb_rapid_msgs::Pos _cog_type;
      _cog_type cog;
      typedef abb_rapid_msgs::Orient _aom_type;
      _aom_type aom;
      typedef float _ix_type;
      _ix_type ix;
      typedef float _iy_type;
      _iy_type iy;
      typedef float _iz_type;
      _iz_type iz;

    LoadData():
      mass(0),
      cog(),
      aom(),
      ix(0),
      iy(0),
      iz(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mass;
      u_mass.real = this->mass;
      *(outbuffer + offset + 0) = (u_mass.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mass.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mass.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mass.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mass);
      offset += this->cog.serialize(outbuffer + offset);
      offset += this->aom.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_ix;
      u_ix.real = this->ix;
      *(outbuffer + offset + 0) = (u_ix.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ix.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ix.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ix.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ix);
      union {
        float real;
        uint32_t base;
      } u_iy;
      u_iy.real = this->iy;
      *(outbuffer + offset + 0) = (u_iy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iy);
      union {
        float real;
        uint32_t base;
      } u_iz;
      u_iz.real = this->iz;
      *(outbuffer + offset + 0) = (u_iz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_iz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_iz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_iz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iz);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mass;
      u_mass.base = 0;
      u_mass.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mass.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mass.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mass.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mass = u_mass.real;
      offset += sizeof(this->mass);
      offset += this->cog.deserialize(inbuffer + offset);
      offset += this->aom.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_ix;
      u_ix.base = 0;
      u_ix.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ix.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ix.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ix.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ix = u_ix.real;
      offset += sizeof(this->ix);
      union {
        float real;
        uint32_t base;
      } u_iy;
      u_iy.base = 0;
      u_iy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iy = u_iy.real;
      offset += sizeof(this->iy);
      union {
        float real;
        uint32_t base;
      } u_iz;
      u_iz.base = 0;
      u_iz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_iz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_iz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_iz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->iz = u_iz.real;
      offset += sizeof(this->iz);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/LoadData"; };
    virtual const char * getMD5() override { return "dfe575484752eff5e837f54d2fd939e4"; };

  };

}
#endif
