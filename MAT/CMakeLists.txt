cmake_minimum_required(VERSION 3.24)


set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -std=c++11")
message (STATUS "COMPILER FLAGS: " ${CMAKE_CXX_FLAGS})

add_executable(${PROJECT_NAME} "main.cpp" "MAT.h" "vec4.h" "vec4.cpp" "mat4.h" "mat4.cpp" "vec3.h" "vec3.cpp" "quat.h" "quat.cpp")