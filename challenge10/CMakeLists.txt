cmake_minimum_required(VERSION 3.20)
project(challenge10)
set(CHALLENGE_APP_NAME "challenge10")
set(CMAKE_CXX_STANDARD 11)
link_libraries(nanobench)
add_executable(challenge10 main.cpp)

target_include_directories(${CHALLENGE_APP_NAME} PUBLIC ${ERATOSTHENE_SIEVE_LIBRARY_INCLUDES})
target_link_libraries(${CHALLENGE_APP_NAME} ${ERATOSTHENE_SIEVE_LIBRARY_NAME})

