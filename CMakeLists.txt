cmake_minimum_required(VERSION 3.26)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_Structures main.cpp
        heap/heap.h
        heap/heap.cpp
        heap/tests.h)
