#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(STATIC_PLUGIN)

set(STATIC_PLUGIN_SRCS Main_plugin.cpp)
#set(STATIC_PLUGIN_HDRS Main_plugin.hpp Add_Plugin.hpp)

add_library (${LIB_STATIC_PLUGIN} STATIC ${STATIC_PLUGIN_SRCS})# ${STATIC_PLUGIN_HDRS})

#********** end CmakeLists.txt **********