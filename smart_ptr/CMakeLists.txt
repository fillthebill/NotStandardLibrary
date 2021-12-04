cmake_minimum_required(VERSION 3.20)
project(smart_ptr)

set(CMAKE_CXX_STANDARD 14)

add_executable(smart_ptr smart_ptr_test.cpp ../MyVector/MyVector_iterator.h)
include_directories(.)