#ifndef _ROS_SERVICE_Schedular_h
#define _ROS_SERVICE_Schedular_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace CentralNode
{

static const char SCHEDULAR[] = "CentralNode/Schedular";

  class SchedularRequest : public ros::Msg
  {
    public:

    SchedularRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SCHEDULAR; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SchedularResponse : public ros::Msg
  {
    public:
      uint32_t waypoints_length;
      typedef double _waypoints_type;
      _waypoints_type st_waypoints;
      _waypoints_type * waypoints;
      uint32_t waypoint_types_length;
      typedef int32_t _waypoint_types_type;
      _waypoint_types_type st_waypoint_types;
      _waypoint_types_type * waypoint_types;

    SchedularResponse():
      waypoints_length(0), st_waypoints(), waypoints(nullptr),
      waypoint_types_length(0), st_waypoint_types(), waypoint_types(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->waypoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->waypoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->waypoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->waypoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoints_length);
      for( uint32_t i = 0; i < waypoints_length; i++){
      union {
        double real;
        uint64_t base;
      } u_waypointsi;
      u_waypointsi.real = this->waypoints[i];
      *(outbuffer + offset + 0) = (u_waypointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypointsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_waypointsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_waypointsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_waypointsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_waypointsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->waypoints[i]);
      }
      *(outbuffer + offset + 0) = (this->waypoint_types_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->waypoint_types_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->waypoint_types_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->waypoint_types_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoint_types_length);
      for( uint32_t i = 0; i < waypoint_types_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_waypoint_typesi;
      u_waypoint_typesi.real = this->waypoint_types[i];
      *(outbuffer + offset + 0) = (u_waypoint_typesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypoint_typesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypoint_typesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypoint_typesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoint_types[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t waypoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->waypoints_length);
      if(waypoints_lengthT > waypoints_length)
        this->waypoints = (double*)realloc(this->waypoints, waypoints_lengthT * sizeof(double));
      waypoints_length = waypoints_lengthT;
      for( uint32_t i = 0; i < waypoints_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_waypoints;
      u_st_waypoints.base = 0;
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_waypoints.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_waypoints = u_st_waypoints.real;
      offset += sizeof(this->st_waypoints);
        memcpy( &(this->waypoints[i]), &(this->st_waypoints), sizeof(double));
      }
      uint32_t waypoint_types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      waypoint_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      waypoint_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      waypoint_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->waypoint_types_length);
      if(waypoint_types_lengthT > waypoint_types_length)
        this->waypoint_types = (int32_t*)realloc(this->waypoint_types, waypoint_types_lengthT * sizeof(int32_t));
      waypoint_types_length = waypoint_types_lengthT;
      for( uint32_t i = 0; i < waypoint_types_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_waypoint_types;
      u_st_waypoint_types.base = 0;
      u_st_waypoint_types.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_waypoint_types.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_waypoint_types.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_waypoint_types.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_waypoint_types = u_st_waypoint_types.real;
      offset += sizeof(this->st_waypoint_types);
        memcpy( &(this->waypoint_types[i]), &(this->st_waypoint_types), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return SCHEDULAR; };
    virtual const char * getMD5() override { return "ab7b1b43f5a75abfd5d43934103bc4a6"; };

  };

  class Schedular {
    public:
    typedef SchedularRequest Request;
    typedef SchedularResponse Response;
  };

}
#endif
