cmake_minimum_required(VERSION 3.28)
project(Set C)

set(CMAKE_C_STANDARD 23)

add_executable(Set main.c
        Set.h
        New.h
        Object.h
        Set.c
)
