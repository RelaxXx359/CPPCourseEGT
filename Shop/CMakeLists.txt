cmake_minimum_required(VERSION 3.27)
project(Shop)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shop main.cpp
        Drinks.h
        Alcoholic.h
        Drinks.cpp
        Alcoholic.cpp
        NonAlcoholic.h
        NonAlcoholic.cpp
        User.h
        User.cpp
        Order.h
        Order.cpp)
