cmake_minimum_required(VERSION 3.31)
project(easing_functions)

set(CMAKE_CXX_STANDARD 20)

add_library(easing_functions SHARED easing.cpp)
