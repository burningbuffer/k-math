
file(GLOB HEADER_FILES "include/kma/*.hpp")
file(GLOB SOURCE_FILES "*.cpp")

# Create a library from the source files
add_library(kmath_library ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(kmath_library PUBLIC ../include)

target_include_directories(kmath_library PUBLIC ../include)

target_compile_features(kmath_library PUBLIC cxx_std_20)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_FILES})
