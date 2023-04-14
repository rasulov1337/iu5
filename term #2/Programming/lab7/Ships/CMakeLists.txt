cmake_minimum_required(VERSION 3.23)

set(project "Ships")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        Ship.cpp
        Corvette.cpp
        Parusnik.cpp
        Steamer.cpp)

set(${project}_HEADERS
        Ship.h
        Corvette.h
        Parusnik.h
        Steamer.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
