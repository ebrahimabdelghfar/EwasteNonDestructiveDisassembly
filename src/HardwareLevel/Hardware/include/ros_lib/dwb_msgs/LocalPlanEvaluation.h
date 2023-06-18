#ifndef _ROS_dwb_msgs_LocalPlanEvaluation_h
#define _ROS_dwb_msgs_LocalPlanEvaluation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dwb_msgs/TrajectoryScore.h"

namespace dwb_msgs
{

  class LocalPlanEvaluation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t twists_length;
      typedef dwb_msgs::TrajectoryScore _twists_type;
      _twists_type st_twists;
      _twists_type * twists;
      typedef uint16_t _best_index_type;
      _best_index_type best_index;
      typedef uint16_t _worst_index_type;
      _worst_index_type worst_index;

    LocalPlanEvaluation():
      header(),
      twists_length(0), st_twists(), twists(nullptr),
      best_index(0),
      worst_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->twists_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twists_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twists_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twists_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twists_length);
      for( uint32_t i = 0; i < twists_length; i++){
      offset += this->twists[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->best_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->best_index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->best_index);
      *(outbuffer + offset + 0) = (this->worst_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->worst_index >> (8 * 1)) & 0xFF;
      offset += sizeof(this->worst_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t twists_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twists_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->twists_length);
      if(twists_lengthT > twists_length)
        this->twists = (dwb_msgs::TrajectoryScore*)realloc(this->twists, twists_lengthT * sizeof(dwb_msgs::TrajectoryScore));
      twists_length = twists_lengthT;
      for( uint32_t i = 0; i < twists_length; i++){
      offset += this->st_twists.deserialize(inbuffer + offset);
        memcpy( &(this->twists[i]), &(this->st_twists), sizeof(dwb_msgs::TrajectoryScore));
      }
      this->best_index =  ((uint16_t) (*(inbuffer + offset)));
      this->best_index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->best_index);
      this->worst_index =  ((uint16_t) (*(inbuffer + offset)));
      this->worst_index |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->worst_index);
     return offset;
    }

    virtual const char * getType() override { return "dwb_msgs/LocalPlanEvaluation"; };
    virtual const char * getMD5() override { return "d360642012ea44ee598913c70498aa4b"; };

  };

}
#endif
