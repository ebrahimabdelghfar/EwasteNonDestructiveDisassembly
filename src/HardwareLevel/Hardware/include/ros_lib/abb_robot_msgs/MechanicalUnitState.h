#ifndef _ROS_abb_robot_msgs_MechanicalUnitState_h
#define _ROS_abb_robot_msgs_MechanicalUnitState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

  class MechanicalUnitState : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _activated_type;
      _activated_type activated;

    MechanicalUnitState():
      name(""),
      activated(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_activated;
      u_activated.real = this->activated;
      *(outbuffer + offset + 0) = (u_activated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->activated);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_activated;
      u_activated.base = 0;
      u_activated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->activated = u_activated.real;
      offset += sizeof(this->activated);
     return offset;
    }

    virtual const char * getType() override { return "abb_robot_msgs/MechanicalUnitState"; };
    virtual const char * getMD5() override { return "add093e2c7fdce39ce8a0c1e573668e8"; };

  };

}
#endif
