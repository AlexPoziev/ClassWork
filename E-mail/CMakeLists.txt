cmake_minimum_required(VERSION 3.23)
project(E_mail C)

set(CMAKE_C_STANDARD 99)

add_executable(E_mail main.c lexer.c lexer.h lexerTests.c lexerTests.h)
