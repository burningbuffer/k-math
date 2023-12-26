
file(GLOB HEADER_FILES "include/mat/*.hpp")
file(GLOB SOURCE_FILES "*.cpp")

# Create a library from the source files
add_library(math_library ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(math_library PUBLIC ../include)

target_include_directories(math_library PUBLIC ../include)

target_compile_features(math_library PUBLIC cxx_std_20)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_FILES})
