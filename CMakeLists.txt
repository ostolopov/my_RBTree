cmake_minimum_required(VERSION 3.29)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp
        trees_structs.cpp
        trees_structs.h
        utils.cpp
        utils.h
        ind_funcs.cpp
        ind_funcs.h)
