cmake_minimum_required(VERSION 3.20)

project(Piccolo VERSION 0.1.0)

add_executable(main engine/source/editor/source/main.cpp engine/source/runtime/engine.h)
target_include_directories(main PRIVATE engine)
target_compile_features(main PRIVATE cxx_std_17)


include(CTest)
enable_testing()

add_subdirectory(./engine/test)