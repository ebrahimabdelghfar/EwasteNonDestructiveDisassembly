#ifndef _ROS_SERVICE_StatusChange_h
#define _ROS_SERVICE_StatusChange_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rm_msgs
{

static const char STATUSCHANGE[] = "rm_msgs/StatusChange";

  class StatusChangeRequest : public ros::Msg
  {
    public:
      typedef uint8_t _color_type;
      _color_type color;
      typedef uint8_t _target_type;
      _target_type target;
      typedef uint8_t _armor_target_type;
      _armor_target_type armor_target;
      typedef uint8_t _exposure_type;
      _exposure_type exposure;
      typedef uint8_t _use_id_classification_type;
      _use_id_classification_type use_id_classification;
      enum { RED =  0 };
      enum { BLUE =  1 };
      enum { ARMOR =  0 };
      enum { BUFF =  1 };
      enum { ARMOR_ALL =  0 };
      enum { ARMOR_OUTPOST_BASE =  1 };
      enum { ARMOR_WITHOUT_OUTPOST_BASE =  2 };
      enum { EXPOSURE_LEVEL_0 =  0 };
      enum { EXPOSURE_LEVEL_1 =  1 };
      enum { EXPOSURE_LEVEL_2 =  2 };
      enum { EXPOSURE_LEVEL_3 =  3 };
      enum { EXPOSURE_LEVEL_4 =  4 };

    StatusChangeRequest():
      color(0),
      target(0),
      armor_target(0),
      exposure(0),
      use_id_classification(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      *(outbuffer + offset + 0) = (this->target >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target);
      *(outbuffer + offset + 0) = (this->armor_target >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armor_target);
      *(outbuffer + offset + 0) = (this->exposure >> (8 * 0)) & 0xFF;
      offset += sizeof(this->exposure);
      *(outbuffer + offset + 0) = (this->use_id_classification >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_id_classification);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
      this->target =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->target);
      this->armor_target =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->armor_target);
      this->exposure =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->exposure);
      this->use_id_classification =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->use_id_classification);
     return offset;
    }

    virtual const char * getType() override { return STATUSCHANGE; };
    virtual const char * getMD5() override { return "e5974674c612c2ddc9fe100a2fa0334b"; };

  };

  class StatusChangeResponse : public ros::Msg
  {
    public:
      typedef bool _switch_is_success_type;
      _switch_is_success_type switch_is_success;

    StatusChangeResponse():
      switch_is_success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_switch_is_success;
      u_switch_is_success.real = this->switch_is_success;
      *(outbuffer + offset + 0) = (u_switch_is_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->switch_is_success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_switch_is_success;
      u_switch_is_success.base = 0;
      u_switch_is_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->switch_is_success = u_switch_is_success.real;
      offset += sizeof(this->switch_is_success);
     return offset;
    }

    virtual const char * getType() override { return STATUSCHANGE; };
    virtual const char * getMD5() override { return "6b239f2cd0aa0d5816b7c3243eb924c4"; };

  };

  class StatusChange {
    public:
    typedef StatusChangeRequest Request;
    typedef StatusChangeResponse Response;
  };

}
#endif
