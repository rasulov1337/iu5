cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("MyStack")

add_executable(lab4 main.cpp)

if (NOT WIN32)
target_link_libraries(lab4 mystack)
endif()
