cmake_minimum_required(VERSION 3.20)

project(Piccolo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(engine)



include(CTest)
enable_testing()

add_subdirectory(./engine/test)