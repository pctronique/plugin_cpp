#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(MAIN_PLUGIN)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(PATH_DIST ${MAIN_PLUGIN_SOURCE_DIR}/../../dist)
set(LIBRARY_OUTPUT_PATH ${PATH_DIST}/lib)
set(LIB_MAIN_PLUGIN pluginstatic)
set(MAIN_PLUGIN_SRCS Main_plugin.cpp)

include_directories(${MAIN_PLUGIN_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-fno-gnu-unique")

add_library (${LIB_MAIN_PLUGIN} STATIC ${MAIN_PLUGIN_SRCS})
file(COPY ${MAIN_PLUGIN_SOURCE_DIR}/AddPluginInterface.hpp DESTINATION ${PATH_DIST}/include)
file(COPY ${MAIN_PLUGIN_SOURCE_DIR}/Main_plugin.hpp DESTINATION ${PATH_DIST}/include)

#********** end CmakeLists.txt **********