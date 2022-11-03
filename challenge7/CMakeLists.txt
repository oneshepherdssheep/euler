cmake_minimum_required(VERSION 3.20)
set(APP_NAME "challenge7")
project(${APP_NAME})
set(CMAKE_CXX_STANDARD 11)

link_libraries(nanobench)
add_executable(${APP_NAME} main.cpp)
target_include_directories(${APP_NAME} PUBLIC ${ERATOSTHENE_SIEVE_LIBRARY_INCLUDES})
target_link_libraries(${APP_NAME} ${ERATOSTHENE_SIEVE_LIBRARY_NAME})
