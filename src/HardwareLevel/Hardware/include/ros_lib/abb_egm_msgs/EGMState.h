#ifndef _ROS_abb_egm_msgs_EGMState_h
#define _ROS_abb_egm_msgs_EGMState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "abb_egm_msgs/EGMChannelState.h"

namespace abb_egm_msgs
{

  class EGMState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t egm_channels_length;
      typedef abb_egm_msgs::EGMChannelState _egm_channels_type;
      _egm_channels_type st_egm_channels;
      _egm_channels_type * egm_channels;

    EGMState():
      header(),
      egm_channels_length(0), st_egm_channels(), egm_channels(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->egm_channels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->egm_channels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->egm_channels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->egm_channels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->egm_channels_length);
      for( uint32_t i = 0; i < egm_channels_length; i++){
      offset += this->egm_channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t egm_channels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      egm_channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      egm_channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      egm_channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->egm_channels_length);
      if(egm_channels_lengthT > egm_channels_length)
        this->egm_channels = (abb_egm_msgs::EGMChannelState*)realloc(this->egm_channels, egm_channels_lengthT * sizeof(abb_egm_msgs::EGMChannelState));
      egm_channels_length = egm_channels_lengthT;
      for( uint32_t i = 0; i < egm_channels_length; i++){
      offset += this->st_egm_channels.deserialize(inbuffer + offset);
        memcpy( &(this->egm_channels[i]), &(this->st_egm_channels), sizeof(abb_egm_msgs::EGMChannelState));
      }
     return offset;
    }

    virtual const char * getType() override { return "abb_egm_msgs/EGMState"; };
    virtual const char * getMD5() override { return "a239c0f02980c16cd34f9e56fbc03ff7"; };

  };

}
#endif
