cmake_minimum_required(VERSION 3.10)
project(AGRIC_SENSOR)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(AGRIC_SENSOR 
src/main.cpp
src/SensorReading.cpp
src/SensorLog.cpp)