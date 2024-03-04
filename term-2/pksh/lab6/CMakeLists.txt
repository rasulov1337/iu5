cmake_minimum_required(VERSION 3.23)
project(lab6)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(Polynomial)

add_executable(lab6 main.cpp)

target_link_libraries(lab6 Polynomial)
