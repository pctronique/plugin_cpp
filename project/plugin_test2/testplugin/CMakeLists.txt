#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN)

set(MY_PROGRAM testplugin)

#INCLUDE_DIRECTORIES(${PROJECT_PLUGIN_SOURCE_DIR}/dist/include/)

set(TEST_PLUGIN_SRCS main.cpp)

ADD_EXECUTABLE(${MY_PROGRAM} ${TEST_PLUGIN_SRCS})
TARGET_LINK_LIBRARIES(${MY_PROGRAM} ${PROJECT_PLUGIN_SOURCE_DIR}/dist/lib/lib${LIB_STATIC_PLUGIN}.a)

#********** end CmakeLists.txt **********