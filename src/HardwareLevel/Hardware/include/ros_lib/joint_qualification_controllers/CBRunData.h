#ifndef _ROS_joint_qualification_controllers_CBRunData_h
#define _ROS_joint_qualification_controllers_CBRunData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/CBPositionData.h"

namespace joint_qualification_controllers
{

  class CBRunData : public ros::Msg
  {
    public:
      typedef float _lift_position_type;
      _lift_position_type lift_position;
      uint32_t flex_data_length;
      typedef joint_qualification_controllers::CBPositionData _flex_data_type;
      _flex_data_type st_flex_data;
      _flex_data_type * flex_data;

    CBRunData():
      lift_position(0),
      flex_data_length(0), st_flex_data(), flex_data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_lift_position;
      u_lift_position.real = this->lift_position;
      *(outbuffer + offset + 0) = (u_lift_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lift_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lift_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lift_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lift_position);
      *(outbuffer + offset + 0) = (this->flex_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flex_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flex_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flex_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flex_data_length);
      for( uint32_t i = 0; i < flex_data_length; i++){
      offset += this->flex_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_lift_position;
      u_lift_position.base = 0;
      u_lift_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lift_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lift_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lift_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lift_position = u_lift_position.real;
      offset += sizeof(this->lift_position);
      uint32_t flex_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      flex_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      flex_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      flex_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->flex_data_length);
      if(flex_data_lengthT > flex_data_length)
        this->flex_data = (joint_qualification_controllers::CBPositionData*)realloc(this->flex_data, flex_data_lengthT * sizeof(joint_qualification_controllers::CBPositionData));
      flex_data_length = flex_data_lengthT;
      for( uint32_t i = 0; i < flex_data_length; i++){
      offset += this->st_flex_data.deserialize(inbuffer + offset);
        memcpy( &(this->flex_data[i]), &(this->st_flex_data), sizeof(joint_qualification_controllers::CBPositionData));
      }
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/CBRunData"; };
    virtual const char * getMD5() override { return "16bad2df24f5cffc934c2d3ae9bb08e6"; };

  };

}
#endif
