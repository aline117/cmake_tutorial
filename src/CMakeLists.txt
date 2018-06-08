#cmake_minimum_required(VERSION 2.8.12)

project(test_cmake)

#include_directories(include)


set(tc_incs
	main_depend.h
)
set(tc_srcs ${tc_srcs}
	main_depend.cpp
)
set(tc_srcs_exe ${tc_srcs_exe}
	main.cpp
)

message(STATUS "GENERATOR_IS_MULTI_CONFIG:${GENERATOR_IS_MULTI_CONFIG}")
message("CMAKE_CONFIGURATION_TYPES:${CMAKE_CONFIGURATION_TYPES}") #Debug;Release;MinSizeRel;RelWithDebInfo
message("CMAKE_BUILD_TYPE:${CMAKE_BUILD_TYPE}") #CMAKE_BUILD_TYPE

if(WIN32)
	message("VS_CONFIGURATION_TYPE:${VS_CONFIGURATION_TYPE}")
endif()


###+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
###设置生成结果(库/执行文件)的输出目录
#设置生成"库<dll/lib>"的输出目录,不支持多配置<CONFIG>的generator
#支持多配置<CONFIG>的generator
#ARCHIVE_OUTPUT_DIRECTORY_<CONFIG> #静态库     注要"CMAKE_"前缀
#LIBRARY_OUTPUT_DIRECTORY_<CONFIG> #Module库   注要"CMAKE_"前缀
#RUNTIME_OUTPUT_DIRECTORY_<CONFIG> #可执行/DLL 注要"CMAKE_"前缀
#LIBRARY_OUTPUT_PATH    #静态库/DLL 注不要"CMAKE_"前缀
#EXECUTABLE_OUTPUT_PATH #可执行/DLL 注不要"CMAKE_"前缀
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${DIR_DLL}") #ok
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${DIR_DLL}") #ok
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${DIR_LIB}") #ok
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${DIR_LIB}") #ok
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${DIR_BIN}") #ok
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${DIR_BIN}") #ok

#不支持多配置<CONFIG>的generator，同LIBRARY_OUTPUT_PATH 和 EXECUTABLE_OUTPUT_PATH
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY   "${DIR_LIB}") #ok
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY   "${DIR_LIB}") #ok
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   "${DIR_BIN}") #ok
#set(LIBRARY_OUTPUT_PATH "${DIR_LIB}")    #ok
#set(EXECUTABLE_OUTPUT_PATH "${DIR_BIN}") #ok 

message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG:${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG:${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE:${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY:${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECTORY:${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECTORY:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "LIBRARY_OUTPUT_PATH:${LIBRARY_OUTPUT_PATH}")
message(STATUS "EXECUTABLE_OUTPUT_PATH:${EXECUTABLE_OUTPUT_PATH}")
###-----------------------------------------------------------------

#add_custom_command(OUTPUT output1 [output2 ...]
#                   COMMAND command1 [ARGS] [args1...]
#                   [COMMAND command2 [ARGS] [args2...] ...]
#                   [MAIN_DEPENDENCY depend]
#                   [DEPENDS [depends...]]
#                   [BYPRODUCTS [files...]]
#                   [IMPLICIT_DEPENDS <lang1> depend1
#                                    [<lang2> depend2] ...]
#                   [WORKING_DIRECTORY dir]
#                   [COMMENT comment]
#                   [DEPFILE depfile]
#                   [VERBATIM] [APPEND] [USES_TERMINAL]
#                   [COMMAND_EXPAND_LISTS])
set(TEST_FILE "log.txt")
add_custom_command(OUTPUT  ${TEST_FILE}
  COMMAND echo "Generating log.txt file..."
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_FILE} ${TEST_FILE}
  COMMENT  "This is a test"
 )
#add_custom_target(test_cmake_dll ALL DEPENDS ${TEST_FILE})

set(DEPEND_TEST "main_depend_test.cpp")
add_custom_command(OUTPUT  ${DEPEND_TEST}
  COMMAND echo "Generating log.txt file..."
  #COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_FILE} ${TEST_FILE}
  COMMENT  "This is a test"
)

add_library(test_cmake_dll SHARED
	${tc_incs}
	${tc_srcs}
	${TEST_FILE}
	${DEPEND_TEST}
	)
add_library(test_cmake_lib STATIC
	${tc_incs}
	${tc_srcs}
	)

#设置生成"可能执行文件"的输出目录
add_executable(test_cmake_exe
	${tc_incs}
	${tc_srcs}
	${tc_srcs_exe}
)
