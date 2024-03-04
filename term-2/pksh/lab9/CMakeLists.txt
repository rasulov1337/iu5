cmake_minimum_required(VERSION 3.23)
project(lab9)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("Solutions")

add_executable(lab9 main.cpp)

target_link_libraries(lab9 "Solutions")
