cmake_minimum_required(VERSION 3.27)
project(LibraryManageSystem_HomeWork)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LibraryManageSystem_HomeWork
        Book.cpp
        Book.h
        main.cpp
        Member.cpp
        Member.h
        Task.h)
