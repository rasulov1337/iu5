cmake_minimum_required(VERSION 3.23)
project(lab5)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory("Containers")

add_executable(lab5 main.cpp)

target_link_libraries(lab5 containers)
