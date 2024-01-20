cmake_minimum_required(VERSION 3.26)
project(advent_of_code_23 C)

set(CMAKE_C_STANDARD 11)

include_directories(helper)

add_executable(advent_of_code_23
        01/src/main.c
        helper/file_helper.c
        helper/file_helper.h
        helper/string_helper.h
        helper/string_helper.c
        helper/array_helper.h
        helper/array_helper.c
        helper/math_helper.c
        helper/math_helper.h
        helper/debug_helper.c
        helper/debug_helper.h
        helper/assert_helper.c
        helper/assert_helper.h
        helper/misc_helper.c
        helper/misc_helper.h
        02/src/main.c
        helper/helpers.h
        03/src/main.c
        06/src/main.c)
