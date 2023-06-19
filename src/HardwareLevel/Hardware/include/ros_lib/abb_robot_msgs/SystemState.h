#ifndef _ROS_abb_robot_msgs_SystemState_h
#define _ROS_abb_robot_msgs_SystemState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "abb_robot_msgs/RAPIDTaskState.h"
#include "abb_robot_msgs/MechanicalUnitState.h"

namespace abb_robot_msgs
{

  class SystemState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _motors_on_type;
      _motors_on_type motors_on;
      typedef bool _auto_mode_type;
      _auto_mode_type auto_mode;
      typedef bool _rapid_running_type;
      _rapid_running_type rapid_running;
      uint32_t rapid_tasks_length;
      typedef abb_robot_msgs::RAPIDTaskState _rapid_tasks_type;
      _rapid_tasks_type st_rapid_tasks;
      _rapid_tasks_type * rapid_tasks;
      uint32_t mechanical_units_length;
      typedef abb_robot_msgs::MechanicalUnitState _mechanical_units_type;
      _mechanical_units_type st_mechanical_units;
      _mechanical_units_type * mechanical_units;

    SystemState():
      header(),
      motors_on(0),
      auto_mode(0),
      rapid_running(0),
      rapid_tasks_length(0), st_rapid_tasks(), rapid_tasks(nullptr),
      mechanical_units_length(0), st_mechanical_units(), mechanical_units(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_motors_on;
      u_motors_on.real = this->motors_on;
      *(outbuffer + offset + 0) = (u_motors_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motors_on);
      union {
        bool real;
        uint8_t base;
      } u_auto_mode;
      u_auto_mode.real = this->auto_mode;
      *(outbuffer + offset + 0) = (u_auto_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_mode);
      union {
        bool real;
        uint8_t base;
      } u_rapid_running;
      u_rapid_running.real = this->rapid_running;
      *(outbuffer + offset + 0) = (u_rapid_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rapid_running);
      *(outbuffer + offset + 0) = (this->rapid_tasks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rapid_tasks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rapid_tasks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rapid_tasks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rapid_tasks_length);
      for( uint32_t i = 0; i < rapid_tasks_length; i++){
      offset += this->rapid_tasks[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->mechanical_units_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mechanical_units_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mechanical_units_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mechanical_units_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mechanical_units_length);
      for( uint32_t i = 0; i < mechanical_units_length; i++){
      offset += this->mechanical_units[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_motors_on;
      u_motors_on.base = 0;
      u_motors_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motors_on = u_motors_on.real;
      offset += sizeof(this->motors_on);
      union {
        bool real;
        uint8_t base;
      } u_auto_mode;
      u_auto_mode.base = 0;
      u_auto_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_mode = u_auto_mode.real;
      offset += sizeof(this->auto_mode);
      union {
        bool real;
        uint8_t base;
      } u_rapid_running;
      u_rapid_running.base = 0;
      u_rapid_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rapid_running = u_rapid_running.real;
      offset += sizeof(this->rapid_running);
      uint32_t rapid_tasks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rapid_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rapid_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rapid_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rapid_tasks_length);
      if(rapid_tasks_lengthT > rapid_tasks_length)
        this->rapid_tasks = (abb_robot_msgs::RAPIDTaskState*)realloc(this->rapid_tasks, rapid_tasks_lengthT * sizeof(abb_robot_msgs::RAPIDTaskState));
      rapid_tasks_length = rapid_tasks_lengthT;
      for( uint32_t i = 0; i < rapid_tasks_length; i++){
      offset += this->st_rapid_tasks.deserialize(inbuffer + offset);
        memcpy( &(this->rapid_tasks[i]), &(this->st_rapid_tasks), sizeof(abb_robot_msgs::RAPIDTaskState));
      }
      uint32_t mechanical_units_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mechanical_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mechanical_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mechanical_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mechanical_units_length);
      if(mechanical_units_lengthT > mechanical_units_length)
        this->mechanical_units = (abb_robot_msgs::MechanicalUnitState*)realloc(this->mechanical_units, mechanical_units_lengthT * sizeof(abb_robot_msgs::MechanicalUnitState));
      mechanical_units_length = mechanical_units_lengthT;
      for( uint32_t i = 0; i < mechanical_units_length; i++){
      offset += this->st_mechanical_units.deserialize(inbuffer + offset);
        memcpy( &(this->mechanical_units[i]), &(this->st_mechanical_units), sizeof(abb_robot_msgs::MechanicalUnitState));
      }
     return offset;
    }

    virtual const char * getType() override { return "abb_robot_msgs/SystemState"; };
    virtual const char * getMD5() override { return "46309669ed6ba4863375b03174d00ad7"; };

  };

}
#endif
