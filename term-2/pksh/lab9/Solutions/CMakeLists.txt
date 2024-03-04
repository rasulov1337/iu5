cmake_minimum_required(VERSION 3.23)

set(project "Solutions")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        "FirstPart.cpp"
        "Task5.cpp"
        "Task6.cpp"
        "Task7.cpp"
        "Task8.cpp"
        "Task9.cpp"
)

set(${project}_HEADERS
        "FirstPart.h"
        "Task5.h"
        "Task6.h"
        "Task7.h"
        "Task8.h"
        "Task9.h"
)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
