cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
project("euler" VERSION 1.0.0 LANGUAGES C CXX)

# --------------------------
# challenge options
# --------------------------

option(ENABLE_ERATOSTHENE_SIEVE_LIBRARY "Enable Eratosthene Library" ON)
set(ERATOSTHENE_SIEVE_LIBRARY_NAME "eratosthene_sieve")


# --------------------------
# challenge projects
# --------------------------

add_subdirectory(challenge1)
add_subdirectory(challenge2)
add_subdirectory(challenge3)
add_subdirectory(challenge4)
add_subdirectory(challenge5)
add_subdirectory(challenge6)
add_subdirectory(challenge7)
add_subdirectory(challenge8)
add_subdirectory(challenge9)

# --------------------------
# submodules
# --------------------------

add_subdirectory(nanobench)

# --------------------------
# custom/challenge libraries
# --------------------------

if(ENABLE_ERATOSTHENE_SIEVE_LIBRARY)
    add_subdirectory(challenge_library)
endif()