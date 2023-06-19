#ifndef _ROS_abb_rapid_msgs_WObjData_h
#define _ROS_abb_rapid_msgs_WObjData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_msgs/Pose.h"

namespace abb_rapid_msgs
{

  class WObjData : public ros::Msg
  {
    public:
      typedef bool _robhold_type;
      _robhold_type robhold;
      typedef bool _ufprog_type;
      _ufprog_type ufprog;
      typedef const char* _ufmec_type;
      _ufmec_type ufmec;
      typedef abb_rapid_msgs::Pose _uframe_type;
      _uframe_type uframe;
      typedef abb_rapid_msgs::Pose _oframe_type;
      _oframe_type oframe;

    WObjData():
      robhold(0),
      ufprog(0),
      ufmec(""),
      uframe(),
      oframe()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_robhold;
      u_robhold.real = this->robhold;
      *(outbuffer + offset + 0) = (u_robhold.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->robhold);
      union {
        bool real;
        uint8_t base;
      } u_ufprog;
      u_ufprog.real = this->ufprog;
      *(outbuffer + offset + 0) = (u_ufprog.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ufprog);
      uint32_t length_ufmec = strlen(this->ufmec);
      varToArr(outbuffer + offset, length_ufmec);
      offset += 4;
      memcpy(outbuffer + offset, this->ufmec, length_ufmec);
      offset += length_ufmec;
      offset += this->uframe.serialize(outbuffer + offset);
      offset += this->oframe.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_robhold;
      u_robhold.base = 0;
      u_robhold.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->robhold = u_robhold.real;
      offset += sizeof(this->robhold);
      union {
        bool real;
        uint8_t base;
      } u_ufprog;
      u_ufprog.base = 0;
      u_ufprog.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ufprog = u_ufprog.real;
      offset += sizeof(this->ufprog);
      uint32_t length_ufmec;
      arrToVar(length_ufmec, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ufmec; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ufmec-1]=0;
      this->ufmec = (char *)(inbuffer + offset-1);
      offset += length_ufmec;
      offset += this->uframe.deserialize(inbuffer + offset);
      offset += this->oframe.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "abb_rapid_msgs/WObjData"; };
    virtual const char * getMD5() override { return "eb6fd21e8b900ca32b7fe6c07697ac07"; };

  };

}
#endif
