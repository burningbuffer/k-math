add_executable(demo demo.cpp)
target_compile_features(demo PRIVATE cxx_std_20)
# on hold
target_link_libraries(demo PRIVATE math_library)