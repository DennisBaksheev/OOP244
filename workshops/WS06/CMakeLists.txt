cmake_minimum_required(VERSION 3.23)
project(WS06)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WS06
        main.cpp
        Numbers.cpp
        Numbers.h)
