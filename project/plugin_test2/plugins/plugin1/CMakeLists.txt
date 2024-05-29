#********** start CmakeLists.txt **********

cmake_minimum_required(VERSION 3.1.0)

project(TEST_PLUGIN1)

set(LIB_TEST_PLUGIN1 plugin1)
set(LIB_ADDSTATIC_PLUGIN pluginaddstatic)

include_directories(${TEST_PLUGIN1_SOURCE_DIR}/../../include)
include_directories(${TEST_PLUGIN1_SOURCE_DIR})

set(LIBRARY_OUTPUT_PATH ${TEST_PLUGIN1_SOURCE_DIR}/../../dist/bin/plugins/)

set(TEST_PLUGIN1_SRCS Plugin1.cpp)
set(TEST_PLUGIN1_HDRS Plugin1.hpp)

add_library (${LIB_TEST_PLUGIN1} SHARED ${TEST_PLUGIN1_SRCS} ${TEST_PLUGIN1_HDRS})
#TARGET_LINK_LIBRARIES(${LIB_TEST_PLUGIN1} ${TEST_PLUGIN1_SOURCE_DIR}/../../dist/lib/lib${LIB_ADDSTATIC_PLUGIN}.a)

#set(EXECUTABLE_OUTPUT_PATH ${TEST_PLUGIN1_SOURCE_DIR}/../../dist/bin)
#ADD_EXECUTABLE(test01 main.cpp ${TEST_PLUGIN1_SRCS} ${TEST_PLUGIN1_HDRS})
#TARGET_LINK_LIBRARIES(test01 ${TEST_PLUGIN1_SOURCE_DIR}/../../dist/lib/lib${LIB_ADDSTATIC_PLUGIN}.a)

#file(COPY ${PROJECT_PLUGIN_SOURCE_DIR}/dist/lib/lib${LIB_TEST_PLUGIN1}.so DESTINATION ${PROJECT_PLUGIN_SOURCE_DIR}/dist/bin/plugins/)

#********** end CmakeLists.txt **********