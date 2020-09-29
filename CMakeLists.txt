cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp Array.h DynamicArray.h Stack.h)
