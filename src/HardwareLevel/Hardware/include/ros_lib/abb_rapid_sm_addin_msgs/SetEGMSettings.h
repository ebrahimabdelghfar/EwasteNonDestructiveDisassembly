#ifndef _ROS_SERVICE_SetEGMSettings_h
#define _ROS_SERVICE_SetEGMSettings_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "abb_rapid_sm_addin_msgs/EGMSettings.h"

namespace abb_rapid_sm_addin_msgs
{

static const char SETEGMSETTINGS[] = "abb_rapid_sm_addin_msgs/SetEGMSettings";

  class SetEGMSettingsRequest : public ros::Msg
  {
    public:
      typedef const char* _task_type;
      _task_type task;
      typedef abb_rapid_sm_addin_msgs::EGMSettings _settings_type;
      _settings_type settings;

    SetEGMSettingsRequest():
      task(""),
      settings()
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
      offset += this->settings.serialize(outbuffer + offset);
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
      offset += this->settings.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETEGMSETTINGS; };
    virtual const char * getMD5() override { return "081e736ac1ee21b823542360d17eb3ae"; };

  };

  class SetEGMSettingsResponse : public ros::Msg
  {
    public:
      typedef uint16_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _message_type;
      _message_type message;

    SetEGMSettingsResponse():
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

    virtual const char * getType() override { return SETEGMSETTINGS; };
    virtual const char * getMD5() override { return "aab0cc4b756aaf08eb67ad6459b36b27"; };

  };

  class SetEGMSettings {
    public:
    typedef SetEGMSettingsRequest Request;
    typedef SetEGMSettingsResponse Response;
  };

}
#endif
