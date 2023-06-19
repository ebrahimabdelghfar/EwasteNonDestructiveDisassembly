#ifndef _ROS_SERVICE_GetEGMSettings_h
#define _ROS_SERVICE_GetEGMSettings_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_sm_addin_msgs/EGMSettings.h"

namespace abb_rapid_sm_addin_msgs
{

static const char GETEGMSETTINGS[] = "abb_rapid_sm_addin_msgs/GetEGMSettings";

  class GetEGMSettingsRequest : public ros::Msg
  {
    public:
      typedef const char* _task_type;
      _task_type task;

    GetEGMSettingsRequest():
      task("")
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
     return offset;
    }

    virtual const char * getType() override { return GETEGMSETTINGS; };
    virtual const char * getMD5() override { return "0ece8f504419f7ca4d91b277e47ff617"; };

  };

  class GetEGMSettingsResponse : public ros::Msg
  {
    public:
      typedef abb_rapid_sm_addin_msgs::EGMSettings _settings_type;
      _settings_type settings;
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    GetEGMSettingsResponse():
      settings(),
      result_code(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->settings.serialize(outbuffer + offset);
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
      offset += this->settings.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return GETEGMSETTINGS; };
    virtual const char * getMD5() override { return "e1f4c6b9730a3324dc0ac94d49b23bf7"; };

  };

  class GetEGMSettings {
    public:
    typedef GetEGMSettingsRequest Request;
    typedef GetEGMSettingsResponse Response;
  };

}
#endif
