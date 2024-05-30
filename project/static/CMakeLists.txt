#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(STATIC_PLUGIN)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(PATH_DIST ${STATIC_PLUGIN_SOURCE_DIR}/../dist)
set(LIBRARY_OUTPUT_PATH ${PATH_DIST}/lib)
set(LIB_STATIC_PLUGIN pluginstatic)
set(STATIC_PLUGIN_SRCS Main_plugin.cpp)

include_directories(${STATIC_PLUGIN_SOURCE_DIR})

add_library (${LIB_STATIC_PLUGIN} STATIC ${STATIC_PLUGIN_SRCS})
file(COPY ${STATIC_PLUGIN_SOURCE_DIR}/Add_Plugin.hpp DESTINATION ${PATH_DIST}/include)
file(COPY ${STATIC_PLUGIN_SOURCE_DIR}/Main_plugin.hpp DESTINATION ${PATH_DIST}/include)

#********** end CmakeLists.txt **********