cmake_minimum_required(VERSION 3.13)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project producent.c utils.c utils.h consts.h)