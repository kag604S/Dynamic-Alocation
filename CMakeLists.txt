cmake_minimum_required(VERSION 3.28)
project(dynamiczna)

set(CMAKE_CXX_STANDARD 17)

add_executable(dynamiczna main.cpp
        array.cpp
        array.h)
