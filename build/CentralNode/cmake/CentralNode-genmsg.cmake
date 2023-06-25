# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "CentralNode: 1 messages, 1 services")

set(MSG_I_FLAGS "-ICentralNode:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(CentralNode_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_custom_target(_CentralNode_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "CentralNode" "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" ""
)

get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_custom_target(_CentralNode_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "CentralNode" "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/CentralNode
)

### Generating Services
_generate_srv_cpp(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/CentralNode
)

### Generating Module File
_generate_module_cpp(CentralNode
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/CentralNode
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(CentralNode_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(CentralNode_generate_messages CentralNode_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_dependencies(CentralNode_generate_messages_cpp _CentralNode_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_dependencies(CentralNode_generate_messages_cpp _CentralNode_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(CentralNode_gencpp)
add_dependencies(CentralNode_gencpp CentralNode_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS CentralNode_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/CentralNode
)

### Generating Services
_generate_srv_eus(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/CentralNode
)

### Generating Module File
_generate_module_eus(CentralNode
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/CentralNode
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(CentralNode_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(CentralNode_generate_messages CentralNode_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_dependencies(CentralNode_generate_messages_eus _CentralNode_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_dependencies(CentralNode_generate_messages_eus _CentralNode_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(CentralNode_geneus)
add_dependencies(CentralNode_geneus CentralNode_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS CentralNode_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/CentralNode
)

### Generating Services
_generate_srv_lisp(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/CentralNode
)

### Generating Module File
_generate_module_lisp(CentralNode
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/CentralNode
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(CentralNode_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(CentralNode_generate_messages CentralNode_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_dependencies(CentralNode_generate_messages_lisp _CentralNode_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_dependencies(CentralNode_generate_messages_lisp _CentralNode_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(CentralNode_genlisp)
add_dependencies(CentralNode_genlisp CentralNode_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS CentralNode_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/CentralNode
)

### Generating Services
_generate_srv_nodejs(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/CentralNode
)

### Generating Module File
_generate_module_nodejs(CentralNode
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/CentralNode
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(CentralNode_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(CentralNode_generate_messages CentralNode_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_dependencies(CentralNode_generate_messages_nodejs _CentralNode_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_dependencies(CentralNode_generate_messages_nodejs _CentralNode_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(CentralNode_gennodejs)
add_dependencies(CentralNode_gennodejs CentralNode_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS CentralNode_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode
)

### Generating Services
_generate_srv_py(CentralNode
  "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode
)

### Generating Module File
_generate_module_py(CentralNode
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(CentralNode_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(CentralNode_generate_messages CentralNode_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/msg/node_response.msg" NAME_WE)
add_dependencies(CentralNode_generate_messages_py _CentralNode_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/CentralNode/srv/Schedular.srv" NAME_WE)
add_dependencies(CentralNode_generate_messages_py _CentralNode_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(CentralNode_genpy)
add_dependencies(CentralNode_genpy CentralNode_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS CentralNode_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/CentralNode)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/CentralNode
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(CentralNode_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/CentralNode)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/CentralNode
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(CentralNode_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/CentralNode)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/CentralNode
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(CentralNode_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/CentralNode)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/CentralNode
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(CentralNode_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/CentralNode
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(CentralNode_generate_messages_py std_msgs_generate_messages_py)
endif()
