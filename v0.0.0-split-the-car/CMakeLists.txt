cmake_minimum_required(VERSION 3.16)

project(v0_0_0_split_the_car LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Object-Oriented example
add_executable(cars cars.cpp)

# Data-Oriented example
add_executable(splited_cars splited_cars.cpp)