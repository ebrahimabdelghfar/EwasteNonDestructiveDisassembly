#ifndef _ROS_dwb_msgs_TrajectoryScore_h
#define _ROS_dwb_msgs_TrajectoryScore_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dwb_msgs/Trajectory2D.h"
#include "dwb_msgs/CriticScore.h"

namespace dwb_msgs
{

  class TrajectoryScore : public ros::Msg
  {
    public:
      typedef dwb_msgs::Trajectory2D _traj_type;
      _traj_type traj;
      uint32_t scores_length;
      typedef dwb_msgs::CriticScore _scores_type;
      _scores_type st_scores;
      _scores_type * scores;
      typedef float _total_type;
      _total_type total;

    TrajectoryScore():
      traj(),
      scores_length(0), st_scores(), scores(nullptr),
      total(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->traj.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->scores_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scores_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scores_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scores_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scores_length);
      for( uint32_t i = 0; i < scores_length; i++){
      offset += this->scores[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_total;
      u_total.real = this->total;
      *(outbuffer + offset + 0) = (u_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->traj.deserialize(inbuffer + offset);
      uint32_t scores_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scores_length);
      if(scores_lengthT > scores_length)
        this->scores = (dwb_msgs::CriticScore*)realloc(this->scores, scores_lengthT * sizeof(dwb_msgs::CriticScore));
      scores_length = scores_lengthT;
      for( uint32_t i = 0; i < scores_length; i++){
      offset += this->st_scores.deserialize(inbuffer + offset);
        memcpy( &(this->scores[i]), &(this->st_scores), sizeof(dwb_msgs::CriticScore));
      }
      union {
        float real;
        uint32_t base;
      } u_total;
      u_total.base = 0;
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total = u_total.real;
      offset += sizeof(this->total);
     return offset;
    }

    virtual const char * getType() override { return "dwb_msgs/TrajectoryScore"; };
    virtual const char * getMD5() override { return "3d0da50e88d25d1140ba21d539b60c4b"; };

  };

}
#endif
