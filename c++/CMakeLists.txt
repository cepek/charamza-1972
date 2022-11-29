cmake_minimum_required(VERSION 3.5)

project(orton3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zkouska1 main.cpp orton3.h orton3.cpp mx.h mx.cpp)


enable_testing()
add_subdirectory(tests)
