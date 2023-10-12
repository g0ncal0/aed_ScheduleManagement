cmake_minimum_required(VERSION 3.25)
project(UNISchedule)

set(CMAKE_CXX_STANDARD 17)

add_executable(UNISchedule schedule/main.cpp)
add_executable(Parse parser/exampleparser.cpp)
