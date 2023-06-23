#ifndef _ROS_trajectory_tracker_msgs_PathWithVelocity_h
#define _ROS_trajectory_tracker_msgs_PathWithVelocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "trajectory_tracker_msgs/PoseStampedWithVelocity.h"

namespace trajectory_tracker_msgs
{

  class PathWithVelocity : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t poses_length;
      typedef trajectory_tracker_msgs::PoseStampedWithVelocity _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    PathWithVelocity():
      header(),
      poses_length(0), st_poses(), poses(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (trajectory_tracker_msgs::PoseStampedWithVelocity*)realloc(this->poses, poses_lengthT * sizeof(trajectory_tracker_msgs::PoseStampedWithVelocity));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(trajectory_tracker_msgs::PoseStampedWithVelocity));
      }
     return offset;
    }

    virtual const char * getType() override { return "trajectory_tracker_msgs/PathWithVelocity"; };
    virtual const char * getMD5() override { return "2ea8c54fd8ddd9fbc5f19046889c0f4e"; };

  };

}
#endif
