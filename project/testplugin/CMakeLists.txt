#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(MY_PROGRAM testplugin)

set(PATH_DIST ${TEST_PLUGIN_SOURCE_DIR}/../dist)
set(LIB_STATIC_PLUGIN pctrplugin)
set(EXECUTABLE_OUTPUT_PATH ${PATH_DIST}/bin)

#set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")
set(CMAKE_CXX_FLAGS "-fno-gnu-unique")

link_directories(${PATH_DIST}/lib)

include_directories(${PATH_DIST}/include)
include_directories(${TEST_PLUGIN_SOURCE_DIR})

set(TEST_PLUGIN_SRCS main.cpp)

ADD_EXECUTABLE(${MY_PROGRAM} ${TEST_PLUGIN_SRCS})
TARGET_LINK_LIBRARIES(${MY_PROGRAM} -l${LIB_STATIC_PLUGIN})

file(COPY ${TEST_PLUGIN_SOURCE_DIR}/AddPluginInterface.hpp DESTINATION ${PATH_DIST}/include)

#********** end CmakeLists.txt **********