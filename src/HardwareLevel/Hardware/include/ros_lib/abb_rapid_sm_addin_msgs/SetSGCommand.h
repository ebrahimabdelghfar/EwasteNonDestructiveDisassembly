#ifndef _ROS_SERVICE_SetSGCommand_h
#define _ROS_SERVICE_SetSGCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_rapid_sm_addin_msgs
{

static const char SETSGCOMMAND[] = "abb_rapid_sm_addin_msgs/SetSGCommand";

  class SetSGCommandRequest : public ros::Msg
  {
    public:
      typedef const char* _task_type;
      _task_type task;
      typedef uint8_t _command_type;
      _command_type command;
      typedef float _target_position_type;
      _target_position_type target_position;
      enum { SG_COMMAND_UNKNOWN =  1 };
      enum { SG_COMMAND_NONE =  2 };
      enum { SG_COMMAND_INITIALIZE =  3 };
      enum { SG_COMMAND_CALIBRATE =  4 };
      enum { SG_COMMAND_MOVE_TO =  5 };
      enum { SG_COMMAND_GRIP_IN =  6 };
      enum { SG_COMMAND_GRIP_OUT =  7 };
      enum { SG_COMMAND_BLOW_ON_1 =  8 };
      enum { SG_COMMAND_BLOW_ON_2 =  9 };
      enum { SG_COMMAND_BLOW_OFF_1 =  10 };
      enum { SG_COMMAND_BLOW_OFF_2 =  11 };
      enum { SG_COMMAND_VACUUM_ON_1 =  12 };
      enum { SG_COMMAND_VACUUM_ON_2 =  13 };
      enum { SG_COMMAND_VACUUM_OFF_1 =  14 };
      enum { SG_COMMAND_VACUUM_OFF_2 =  15 };

    SetSGCommandRequest():
      task(""),
      command(0),
      target_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_task = strlen(this->task);
      varToArr(outbuffer + offset, length_task);
      offset += 4;
      memcpy(outbuffer + offset, this->task, length_task);
      offset += length_task;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_target_position;
      u_target_position.real = this->target_position;
      *(outbuffer + offset + 0) = (u_target_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_task;
      arrToVar(length_task, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task-1]=0;
      this->task = (char *)(inbuffer + offset-1);
      offset += length_task;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_target_position;
      u_target_position.base = 0;
      u_target_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_position = u_target_position.real;
      offset += sizeof(this->target_position);
     return offset;
    }

    virtual const char * getType() override { return SETSGCOMMAND; };
    virtual const char * getMD5() override { return "8840583d66e469cae970ed301faf98c0"; };

  };

  class SetSGCommandResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetSGCommandResponse():
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->result_code >> (8 * 1)) & 0xFF;
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
      this->result_code =  ((uint16_t) (*(inbuffer + offset)));
      this->result_code |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
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

    virtual const char * getType() override { return SETSGCOMMAND; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetSGCommand {
    public:
    typedef SetSGCommandRequest Request;
    typedef SetSGCommandResponse Response;
  };

}
#endif
