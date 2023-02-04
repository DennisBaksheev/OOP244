cmake_minimum_required(VERSION 3.23)
project(MS5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS5
        Car.cpp
        Car.h
        Menu.cpp
        Menu.h
        Motorcycle.cpp
        Motorcycle.h
        Parking.cpp
        Parking.h
        ReadWritable.cpp
        ReadWritable.h
        Vehicle.cpp
        Vehicle.h
        main.cpp)
