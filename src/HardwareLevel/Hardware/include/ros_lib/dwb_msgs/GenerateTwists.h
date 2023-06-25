#ifndef _ROS_SERVICE_GenerateTwists_h
#define _ROS_SERVICE_GenerateTwists_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Twist2D.h"

namespace dwb_msgs
{

static const char GENERATETWISTS[] = "dwb_msgs/GenerateTwists";

  class GenerateTwistsRequest : public ros::Msg
  {
    public:
      typedef nav_2d_msgs::Twist2D _current_vel_type;
      _current_vel_type current_vel;

    GenerateTwistsRequest():
      current_vel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->current_vel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->current_vel.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GENERATETWISTS; };
    virtual const char * getMD5() override { return "9b565023e01bba3608d16ec34d67c081"; };

  };

  class GenerateTwistsResponse : public ros::Msg
  {
    public:
      uint32_t twists_length;
      typedef nav_2d_msgs::Twist2D _twists_type;
      _twists_type st_twists;
      _twists_type * twists;

    GenerateTwistsResponse():
      twists_length(0), st_twists(), twists(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->twists_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twists_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twists_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twists_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twists_length);
      for( uint32_t i = 0; i < twists_length; i++){
      offset += this->twists[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t twists_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->twists_length);
      if(twists_lengthT > twists_length)
        this->twists = (nav_2d_msgs::Twist2D*)realloc(this->twists, twists_lengthT * sizeof(nav_2d_msgs::Twist2D));
      twists_length = twists_lengthT;
      for( uint32_t i = 0; i < twists_length; i++){
      offset += this->st_twists.deserialize(inbuffer + offset);
        memcpy( &(this->twists[i]), &(this->st_twists), sizeof(nav_2d_msgs::Twist2D));
      }
     return offset;
    }

    virtual const char * getType() override { return GENERATETWISTS; };
    virtual const char * getMD5() override { return "ca457e77ab95ba074b796555f7e74efe"; };

  };

  class GenerateTwists {
    public:
    typedef GenerateTwistsRequest Request;
    typedef GenerateTwistsResponse Response;
  };

}
#endif
