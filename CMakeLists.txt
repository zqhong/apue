project(apue)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
include_directories(
        "src/include"
        "src/lib"
        "/usr/include"
        "/usr/local/include"
)

add_executable(cp src/01_intro/cp.c)
add_executable(cp2 src/01_intro/cp2.c)
add_executable(getpid src/01_intro/getpid.c)
add_executable(ls src/01_intro/ls.c)
add_executable(sh src/01_intro/sh.c)
add_executable(sh2 src/01_intro/sh2.c)
add_executable(error src/01_intro/error.c)
add_executable(userinfo src/01_intro/userinfo.c)