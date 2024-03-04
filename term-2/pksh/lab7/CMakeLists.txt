cmake_minimum_required(VERSION 3.23)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("Ships")

add_executable(lab7 main.cpp)

target_link_libraries(lab7 "Ships")
