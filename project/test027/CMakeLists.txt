#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN)

SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_BUILD_TYPE Release)

set(MY_PROGRAM testplugin)
set(LIB_ADDSTATIC_PLUGIN circle)
set(LIB_ADDSTATIC1_PLUGIN circle1)

set (CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(EXECUTABLE_OUTPUT_PATH ${TEST_PLUGIN_SOURCE_DIR}/dist/bin)
set(LIBRARY_OUTPUT_PATH ${TEST_PLUGIN_SOURCE_DIR}/dist/bin)

set(TEST_PLUGIN_SRCS main.cpp Add_Plugin.hpp)
#set(TEST_PLUGINSO_SRCS Add_plugin.cpp Add_Plugin.hpp)
set(TEST_PLUGIN1_SRCS Plugin1.cpp Add_Plugin.hpp Plugin1.hpp)

ADD_EXECUTABLE(${MY_PROGRAM} ${TEST_PLUGIN_SRCS})
#add_library (${LIB_ADDSTATIC_PLUGIN} SHARED ${TEST_PLUGINSO_SRCS})
add_library (${LIB_ADDSTATIC1_PLUGIN} SHARED ${TEST_PLUGIN1_SRCS})

#********** end CmakeLists.txt **********