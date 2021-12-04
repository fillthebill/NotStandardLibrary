cmake_minimum_required(VERSION 3.20)
project(query)

set(CMAKE_CXX_STANDARD 14)

add_executable(query query.cpp)
include_directories(../smart_ptr)