#ifndef _ROS_joint_qualification_controllers_CBPositionData_h
#define _ROS_joint_qualification_controllers_CBPositionData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/JointPositionData.h"

namespace joint_qualification_controllers
{

  class CBPositionData : public ros::Msg
  {
    public:
      typedef float _flex_position_type;
      _flex_position_type flex_position;
      typedef joint_qualification_controllers::JointPositionData _lift_hold_type;
      _lift_hold_type lift_hold;
      typedef joint_qualification_controllers::JointPositionData _flex_hold_type;
      _flex_hold_type flex_hold;

    CBPositionData():
      flex_position(0),
      lift_hold(),
      flex_hold()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_flex_position;
      u_flex_position.real = this->flex_position;
      *(outbuffer + offset + 0) = (u_flex_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flex_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flex_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flex_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flex_position);
      offset += this->lift_hold.serialize(outbuffer + offset);
      offset += this->flex_hold.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_flex_position;
      u_flex_position.base = 0;
      u_flex_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flex_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flex_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flex_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flex_position = u_flex_position.real;
      offset += sizeof(this->flex_position);
      offset += this->lift_hold.deserialize(inbuffer + offset);
      offset += this->flex_hold.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/CBPositionData"; };
    virtual const char * getMD5() override { return "e7b62743b80e10dde08aea881b6ccf7b"; };

  };

}
#endif
