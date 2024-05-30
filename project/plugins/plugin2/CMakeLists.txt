#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN2)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(LIB_TEST_PLUGIN2 plugin2)

set (CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed")

set(PATH_DIST ${TEST_PLUGIN2_SOURCE_DIR}/../../dist)
set(LIBRARY_OUTPUT_PATH ${PATH_DIST}/bin/plugins/)

include_directories(${PATH_DIST}/include)
include_directories(${TEST_PLUGIN2_SOURCE_DIR})

set(TEST_PLUGIN2_SRCS Plugin2.cpp)
set(TEST_PLUGIN2_HDRS Plugin2.hpp)

add_library (${LIB_TEST_PLUGIN2} SHARED ${TEST_PLUGIN2_SRCS} ${TEST_PLUGIN2_HDRS})

#********** end CmakeLists.txt **********