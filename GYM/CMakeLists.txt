cmake_minimum_required(VERSION 3.24)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -std=c++11")
message (STATUS "COMPILER FLAGS: " ${CMAKE_CXX_FLAGS})

project(gym)

add_library(gym "GYM.h" "vec4.h" "vec4.cpp" "mat4.h" "mat4.cpp" "vec3.h" "vec3.cpp" "quat.h" "quat.cpp")

set_target_properties(gym PROPERTIES PUBLIC_HEADER "GYM.h" "vec4.h" "mat4.h" "vec3.h" "quat.h")

install(TARGETS gym DESTINATION lib
        PUBLIC_HEADER DESTINATION GYM)

