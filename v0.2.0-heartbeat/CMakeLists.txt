cmake_minimum_required(VERSION 3.16)

project(v0_2_0_heartbeat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Object-Oriented example
add_executable(heartbeat_car heartbeat_car.cpp)

# Data-Oriented example
add_executable(heartbeat_system heartbeat_system.cpp)

add_executable(multi_heart multi_heart.cpp)