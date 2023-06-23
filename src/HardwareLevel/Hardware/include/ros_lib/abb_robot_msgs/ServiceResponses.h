#ifndef _ROS_abb_robot_msgs_ServiceResponses_h
#define _ROS_abb_robot_msgs_ServiceResponses_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace abb_robot_msgs
{

  class ServiceResponses : public ros::Msg
  {
    public:
      enum { SUCCESS = "" };
      enum { RC_SUCCESS = 1 };
      enum { FAILED = "Service failed (e.g. timeout or resource not found, see the DEBUG log for details)" };
      enum { RC_FAILED = 2 };
      enum { SERVER_IS_BUSY = "Server is busy" };
      enum { RC_SERVER_IS_BUSY = 1001 };
      enum { EMPTY_FILENAME = "Filename is empty" };
      enum { RC_EMPTY_FILENAME = 2001 };
      enum { EMPTY_SIGNAL_NAME = "Signal name is empty" };
      enum { RC_EMPTY_SIGNAL_NAME = 2002 };
      enum { EMPTY_RAPID_TASK_NAME = "RAPID task name is empty" };
      enum { RC_EMPTY_RAPID_TASK_NAME = 2003 };
      enum { EMPTY_RAPID_MODULE_NAME = "RAPID module name is empty" };
      enum { RC_EMPTY_RAPID_MODULE_NAME = 2004 };
      enum { EMPTY_RAPID_SYMBOL_NAME = "RAPID symbol name is empty" };
      enum { RC_EMPTY_RAPID_SYMBOL_NAME = 2005 };
      enum { NOT_IN_AUTO_MODE = "Robot controller is not in AUTO mode" };
      enum { RC_NOT_IN_AUTO_MODE = 3001 };
      enum { MOTORS_ARE_OFF = "Motors are off" };
      enum { RC_MOTORS_ARE_OFF = 3002 };
      enum { MOTORS_ARE_ON = "Motors are on" };
      enum { RC_MOTORS_ARE_ON = 3003 };
      enum { RAPID_NOT_STOPPED = "RAPID has not been stopped" };
      enum { RC_RAPID_NOT_STOPPED = 3004 };
      enum { RAPID_NOT_RUNNING = "RAPID is not running" };
      enum { RC_RAPID_NOT_RUNNING = 3005 };
      enum { SM_RUNTIME_STATES_MISSING = "No runtime states received for any StateMachine Add-In instance" };
      enum { RC_SM_RUNTIME_STATES_MISSING = 4001 };
      enum { SM_UNKNOWN_RAPID_TASK = "RAPID task not found among known StateMachine Add-In instances" };
      enum { RC_SM_UNKNOWN_RAPID_TASK = 4002 };
      enum { SM_UNINITIALIZED = "StateMachine Add-In instance has not been initialized" };
      enum { RC_SM_UNINITIALIZED = 4003 };

    ServiceResponses()
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

    virtual const char * getType() override { return "abb_robot_msgs/ServiceResponses"; };
    virtual const char * getMD5() override { return "c541477c2ff72df8851a0d0cd0b0b782"; };

  };

}
#endif
