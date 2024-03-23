cmake_minimum_required(VERSION 3.27)
project(Second_Laba C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-std=c11)
add_executable(Second_Laba main.c
        list_stack.c
        tests_dynamic.c
        dynamic_array.c
        tests_list.c)
