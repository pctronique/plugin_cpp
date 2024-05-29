#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN)

SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_BUILD_TYPE Release)

set(MY_PROGRAM testplugin)
set(LIB_STATIC_PLUGIN pluginstatic)
set(LIB_ADDSTATIC_PLUGIN pluginaddstatic)

include_directories(${TEST_PLUGIN_SOURCE_DIR}/../include)
set(EXECUTABLE_OUTPUT_PATH ${TEST_PLUGIN_SOURCE_DIR}/../dist/bin)

set(TEST_PLUGIN_SRCS main.cpp)

ADD_EXECUTABLE(${MY_PROGRAM} ${TEST_PLUGIN_SRCS})
TARGET_LINK_LIBRARIES(${MY_PROGRAM} ${TEST_PLUGIN_SOURCE_DIR}/../dist/lib/lib${LIB_STATIC_PLUGIN}.a)

#********** end CmakeLists.txt **********