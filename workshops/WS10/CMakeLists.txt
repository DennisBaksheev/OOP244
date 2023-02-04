cmake_minimum_required(VERSION 3.23)
project(WS10)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WS10
        Car.cpp
        Car.h
        Collection.cpp
        Collection.h
        Employee.cpp
        Employee.h
        main.cpp
        ReadWrite.cpp
        ReadWrite.h
        search.h
        Student.cpp
        Student.h)
