cmake_minimum_required(VERSION 3.23)
project(binary C)

set(CMAKE_C_STANDARD 99)

add_executable(binary main.c binary.c binary.h)
