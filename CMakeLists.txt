cmake_minimum_required(VERSION 3.23)
project(m1)

set(CMAKE_CXX_STANDARD 14)

add_executable(m1 ms3.cpp Utilities.cpp Utilities.h Station.cpp Station.h CustomerOrder.cpp CustomerOrder.h Workstation.cpp Workstation.h LineManager.cpp LineManager.h)
