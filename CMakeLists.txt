cmake_minimum_required(VERSION 3.17)
project(GNL C)

set(CMAKE_C_STANDARD 99)

include_directories(./)

add_executable(GNL
        main.c
        get_next_line.c
        get_next_line_utils.c
        get_next_line.h)