cmake_minimum_required(VERSION 3.20)
project(challenge1)

set(CMAKE_CXX_STANDARD 11)

link_libraries(nanobench)
add_executable(challenge1 main.cpp)
