cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project ("storyBoard")

set (CMAKE_C_COMPILER "gcc-5")
set (CMAKE_CXX_COMPILER "g++-5")
set (CMAKE_CXX_FLAGS "-std=c++17")

add_executable(storyBoard storyBoard.cpp main.cpp)
