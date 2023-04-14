cmake_minimum_required(VERSION 3.23)
project(lab3)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory("Fraction")

add_executable(lab3 main.cpp)

target_link_libraries(lab3 fraction)
