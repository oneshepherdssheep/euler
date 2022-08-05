cmake_minimum_required(VERSION 3.20)

project("euler" VERSION 1.0.0 LANGUAGES C CXX)

# --------------------------
# challenge projects
# --------------------------

add_subdirectory(challenge1)
add_subdirectory(challenge2)
add_subdirectory(challenge3)
add_subdirectory(challenge4)
add_subdirectory(challenge5)

# --------------------------
# submodules
# --------------------------

add_subdirectory(nanobench)