cmake_minimum_required(VERSION 3.20)
project(challenge3)
set(CMAKE_CXX_STANDARD 11)

link_libraries(nanobench)
add_executable(challenge3 main.cpp eratosthene_table.cpp)
