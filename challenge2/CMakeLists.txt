cmake_minimum_required(VERSION 3.20)
project(challenge2)

set(CMAKE_CXX_STANDARD 11)

link_libraries(nanobench)
add_executable(challenge2 main.cpp)
