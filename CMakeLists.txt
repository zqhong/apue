project(apue)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
include_directories(
        "src/include"
        "src/lib"
        "/usr/include"
        "/usr/local/include"
)

add_executable(cp src/intro/cp.c)
add_executable(cp2 src/intro/cp2.c)
add_executable(getpid src/intro/getpid.c)
add_executable(ls src/intro/ls.c)
add_executable(sh src/intro/sh.c)