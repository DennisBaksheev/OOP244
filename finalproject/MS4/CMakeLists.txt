cmake_minimum_required(VERSION 3.23)
project(MS4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS4
        Car.cpp
        Car.h
        main.cpp
        Motorcycle.cpp
        Motorcycle.h
        ReadWritable.cpp
        ReadWritable.h
        Vehicle.cpp
        Vehicle.h)
