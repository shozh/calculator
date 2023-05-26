cmake_minimum_required(VERSION 3.25)
project(calculator C)

set(CMAKE_C_STANDARD 23)

add_executable(calculator main.c stack.c list.c)
add_executable(runner run.c stack.c list.c)
