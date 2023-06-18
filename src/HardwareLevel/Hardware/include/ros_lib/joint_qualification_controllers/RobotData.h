#ifndef _ROS_joint_qualification_controllers_RobotData_h
#define _ROS_joint_qualification_controllers_RobotData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "joint_qualification_controllers/JointData.h"
#include "joint_qualification_controllers/ActuatorData.h"

namespace joint_qualification_controllers
{

  class RobotData : public ros::Msg
  {
    public:
      typedef float _test_time_type;
      _test_time_type test_time;
      typedef bool _timeout_type;
      _timeout_type timeout;
      typedef int32_t _num_joints_type;
      _num_joints_type num_joints;
      typedef int32_t _num_actuators_type;
      _num_actuators_type num_actuators;
      uint32_t joint_data_length;
      typedef joint_qualification_controllers::JointData _joint_data_type;
      _joint_data_type st_joint_data;
      _joint_data_type * joint_data;
      uint32_t actuator_data_length;
      typedef joint_qualification_controllers::ActuatorData _actuator_data_type;
      _actuator_data_type st_actuator_data;
      _actuator_data_type * actuator_data;

    RobotData():
      test_time(0),
      timeout(0),
      num_joints(0),
      num_actuators(0),
      joint_data_length(0), st_joint_data(), joint_data(nullptr),
      actuator_data_length(0), st_actuator_data(), actuator_data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_test_time;
      u_test_time.real = this->test_time;
      *(outbuffer + offset + 0) = (u_test_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_test_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_test_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_test_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->test_time);
      union {
        bool real;
        uint8_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_num_joints;
      u_num_joints.real = this->num_joints;
      *(outbuffer + offset + 0) = (u_num_joints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_joints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_joints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_joints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_joints);
      union {
        int32_t real;
        uint32_t base;
      } u_num_actuators;
      u_num_actuators.real = this->num_actuators;
      *(outbuffer + offset + 0) = (u_num_actuators.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_actuators.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_actuators.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_actuators.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_actuators);
      *(outbuffer + offset + 0) = (this->joint_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_data_length);
      for( uint32_t i = 0; i < joint_data_length; i++){
      offset += this->joint_data[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->actuator_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actuator_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->actuator_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->actuator_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actuator_data_length);
      for( uint32_t i = 0; i < actuator_data_length; i++){
      offset += this->actuator_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_test_time;
      u_test_time.base = 0;
      u_test_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_test_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_test_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_test_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->test_time = u_test_time.real;
      offset += sizeof(this->test_time);
      union {
        bool real;
        uint8_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_num_joints;
      u_num_joints.base = 0;
      u_num_joints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_joints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_joints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_joints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_joints = u_num_joints.real;
      offset += sizeof(this->num_joints);
      union {
        int32_t real;
        uint32_t base;
      } u_num_actuators;
      u_num_actuators.base = 0;
      u_num_actuators.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_actuators.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_actuators.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_actuators.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_actuators = u_num_actuators.real;
      offset += sizeof(this->num_actuators);
      uint32_t joint_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_data_length);
      if(joint_data_lengthT > joint_data_length)
        this->joint_data = (joint_qualification_controllers::JointData*)realloc(this->joint_data, joint_data_lengthT * sizeof(joint_qualification_controllers::JointData));
      joint_data_length = joint_data_lengthT;
      for( uint32_t i = 0; i < joint_data_length; i++){
      offset += this->st_joint_data.deserialize(inbuffer + offset);
        memcpy( &(this->joint_data[i]), &(this->st_joint_data), sizeof(joint_qualification_controllers::JointData));
      }
      uint32_t actuator_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      actuator_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      actuator_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      actuator_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->actuator_data_length);
      if(actuator_data_lengthT > actuator_data_length)
        this->actuator_data = (joint_qualification_controllers::ActuatorData*)realloc(this->actuator_data, actuator_data_lengthT * sizeof(joint_qualification_controllers::ActuatorData));
      actuator_data_length = actuator_data_lengthT;
      for( uint32_t i = 0; i < actuator_data_length; i++){
      offset += this->st_actuator_data.deserialize(inbuffer + offset);
        memcpy( &(this->actuator_data[i]), &(this->st_actuator_data), sizeof(joint_qualification_controllers::ActuatorData));
      }
     return offset;
    }

    virtual const char * getType() override { return "joint_qualification_controllers/RobotData"; };
    virtual const char * getMD5() override { return "025931e8023fe22bd8228a980121730a"; };

  };

}
#endif
