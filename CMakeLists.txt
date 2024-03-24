cmake_minimum_required(VERSION 3.28)
project(Market_Billing_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Market_Billing_System
        main.cpp
        Bill.h
        Bill.cpp)
