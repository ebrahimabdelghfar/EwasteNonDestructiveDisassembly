#ifndef _ROS_locomotor_msgs_ResultCode_h
#define _ROS_locomotor_msgs_ResultCode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace locomotor_msgs
{

  class ResultCode : public ros::Msg
  {
    public:
      typedef int32_t _component_type;
      _component_type component;
      typedef int32_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;
      enum { GLOBAL_COSTMAP =  1 };
      enum { LOCAL_COSTMAP =  2 };
      enum { GLOBAL_PLANNER =  4 };
      enum { LOCAL_PLANNER =  8 };
      enum { GENERIC_COSTMAP = 0 };
      enum { COSTMAP_SAFETY = 1 };
      enum { COSTMAP_DATA_LAG = 2 };
      enum { GENERIC_PLANNER = 3 };
      enum { GENERIC_GLOBAL_PLANNER = 4 };
      enum { INVALID_START = 5 };
      enum { START_BOUNDS = 6 };
      enum { OCCUPIED_START = 7 };
      enum { INVALID_GOAL = 8 };
      enum { GOAL_BOUNDS = 9 };
      enum { OCCUPIED_GOAL = 10 };
      enum { NO_GLOBAL_PATH = 11 };
      enum { GLOBAL_PLANNER_TIMEOUT = 12 };
      enum { GENERIC_LOCAL_PLANNER = 13 };
      enum { ILLEGAL_TRAJECTORY = 14 };
      enum { NO_LEGAL_TRAJECTORIES = 15 };
      enum { PLANNER_TF = 16 };

    ResultCode():
      component(0),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_component;
      u_component.real = this->component;
      *(outbuffer + offset + 0) = (u_component.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_component.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_component.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_component.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->component);
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.real = this->result_code;
      *(outbuffer + offset + 0) = (u_result_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result_code);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_component;
      u_component.base = 0;
      u_component.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_component.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_component.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_component.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->component = u_component.real;
      offset += sizeof(this->component);
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.base = 0;
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result_code = u_result_code.real;
      offset += sizeof(this->result_code);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return "locomotor_msgs/ResultCode"; };
    virtual const char * getMD5() override { return "9c162cbf5db9d590e1047c78cbd90371"; };

  };

}
#endif
