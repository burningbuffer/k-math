cmake_minimum_required(VERSION 3.24)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -std=c++11")
#message (STATUS "COMPILER FLAGS: " ${CMAKE_CXX_FLAGS})

#set(CMAKE_VERBOSE_MAKEFILE ON)
#message (STATUS "VERBOSE: " ${CMAKE_VERBOSE_MAKEFILE})

project(libtest)

add_executable(${PROJECT_NAME} main.cpp "GYM/GYM.h" "GYM/vec4.h" "GYM/vec4.cpp" "GYM/mat4.h" "GYM/mat4.cpp" "GYM/vec3.h" "GYM/vec3.cpp" "GYM/quat.h" "GYM/quat.cpp")

# TODO clear
target_link_directories(libtest PRIVATE ${CMAKE_SOURCE_DIR}/GYM/build)

target_link_libraries(libtest gym)

#install(TARGETS libtest DESTINATION bin) #make install

message(STATUS "END CMAKE")