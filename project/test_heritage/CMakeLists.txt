#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(PROJECT_PLUGIN)

set(MY_PROGRAM testplugin)

#INCLUDE_DIRECTORIES(${PROJECT_PLUGIN_SOURCE_DIR}/dist/include/)

set(TEST_PLUGIN_SRCS main.cpp)

ADD_EXECUTABLE(prog ${TEST_PLUGIN_SRCS})

#********** end CmakeLists.txt **********