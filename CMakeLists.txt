cmake_minimum_required(VERSION 3.12)
project(assignment20181_wezpez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment20181_wezpez
        NearlySorted.h
        testNearlySorted.cpp)
