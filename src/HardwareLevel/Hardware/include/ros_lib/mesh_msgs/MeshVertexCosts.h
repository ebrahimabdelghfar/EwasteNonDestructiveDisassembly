#ifndef _ROS_mesh_msgs_MeshVertexCosts_h
#define _ROS_mesh_msgs_MeshVertexCosts_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mesh_msgs
{

  class MeshVertexCosts : public ros::Msg
  {
    public:
      uint32_t costs_length;
      typedef float _costs_type;
      _costs_type st_costs;
      _costs_type * costs;

    MeshVertexCosts():
      costs_length(0), st_costs(), costs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->costs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->costs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->costs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->costs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->costs_length);
      for( uint32_t i = 0; i < costs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_costsi;
      u_costsi.real = this->costs[i];
      *(outbuffer + offset + 0) = (u_costsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_costsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_costsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_costsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->costs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t costs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->costs_length);
      if(costs_lengthT > costs_length)
        this->costs = (float*)realloc(this->costs, costs_lengthT * sizeof(float));
      costs_length = costs_lengthT;
      for( uint32_t i = 0; i < costs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_costs;
      u_st_costs.base = 0;
      u_st_costs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_costs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_costs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_costs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_costs = u_st_costs.real;
      offset += sizeof(this->st_costs);
        memcpy( &(this->costs[i]), &(this->st_costs), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "mesh_msgs/MeshVertexCosts"; };
    virtual const char * getMD5() override { return "ade4ce6a157397b6c023e12482bc76c8"; };

  };

}
#endif
