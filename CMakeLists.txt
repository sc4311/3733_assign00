cmake_minimum_required(VERSION 3.28)
project(assign0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assign0
        driver1.c
        Makefile
        mylinkedlist.c
        mylinkedlist.h)
