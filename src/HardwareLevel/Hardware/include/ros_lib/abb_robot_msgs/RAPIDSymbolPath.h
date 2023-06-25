#ifndef _ROS_abb_robot_msgs_RAPIDSymbolPath_h
#define _ROS_abb_robot_msgs_RAPIDSymbolPath_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

  class RAPIDSymbolPath : public ros::Msg
  {
    public:
      typedef const char* _task_type;
      _task_type task;
      typedef const char* _module_type;
      _module_type module;
      typedef const char* _symbol_type;
      _symbol_type symbol;

    RAPIDSymbolPath():
      task(""),
      module(""),
      symbol("")
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
      uint32_t length_module = strlen(this->module);
      varToArr(outbuffer + offset, length_module);
      offset += 4;
      memcpy(outbuffer + offset, this->module, length_module);
      offset += length_module;
      uint32_t length_symbol = strlen(this->symbol);
      varToArr(outbuffer + offset, length_symbol);
      offset += 4;
      memcpy(outbuffer + offset, this->symbol, length_symbol);
      offset += length_symbol;
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
      uint32_t length_module;
      arrToVar(length_module, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_module; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_module-1]=0;
      this->module = (char *)(inbuffer + offset-1);
      offset += length_module;
      uint32_t length_symbol;
      arrToVar(length_symbol, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_symbol; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_symbol-1]=0;
      this->symbol = (char *)(inbuffer + offset-1);
      offset += length_symbol;
     return offset;
    }

    virtual const char * getType() override { return "abb_robot_msgs/RAPIDSymbolPath"; };
    virtual const char * getMD5() override { return "3214a5a49942fc04a524a160d9874980"; };

  };

}
#endif
