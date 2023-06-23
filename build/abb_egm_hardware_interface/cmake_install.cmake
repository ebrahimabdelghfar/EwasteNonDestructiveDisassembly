# Install script for directory: /home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/ABB_Dependent/abb_robot_driver/abb_egm_hardware_interface

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE PROGRAM FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/_setup_util.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE PROGRAM FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/env.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/setup.bash;/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE FILE FILES
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/setup.bash"
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/setup.sh;/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE FILE FILES
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/setup.sh"
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/setup.zsh;/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE FILE FILES
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/setup.zsh"
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/install" TYPE FILE FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/.rosinstall")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/abb_egm_hardware_interface.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_egm_hardware_interface/cmake" TYPE FILE FILES
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/abb_egm_hardware_interfaceConfig.cmake"
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/catkin_generated/installspace/abb_egm_hardware_interfaceConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_egm_hardware_interface" TYPE FILE FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/ABB_Dependent/abb_robot_driver/abb_egm_hardware_interface/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib/libabb_egm_hardware_interface_hardware_interface.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so"
         OLD_RPATH "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_robot_cpp_utilities/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_hardware_interface.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface" TYPE EXECUTABLE FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib/abb_egm_hardware_interface/egm_hardware_interface")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface"
         OLD_RPATH "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_robot_cpp_utilities/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/lib:/opt/ros/noetic/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_hardware_interface")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib/libabb_egm_hardware_interface_controller_stopper.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so"
         OLD_RPATH "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_robot_cpp_utilities/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libabb_egm_hardware_interface_controller_stopper.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface" TYPE EXECUTABLE FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib/abb_egm_hardware_interface/egm_controller_stopper")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper"
         OLD_RPATH "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_robot_cpp_utilities/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/lib:/opt/ros/noetic/lib:/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/devel/.private/abb_egm_hardware_interface/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/abb_egm_hardware_interface/egm_controller_stopper")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/abb_egm_hardware_interface" TYPE DIRECTORY FILES "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/ABB_Dependent/abb_robot_driver/abb_egm_hardware_interface/include/abb_egm_hardware_interface/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_egm_hardware_interface" TYPE DIRECTORY FILES
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/ABB_Dependent/abb_robot_driver/abb_egm_hardware_interface/config"
    "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/src/ABB_Dependent/abb_robot_driver/abb_egm_hardware_interface/launch"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/abb_egm_hardware_interface/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
