#ifndef _ROS_dwb_msgs_Trajectory2D_h
#define _ROS_dwb_msgs_Trajectory2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_2d_msgs/Twist2D.h"
#include "geometry_msgs/Pose2D.h"
#include "ros/duration.h"

namespace dwb_msgs
{

  class Trajectory2D : public ros::Msg
  {
    public:
      typedef nav_2d_msgs::Twist2D _velocity_type;
      _velocity_type velocity;
      uint32_t poses_length;
      typedef geometry_msgs::Pose2D _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t time_offsets_length;
      typedef ros::Duration _time_offsets_type;
      _time_offsets_type st_time_offsets;
      _time_offsets_type * time_offsets;

    Trajectory2D():
      velocity(),
      poses_length(0), st_poses(), poses(nullptr),
      time_offsets_length(0), st_time_offsets(), time_offsets(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->velocity.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->time_offsets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_offsets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_offsets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_offsets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_offsets_length);
      for( uint32_t i = 0; i < time_offsets_length; i++){
      *(outbuffer + offset + 0) = (this->time_offsets[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_offsets[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_offsets[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_offsets[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_offsets[i].sec);
      *(outbuffer + offset + 0) = (this->time_offsets[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_offsets[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_offsets[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_offsets[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_offsets[i].nsec);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->velocity.deserialize(inbuffer + offset);
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose2D*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose2D));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose2D));
      }
      uint32_t time_offsets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_offsets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_offsets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_offsets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_offsets_length);
      if(time_offsets_lengthT > time_offsets_length)
        this->time_offsets = (ros::Duration*)realloc(this->time_offsets, time_offsets_lengthT * sizeof(ros::Duration));
      time_offsets_length = time_offsets_lengthT;
      for( uint32_t i = 0; i < time_offsets_length; i++){
      this->st_time_offsets.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_offsets.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_offsets.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_offsets.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_offsets.sec);
      this->st_time_offsets.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_offsets.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_offsets.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_offsets.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_offsets.nsec);
        memcpy( &(this->time_offsets[i]), &(this->st_time_offsets), sizeof(ros::Duration));
      }
     return offset;
    }

    virtual const char * getType() override { return "dwb_msgs/Trajectory2D"; };
    virtual const char * getMD5() override { return "cabdc5bddc0dd1dcdc6b8f29fcb7ebcb"; };

  };

}
#endif
