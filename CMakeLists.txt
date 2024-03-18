cmake_minimum_required(VERSION 3.27)
project(Second_Laba C)

set(CMAKE_C_STANDARD 11)

add_executable(Second_Laba main.c
        dynamic_array.h
        list_stack.c
        tests_dinamic.h
        tests_dinamic.c)
