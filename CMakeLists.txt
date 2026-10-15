cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

include_directories(include)

# Core Library
add_library(learn_c_lib
    src/roadmap.c
    src/memory_pool.c
)

# Main Executable
add_executable(learn_c
    src/main.c
)
target_link_libraries(learn_c PRIVATE learn_c_lib)

# Tests Executable
enable_testing()
add_executable(test_runner
    tests/test_main.c
)
target_link_libraries(test_runner PRIVATE learn_c_lib)
add_test(NAME test_runner COMMAND test_runner)
