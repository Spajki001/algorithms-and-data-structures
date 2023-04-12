cmake_minimum_required(VERSION 3.25)
project(LV3 C)

set(CMAKE_C_STANDARD 11)

add_executable(LV3 main.c stack.c stack.h stack_linked_list.c stack_linked_list.h)
