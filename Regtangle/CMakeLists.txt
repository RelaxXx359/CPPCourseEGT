cmake_minimum_required(VERSION 3.27)
project(Regtangle)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Regtangle
        main.cpp
        Point.cpp
        Point.h
        Rectangle.cpp
        Rectangle.h
        Task.h)
