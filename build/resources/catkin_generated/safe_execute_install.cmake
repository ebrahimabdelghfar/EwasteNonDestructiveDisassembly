execute_process(COMMAND "/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/resources/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/omar/Desktop/GP/EwasteNonDestructiveDisassembly/build/resources/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
