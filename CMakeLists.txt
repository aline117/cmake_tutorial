cmake_minimum_required(VERSION 2.8.12)

if(APPLE)
	set(CMAKE_MACOSX_RPATH 1)
	message("MAC os x")
elseif(WIN32)
	message("windows")
else()
	#if(UNIX AND UNIX_STRUCTURE)
	message("linux")
endif(APPLE)

#根据判断系统版本
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(__SIZEOF__ "64")
else()
	set(__SIZEOF__ "32")
endif()
message(STATUS "BUILD ENV: ${__SIZEOF__}Bit" )


set(DIR_PRJ ${CMAKE_CURRENT_SOURCE_DIR})
set(DIR_DLL "${DIR_PRJ}/dll")
set(DIR_LIB "${DIR_PRJ}/lib")
set(DIR_BIN "${DIR_PRJ}/bin")

add_subdirectory(src)


#include(CopyMSVCBins)

