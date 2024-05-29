#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(PROJECT_PLUGIN)

SET(CMAKE_BUILD_TYPE Debug)
#SET(CMAKE_BUILD_TYPE Release)

set(LIB_STATIC_PLUGIN pluginstatic)

include_directories(${PROJECT_PLUGIN_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${PROJECT_PLUGIN_SOURCE_DIR}/dist/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_PLUGIN_SOURCE_DIR}/dist/bin)

file(COPY ${PROJECT_PLUGIN_SOURCE_DIR}/include/Main_plugin.hpp DESTINATION ${PROJECT_PLUGIN_SOURCE_DIR}/dist/include/)

add_subdirectory(static)
add_subdirectory(testplugin)
add_subdirectory(plugins)

#********** end CmakeLists.txt **********