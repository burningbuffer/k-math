add_executable(demo demo.cpp)
target_compile_features(demo PRIVATE cxx_std_20)
target_link_libraries(demo PRIVATE kmath_library)