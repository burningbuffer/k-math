# Cmake version
cmake_minimum_required(VERSION 3.8)

# Project name and languages
project(
  kmath
  LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ox /Gv")
message (STATUS "COMPILER FLAGS: " ${CMAKE_CXX_FLAGS})

# Locate header files
file(GLOB LIBRARY_FILES "include/kma/*.hpp")

# Create an INTERFACE library (header-only library)
add_library(kmath_library INTERFACE)

# Set C++ features for the library
target_compile_features(kmath_library INTERFACE cxx_std_20)

# Set include directories for the library
target_include_directories(kmath_library INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add demos subdirectory
add_subdirectory(demos)