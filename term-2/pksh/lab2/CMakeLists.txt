cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory("planet")
add_subdirectory("subscriber")

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        main.cpp)

target_link_libraries(lab2 PUBLIC planet)
target_link_libraries(lab2 PUBLIC subscriber)
