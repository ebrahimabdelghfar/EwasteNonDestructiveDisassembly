#ifndef _ROS_joint_qualification_controllers_JointData_h
#define _ROS_joint_qualification_controllers_JointData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace joint_qualification_controllers
{

  class JointData : public ros::Msg
  {
    public:
      typedef int16_t _index_type;
      _index_type index;
      typedef const char* _name_type;
      _name_type name;
      typedef int8_t _is_cal_type;
      _is_cal_type is_cal;
      typedef int8_t _has_safety_type;
      _has_safety_type has_safety;
      typedef const char* _type_type;
      _type_type type;

    JointData():
      index(0),
      name(""),
      is_cal(0),
      has_safety(0),
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->index);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int8_t real;
        uint8_t base;
      } u_is_cal;
      u_is_cal.real = this->is_cal;
      *(outbuffer + offset + 0) = (u_is_cal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_cal);
      union {
        int8_t real;
        uint8_t base;
      } u_has_safety;
      u_has_safety.real = this->has_safety;
      *(outbuffer + offset + 0) = (u_has_safety.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_safety);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index = u_index.real;
      offset += sizeof(this->index);
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
        int8_t real;
        uint8_t base;
      } u_is_cal;
      u_is_cal.base = 0;
      u_is_cal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_cal = u_is_cal.real;
      offset += sizeof(this->is_cal);
      union {
        int8_t real;
        uint8_t base;
      } u_has_safety;
      u_has_safety.base = 0;
      u_has_safety.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_safety = u_has_safety.real;
      offset += sizeof(this->has_safety);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/JointData"; };
    virtual const char * getMD5() override { return "191610564bf935172c9424c803ed6939"; };

  };

}
#endif
