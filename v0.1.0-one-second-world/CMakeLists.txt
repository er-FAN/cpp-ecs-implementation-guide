cmake_minimum_required(VERSION 3.16)

project(v0_1_0_one_second_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Object-Oriented example
add_executable(one_second_car one_second_car.cpp)

# Data-Oriented example
add_executable(one_second_system one_second_system.cpp)