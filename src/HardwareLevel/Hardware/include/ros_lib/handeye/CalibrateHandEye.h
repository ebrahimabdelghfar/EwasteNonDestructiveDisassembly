#ifndef _ROS_SERVICE_CalibrateHandEye_h
#define _ROS_SERVICE_CalibrateHandEye_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"

namespace handeye
{

static const char CALIBRATEHANDEYE[] = "handeye/CalibrateHandEye";

  class CalibrateHandEyeRequest : public ros::Msg
  {
    public:
      typedef const char* _setup_type;
      _setup_type setup;
      typedef const char* _solver_type;
      _solver_type solver;
      typedef geometry_msgs::PoseArray _effector_wrt_world_type;
      _effector_wrt_world_type effector_wrt_world;
      typedef geometry_msgs::PoseArray _object_wrt_sensor_type;
      _object_wrt_sensor_type object_wrt_sensor;

    CalibrateHandEyeRequest():
      setup(""),
      solver(""),
      effector_wrt_world(),
      object_wrt_sensor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_setup = strlen(this->setup);
      varToArr(outbuffer + offset, length_setup);
      offset += 4;
      memcpy(outbuffer + offset, this->setup, length_setup);
      offset += length_setup;
      uint32_t length_solver = strlen(this->solver);
      varToArr(outbuffer + offset, length_solver);
      offset += 4;
      memcpy(outbuffer + offset, this->solver, length_solver);
      offset += length_solver;
      offset += this->effector_wrt_world.serialize(outbuffer + offset);
      offset += this->object_wrt_sensor.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_setup;
      arrToVar(length_setup, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_setup; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_setup-1]=0;
      this->setup = (char *)(inbuffer + offset-1);
      offset += length_setup;
      uint32_t length_solver;
      arrToVar(length_solver, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_solver; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_solver-1]=0;
      this->solver = (char *)(inbuffer + offset-1);
      offset += length_solver;
      offset += this->effector_wrt_world.deserialize(inbuffer + offset);
      offset += this->object_wrt_sensor.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CALIBRATEHANDEYE; };
    virtual const char * getMD5() override { return "9452c7113df2fa7160fa51c55eef0fd7"; };

  };

  class CalibrateHandEyeResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef geometry_msgs::Pose _sensor_frame_type;
      _sensor_frame_type sensor_frame;
      typedef double _rotation_rmse_type;
      _rotation_rmse_type rotation_rmse;
      typedef double _translation_rmse_type;
      _translation_rmse_type translation_rmse;

    CalibrateHandEyeResponse():
      success(0),
      sensor_frame(),
      rotation_rmse(0),
      translation_rmse(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      offset += this->sensor_frame.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_rotation_rmse;
      u_rotation_rmse.real = this->rotation_rmse;
      *(outbuffer + offset + 0) = (u_rotation_rmse.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotation_rmse.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotation_rmse.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotation_rmse.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rotation_rmse.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rotation_rmse.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rotation_rmse.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rotation_rmse.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rotation_rmse);
      union {
        double real;
        uint64_t base;
      } u_translation_rmse;
      u_translation_rmse.real = this->translation_rmse;
      *(outbuffer + offset + 0) = (u_translation_rmse.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_translation_rmse.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_translation_rmse.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_translation_rmse.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_translation_rmse.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_translation_rmse.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_translation_rmse.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_translation_rmse.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->translation_rmse);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      offset += this->sensor_frame.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_rotation_rmse;
      u_rotation_rmse.base = 0;
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rotation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rotation_rmse = u_rotation_rmse.real;
      offset += sizeof(this->rotation_rmse);
      union {
        double real;
        uint64_t base;
      } u_translation_rmse;
      u_translation_rmse.base = 0;
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_translation_rmse.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->translation_rmse = u_translation_rmse.real;
      offset += sizeof(this->translation_rmse);
     return offset;
    }

    virtual const char * getType() override { return CALIBRATEHANDEYE; };
    virtual const char * getMD5() override { return "a500c4ad906c1d8c5f99d37687460c1f"; };

  };

  class CalibrateHandEye {
    public:
    typedef CalibrateHandEyeRequest Request;
    typedef CalibrateHandEyeResponse Response;
  };

}
#endif
