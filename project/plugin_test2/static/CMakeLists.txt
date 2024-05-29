#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(STATIC_PLUGIN)

set(LIB_STATIC_PLUGIN pluginstatic)
set(LIB_ADDSTATIC_PLUGIN pluginaddstatic)

include_directories(${STATIC_PLUGIN_SOURCE_DIR}/../include)
set(LIBRARY_OUTPUT_PATH ${STATIC_PLUGIN_SOURCE_DIR}/../dist/lib)

set(STATIC_ADDPLUGIN_SRCS Add_plugin.cpp)
set(STATIC_PLUGIN_SRCS Main_plugin.cpp)
#set(STATIC_PLUGIN_HDRS Main_plugin.hpp Add_Plugin.hpp)

add_library (${LIB_ADDSTATIC_PLUGIN} STATIC ${STATIC_ADDPLUGIN_SRCS})

add_library (${LIB_STATIC_PLUGIN} STATIC ${STATIC_PLUGIN_SRCS})# ${STATIC_ADDPLUGIN_SRCS})# ${STATIC_PLUGIN_HDRS})

#********** end CmakeLists.txt **********