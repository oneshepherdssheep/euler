cmake_minimum_required(VERSION 3.20)
project(challenge13)
set(CMAKE_CXX_STANDARD 11)
link_libraries(nanobench)
add_executable(challenge13 main.cpp)
target_link_libraries(challenge13 ${NUMERALS_LIBRARY_NAME})
target_include_directories(challenge13 PUBLIC ${NUMERALS_LIBRARY_NAME_INCLUDES})
