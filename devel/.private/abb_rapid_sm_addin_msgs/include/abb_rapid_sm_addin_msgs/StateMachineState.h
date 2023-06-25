// Generated by gencpp from file abb_rapid_sm_addin_msgs/StateMachineState.msg
// DO NOT EDIT!


#ifndef ABB_RAPID_SM_ADDIN_MSGS_MESSAGE_STATEMACHINESTATE_H
#define ABB_RAPID_SM_ADDIN_MSGS_MESSAGE_STATEMACHINESTATE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace abb_rapid_sm_addin_msgs
{
template <class ContainerAllocator>
struct StateMachineState_
{
  typedef StateMachineState_<ContainerAllocator> Type;

  StateMachineState_()
    : rapid_task()
    , sm_state(0)
    , egm_action(0)  {
    }
  StateMachineState_(const ContainerAllocator& _alloc)
    : rapid_task(_alloc)
    , sm_state(0)
    , egm_action(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _rapid_task_type;
  _rapid_task_type rapid_task;

   typedef uint8_t _sm_state_type;
  _sm_state_type sm_state;

   typedef uint8_t _egm_action_type;
  _egm_action_type egm_action;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(SM_STATE_UNKNOWN)
  #undef SM_STATE_UNKNOWN
#endif
#if defined(_WIN32) && defined(SM_STATE_IDLE)
  #undef SM_STATE_IDLE
#endif
#if defined(_WIN32) && defined(SM_STATE_INITIALIZE)
  #undef SM_STATE_INITIALIZE
#endif
#if defined(_WIN32) && defined(SM_STATE_RUN_RAPID_ROUTINE)
  #undef SM_STATE_RUN_RAPID_ROUTINE
#endif
#if defined(_WIN32) && defined(SM_STATE_RUN_EGM_ROUTINE)
  #undef SM_STATE_RUN_EGM_ROUTINE
#endif
#if defined(_WIN32) && defined(EGM_ACTION_UNKNOWN)
  #undef EGM_ACTION_UNKNOWN
#endif
#if defined(_WIN32) && defined(EGM_ACTION_NONE)
  #undef EGM_ACTION_NONE
#endif
#if defined(_WIN32) && defined(EGM_ACTION_RUN_JOINT)
  #undef EGM_ACTION_RUN_JOINT
#endif
#if defined(_WIN32) && defined(EGM_ACTION_RUN_POSE)
  #undef EGM_ACTION_RUN_POSE
#endif
#if defined(_WIN32) && defined(EGM_ACTION_STOP)
  #undef EGM_ACTION_STOP
#endif
#if defined(_WIN32) && defined(EGM_ACTION_START_STREAM)
  #undef EGM_ACTION_START_STREAM
#endif
#if defined(_WIN32) && defined(EGM_ACTION_STOP_STREAM)
  #undef EGM_ACTION_STOP_STREAM
#endif

  enum {
    SM_STATE_UNKNOWN = 1u,
    SM_STATE_IDLE = 2u,
    SM_STATE_INITIALIZE = 3u,
    SM_STATE_RUN_RAPID_ROUTINE = 4u,
    SM_STATE_RUN_EGM_ROUTINE = 5u,
    EGM_ACTION_UNKNOWN = 1u,
    EGM_ACTION_NONE = 2u,
    EGM_ACTION_RUN_JOINT = 3u,
    EGM_ACTION_RUN_POSE = 4u,
    EGM_ACTION_STOP = 5u,
    EGM_ACTION_START_STREAM = 6u,
    EGM_ACTION_STOP_STREAM = 7u,
  };


  typedef boost::shared_ptr< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> const> ConstPtr;

}; // struct StateMachineState_

typedef ::abb_rapid_sm_addin_msgs::StateMachineState_<std::allocator<void> > StateMachineState;

typedef boost::shared_ptr< ::abb_rapid_sm_addin_msgs::StateMachineState > StateMachineStatePtr;
typedef boost::shared_ptr< ::abb_rapid_sm_addin_msgs::StateMachineState const> StateMachineStateConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator1> & lhs, const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator2> & rhs)
{
  return lhs.rapid_task == rhs.rapid_task &&
    lhs.sm_state == rhs.sm_state &&
    lhs.egm_action == rhs.egm_action;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator1> & lhs, const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace abb_rapid_sm_addin_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "de6354e383149183de9c15ab3d871c7b";
  }

  static const char* value(const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xde6354e383149183ULL;
  static const uint64_t static_value2 = 0xde9c15ab3d871c7bULL;
};

template<class ContainerAllocator>
struct DataType< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "abb_rapid_sm_addin_msgs/StateMachineState";
  }

  static const char* value(const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#-------------------------------------------------------------------------------\n"
"# Description:\n"
"#   The purpose of this message definition, is to represent the state of an\n"
"#   instance of the RobotWare \"StateMachine Add-In\"'s RAPID implementation.\n"
"#-------------------------------------------------------------------------------\n"
"\n"
"#-------------------------------------------------------------------------------\n"
"# Enumerations\n"
"#-------------------------------------------------------------------------------\n"
"# Possible \"StateMachine Add-In\" RAPID states:\n"
"#\n"
"# Note: These enumeration values differ from the RAPID implementation\n"
"#       values to avoid conflict with default values in ROS messages.\n"
"uint8 SM_STATE_UNKNOWN           = 1\n"
"uint8 SM_STATE_IDLE              = 2\n"
"uint8 SM_STATE_INITIALIZE        = 3\n"
"uint8 SM_STATE_RUN_RAPID_ROUTINE = 4\n"
"uint8 SM_STATE_RUN_EGM_ROUTINE   = 5\n"
"\n"
"# Possible \"StateMachine Add-In\" RAPID EGM actions:\n"
"#\n"
"# Note: These enumeration values differ from the RAPID implementation\n"
"#       values to avoid conflict with default values in ROS messages.\n"
"uint8 EGM_ACTION_UNKNOWN      = 1\n"
"uint8 EGM_ACTION_NONE         = 2\n"
"uint8 EGM_ACTION_RUN_JOINT    = 3\n"
"uint8 EGM_ACTION_RUN_POSE     = 4\n"
"uint8 EGM_ACTION_STOP         = 5\n"
"uint8 EGM_ACTION_START_STREAM = 6\n"
"uint8 EGM_ACTION_STOP_STREAM  = 7\n"
"\n"
"#-------------------------------------------------------------------------------\n"
"# Message fields\n"
"#-------------------------------------------------------------------------------\n"
"# The RAPID task that runs the \"StateMachine Add-In\" instance.\n"
"string rapid_task\n"
"\n"
"# The \"StateMachine Add-In\" instance's current state.\n"
"uint8 sm_state\n"
"\n"
"# The \"StateMachine Add-In\" instance's current EGM action\n"
"# (only used if the RobotWare EGM option is present).\n"
"uint8 egm_action\n"
;
  }

  static const char* value(const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rapid_task);
      stream.next(m.sm_state);
      stream.next(m.egm_action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StateMachineState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::abb_rapid_sm_addin_msgs::StateMachineState_<ContainerAllocator>& v)
  {
    s << indent << "rapid_task: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.rapid_task);
    s << indent << "sm_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sm_state);
    s << indent << "egm_action: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.egm_action);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ABB_RAPID_SM_ADDIN_MSGS_MESSAGE_STATEMACHINESTATE_H
