cmake_minimum_required(VERSION 3.23)
project(WS08)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WS08
        LblShape.cpp
        LblShape.h
        Line.cpp
        Line.h
        main.cpp
        Rectangle.cpp
        Rectangle.h
        Shape.cpp
        Shape.h)
