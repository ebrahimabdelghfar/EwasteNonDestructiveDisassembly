// Generated by gencpp from file abb_robot_msgs/ServiceResponses.msg
// DO NOT EDIT!


#ifndef ABB_ROBOT_MSGS_MESSAGE_SERVICERESPONSES_H
#define ABB_ROBOT_MSGS_MESSAGE_SERVICERESPONSES_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace abb_robot_msgs
{
template <class ContainerAllocator>
struct ServiceResponses_
{
  typedef ServiceResponses_<ContainerAllocator> Type;

  ServiceResponses_()
    {
    }
  ServiceResponses_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }





// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(SUCCESS)
  #undef SUCCESS
#endif
#if defined(_WIN32) && defined(RC_SUCCESS)
  #undef RC_SUCCESS
#endif
#if defined(_WIN32) && defined(FAILED)
  #undef FAILED
#endif
#if defined(_WIN32) && defined(RC_FAILED)
  #undef RC_FAILED
#endif
#if defined(_WIN32) && defined(SERVER_IS_BUSY)
  #undef SERVER_IS_BUSY
#endif
#if defined(_WIN32) && defined(RC_SERVER_IS_BUSY)
  #undef RC_SERVER_IS_BUSY
#endif
#if defined(_WIN32) && defined(EMPTY_FILENAME)
  #undef EMPTY_FILENAME
#endif
#if defined(_WIN32) && defined(RC_EMPTY_FILENAME)
  #undef RC_EMPTY_FILENAME
#endif
#if defined(_WIN32) && defined(EMPTY_SIGNAL_NAME)
  #undef EMPTY_SIGNAL_NAME
#endif
#if defined(_WIN32) && defined(RC_EMPTY_SIGNAL_NAME)
  #undef RC_EMPTY_SIGNAL_NAME
#endif
#if defined(_WIN32) && defined(EMPTY_RAPID_TASK_NAME)
  #undef EMPTY_RAPID_TASK_NAME
#endif
#if defined(_WIN32) && defined(RC_EMPTY_RAPID_TASK_NAME)
  #undef RC_EMPTY_RAPID_TASK_NAME
#endif
#if defined(_WIN32) && defined(EMPTY_RAPID_MODULE_NAME)
  #undef EMPTY_RAPID_MODULE_NAME
#endif
#if defined(_WIN32) && defined(RC_EMPTY_RAPID_MODULE_NAME)
  #undef RC_EMPTY_RAPID_MODULE_NAME
#endif
#if defined(_WIN32) && defined(EMPTY_RAPID_SYMBOL_NAME)
  #undef EMPTY_RAPID_SYMBOL_NAME
#endif
#if defined(_WIN32) && defined(RC_EMPTY_RAPID_SYMBOL_NAME)
  #undef RC_EMPTY_RAPID_SYMBOL_NAME
#endif
#if defined(_WIN32) && defined(NOT_IN_AUTO_MODE)
  #undef NOT_IN_AUTO_MODE
#endif
#if defined(_WIN32) && defined(RC_NOT_IN_AUTO_MODE)
  #undef RC_NOT_IN_AUTO_MODE
#endif
#if defined(_WIN32) && defined(MOTORS_ARE_OFF)
  #undef MOTORS_ARE_OFF
#endif
#if defined(_WIN32) && defined(RC_MOTORS_ARE_OFF)
  #undef RC_MOTORS_ARE_OFF
#endif
#if defined(_WIN32) && defined(MOTORS_ARE_ON)
  #undef MOTORS_ARE_ON
#endif
#if defined(_WIN32) && defined(RC_MOTORS_ARE_ON)
  #undef RC_MOTORS_ARE_ON
#endif
#if defined(_WIN32) && defined(RAPID_NOT_STOPPED)
  #undef RAPID_NOT_STOPPED
#endif
#if defined(_WIN32) && defined(RC_RAPID_NOT_STOPPED)
  #undef RC_RAPID_NOT_STOPPED
#endif
#if defined(_WIN32) && defined(RAPID_NOT_RUNNING)
  #undef RAPID_NOT_RUNNING
#endif
#if defined(_WIN32) && defined(RC_RAPID_NOT_RUNNING)
  #undef RC_RAPID_NOT_RUNNING
#endif
#if defined(_WIN32) && defined(SM_RUNTIME_STATES_MISSING)
  #undef SM_RUNTIME_STATES_MISSING
#endif
#if defined(_WIN32) && defined(RC_SM_RUNTIME_STATES_MISSING)
  #undef RC_SM_RUNTIME_STATES_MISSING
#endif
#if defined(_WIN32) && defined(SM_UNKNOWN_RAPID_TASK)
  #undef SM_UNKNOWN_RAPID_TASK
#endif
#if defined(_WIN32) && defined(RC_SM_UNKNOWN_RAPID_TASK)
  #undef RC_SM_UNKNOWN_RAPID_TASK
#endif
#if defined(_WIN32) && defined(SM_UNINITIALIZED)
  #undef SM_UNINITIALIZED
#endif
#if defined(_WIN32) && defined(RC_SM_UNINITIALIZED)
  #undef RC_SM_UNINITIALIZED
#endif

  enum {
    RC_SUCCESS = 1u,
    RC_FAILED = 2u,
    RC_SERVER_IS_BUSY = 1001u,
    RC_EMPTY_FILENAME = 2001u,
    RC_EMPTY_SIGNAL_NAME = 2002u,
    RC_EMPTY_RAPID_TASK_NAME = 2003u,
    RC_EMPTY_RAPID_MODULE_NAME = 2004u,
    RC_EMPTY_RAPID_SYMBOL_NAME = 2005u,
    RC_NOT_IN_AUTO_MODE = 3001u,
    RC_MOTORS_ARE_OFF = 3002u,
    RC_MOTORS_ARE_ON = 3003u,
    RC_RAPID_NOT_STOPPED = 3004u,
    RC_RAPID_NOT_RUNNING = 3005u,
    RC_SM_RUNTIME_STATES_MISSING = 4001u,
    RC_SM_UNKNOWN_RAPID_TASK = 4002u,
    RC_SM_UNINITIALIZED = 4003u,
  };

  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SUCCESS;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FAILED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SERVER_IS_BUSY;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMPTY_FILENAME;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMPTY_SIGNAL_NAME;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMPTY_RAPID_TASK_NAME;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMPTY_RAPID_MODULE_NAME;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> EMPTY_RAPID_SYMBOL_NAME;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> NOT_IN_AUTO_MODE;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MOTORS_ARE_OFF;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MOTORS_ARE_ON;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> RAPID_NOT_STOPPED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> RAPID_NOT_RUNNING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SM_RUNTIME_STATES_MISSING;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SM_UNKNOWN_RAPID_TASK;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SM_UNINITIALIZED;

  typedef boost::shared_ptr< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> const> ConstPtr;

}; // struct ServiceResponses_

typedef ::abb_robot_msgs::ServiceResponses_<std::allocator<void> > ServiceResponses;

typedef boost::shared_ptr< ::abb_robot_msgs::ServiceResponses > ServiceResponsesPtr;
typedef boost::shared_ptr< ::abb_robot_msgs::ServiceResponses const> ServiceResponsesConstPtr;

// constants requiring out of line definition

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::SUCCESS =
        
          "\"\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::FAILED =
        
          "\"Service failed (e.g. timeout or resource not found, see the DEBUG log for details)\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::SERVER_IS_BUSY =
        
          "\"Server is busy\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::EMPTY_FILENAME =
        
          "\"Filename is empty\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::EMPTY_SIGNAL_NAME =
        
          "\"Signal name is empty\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::EMPTY_RAPID_TASK_NAME =
        
          "\"RAPID task name is empty\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::EMPTY_RAPID_MODULE_NAME =
        
          "\"RAPID module name is empty\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::EMPTY_RAPID_SYMBOL_NAME =
        
          "\"RAPID symbol name is empty\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::NOT_IN_AUTO_MODE =
        
          "\"Robot controller is not in AUTO mode\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::MOTORS_ARE_OFF =
        
          "\"Motors are off\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::MOTORS_ARE_ON =
        
          "\"Motors are on\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::RAPID_NOT_STOPPED =
        
          "\"RAPID has not been stopped\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::RAPID_NOT_RUNNING =
        
          "\"RAPID is not running\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::SM_RUNTIME_STATES_MISSING =
        
          "\"No runtime states received for any StateMachine Add-In instance\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::SM_UNKNOWN_RAPID_TASK =
        
          "\"RAPID task not found among known StateMachine Add-In instances\""
        
        ;
   

   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      ServiceResponses_<ContainerAllocator>::SM_UNINITIALIZED =
        
          "\"StateMachine Add-In instance has not been initialized\""
        
        ;
   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace abb_robot_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c541477c2ff72df8851a0d0cd0b0b782";
  }

  static const char* value(const ::abb_robot_msgs::ServiceResponses_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc541477c2ff72df8ULL;
  static const uint64_t static_value2 = 0x851a0d0cd0b0b782ULL;
};

template<class ContainerAllocator>
struct DataType< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "abb_robot_msgs/ServiceResponses";
  }

  static const char* value(const ::abb_robot_msgs::ServiceResponses_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# result codes are 16 bit unsigned\n"
"\n"
"# Generic OK\n"
"string SUCCESS=\"\"\n"
"uint16 RC_SUCCESS=1\n"
"\n"
"# Generic failure message\n"
"string FAILED=\"Service failed (e.g. timeout or resource not found, see the DEBUG log for details)\"\n"
"uint16 RC_FAILED=2\n"
"\n"
"# The server's underlying communication interface is busy\n"
"string SERVER_IS_BUSY=\"Server is busy\"\n"
"uint16 RC_SERVER_IS_BUSY=1001\n"
"\n"
"# Filename field is empty in service request\n"
"string EMPTY_FILENAME=\"Filename is empty\"\n"
"uint16 RC_EMPTY_FILENAME=2001\n"
"\n"
"# Signal name field is empty in service request\n"
"string EMPTY_SIGNAL_NAME=\"Signal name is empty\"\n"
"uint16 RC_EMPTY_SIGNAL_NAME=2002\n"
"\n"
"# RAPID task name field is empty in service request\n"
"string EMPTY_RAPID_TASK_NAME=\"RAPID task name is empty\"\n"
"uint16 RC_EMPTY_RAPID_TASK_NAME=2003\n"
"\n"
"# RAPID module name field is empty in service request\n"
"string EMPTY_RAPID_MODULE_NAME=\"RAPID module name is empty\"\n"
"uint16 RC_EMPTY_RAPID_MODULE_NAME=2004\n"
"\n"
"# RAPID symbol name field is empty in service request\n"
"string EMPTY_RAPID_SYMBOL_NAME=\"RAPID symbol name is empty\"\n"
"uint16 RC_EMPTY_RAPID_SYMBOL_NAME=2005\n"
"\n"
"# Robot controller is not in auto mode\n"
"string NOT_IN_AUTO_MODE=\"Robot controller is not in AUTO mode\"\n"
"uint16 RC_NOT_IN_AUTO_MODE=3001\n"
"\n"
"# The motors are off\n"
"string MOTORS_ARE_OFF=\"Motors are off\"\n"
"uint16 RC_MOTORS_ARE_OFF=3002\n"
"\n"
"# The motors are on\n"
"string MOTORS_ARE_ON=\"Motors are on\"\n"
"uint16 RC_MOTORS_ARE_ON=3003\n"
"\n"
"# RAPID has not been stopped\n"
"string RAPID_NOT_STOPPED=\"RAPID has not been stopped\"\n"
"uint16 RC_RAPID_NOT_STOPPED=3004\n"
"\n"
"# RAPID is not running\n"
"string RAPID_NOT_RUNNING=\"RAPID is not running\"\n"
"uint16 RC_RAPID_NOT_RUNNING=3005\n"
"\n"
"# RobotWare StateMachine Add-In runtime state is missing\n"
"string SM_RUNTIME_STATES_MISSING=\"No runtime states received for any StateMachine Add-In instance\"\n"
"uint16 RC_SM_RUNTIME_STATES_MISSING=4001\n"
"\n"
"# RobotWare StateMachine Add-In-instances do not know RAPID task\n"
"string SM_UNKNOWN_RAPID_TASK=\"RAPID task not found among known StateMachine Add-In instances\"\n"
"uint16 RC_SM_UNKNOWN_RAPID_TASK=4002\n"
"\n"
"# RobotWare StateMachine Add-In instance has not been initialized\n"
"string SM_UNINITIALIZED=\"StateMachine Add-In instance has not been initialized\"\n"
"uint16 RC_SM_UNINITIALIZED=4003\n"
;
  }

  static const char* value(const ::abb_robot_msgs::ServiceResponses_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ServiceResponses_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::abb_robot_msgs::ServiceResponses_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::abb_robot_msgs::ServiceResponses_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // ABB_ROBOT_MSGS_MESSAGE_SERVICERESPONSES_H
