#ifndef _ROS_locomotor_msgs_NavigateToPoseFeedback_h
#define _ROS_locomotor_msgs_NavigateToPoseFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "locomotor_msgs/NavigationState.h"

namespace locomotor_msgs
{

  class NavigateToPoseFeedback : public ros::Msg
  {
    public:
      typedef locomotor_msgs::NavigationState _state_type;
      _state_type state;
      typedef float _percent_complete_type;
      _percent_complete_type percent_complete;
      typedef float _distance_traveled_type;
      _distance_traveled_type distance_traveled;
      typedef float _estimated_distance_remaining_type;
      _estimated_distance_remaining_type estimated_distance_remaining;

    NavigateToPoseFeedback():
      state(),
      percent_complete(0),
      distance_traveled(0),
      estimated_distance_remaining(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_percent_complete;
      u_percent_complete.real = this->percent_complete;
      *(outbuffer + offset + 0) = (u_percent_complete.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percent_complete.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percent_complete.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percent_complete.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percent_complete);
      union {
        float real;
        uint32_t base;
      } u_distance_traveled;
      u_distance_traveled.real = this->distance_traveled;
      *(outbuffer + offset + 0) = (u_distance_traveled.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_traveled.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_traveled.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_traveled.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_traveled);
      union {
        float real;
        uint32_t base;
      } u_estimated_distance_remaining;
      u_estimated_distance_remaining.real = this->estimated_distance_remaining;
      *(outbuffer + offset + 0) = (u_estimated_distance_remaining.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_estimated_distance_remaining.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_estimated_distance_remaining.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_estimated_distance_remaining.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_distance_remaining);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_percent_complete;
      u_percent_complete.base = 0;
      u_percent_complete.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percent_complete.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percent_complete.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percent_complete.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percent_complete = u_percent_complete.real;
      offset += sizeof(this->percent_complete);
      union {
        float real;
        uint32_t base;
      } u_distance_traveled;
      u_distance_traveled.base = 0;
      u_distance_traveled.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_traveled.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_traveled.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_traveled.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_traveled = u_distance_traveled.real;
      offset += sizeof(this->distance_traveled);
      union {
        float real;
        uint32_t base;
      } u_estimated_distance_remaining;
      u_estimated_distance_remaining.base = 0;
      u_estimated_distance_remaining.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_estimated_distance_remaining.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_estimated_distance_remaining.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_estimated_distance_remaining.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->estimated_distance_remaining = u_estimated_distance_remaining.real;
      offset += sizeof(this->estimated_distance_remaining);
     return offset;
    }

    virtual const char * getType() override { return "locomotor_msgs/NavigateToPoseFeedback"; };
    virtual const char * getMD5() override { return "731b38cf0756acb428661980c367590e"; };

  };

}
#endif
