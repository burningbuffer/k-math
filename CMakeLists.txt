cmake_minimum_required(VERSION 3.24)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -std=c++11")
#message (STATUS "COMPILER FLAGS: " ${CMAKE_CXX_FLAGS})

#set(CMAKE_VERBOSE_MAKEFILE ON)
#message (STATUS "VERBOSE: " ${CMAKE_VERBOSE_MAKEFILE})

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_BUILD_TYPE Debug)

project ("mat_library")

add_subdirectory ("MAT")