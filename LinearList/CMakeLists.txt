cmake_minimum_required(VERSION 3.15)
project(LinearList)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(LinearList main.cpp linearlist.h)
