cmake_minimum_required(VERSION 3.0)

project(lab1.1 VERSION 1.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c
        struct.c struct.h
	menu.c  menu.h
        ${CMAKE_SOURCE_DIR}/CException_lib/CException.c ${CMAKE_SOURCE_DIR}/CException_lib/CException.h
        function_example.c function_example.h)
