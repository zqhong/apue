project(apue)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
include_directories(
        "/usr/include"
        "/usr/local/include"
        "./include"
)

add_executable(sh 01/sh.c)