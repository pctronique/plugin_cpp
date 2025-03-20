#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN1)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(LIB_TEST_PLUGIN1 plugin1)

set (CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(PATH_DIST ${TEST_PLUGIN1_SOURCE_DIR}/../../dist)
set(LIBRARY_OUTPUT_PATH ${PATH_DIST}/bin/plugins/)

include_directories(${PATH_DIST}/include)
include_directories(${TEST_PLUGIN1_SOURCE_DIR})

set(TEST_PLUGIN1_SRCS Plugin1.cpp)
set(TEST_PLUGIN1_HDRS Plugin1.hpp)

add_library (${LIB_TEST_PLUGIN1} SHARED ${TEST_PLUGIN1_SRCS} ${TEST_PLUGIN1_HDRS})

#********** end CmakeLists.txt **********