project(apue)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_BUILD_TYPE "Debug")
include_directories(
        "src/include"
        "src/lib"
        "/usr/include"
        "/usr/local/include"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/01_intro)
add_executable(cp src/01_intro/cp.c)
add_executable(cp2 src/01_intro/cp2.c)
add_executable(getpid src/01_intro/getpid.c)
add_executable(ls src/01_intro/ls.c)
add_executable(sh src/01_intro/sh.c)
add_executable(sh2 src/01_intro/sh2.c)
add_executable(error src/01_intro/error.c)
add_executable(userinfo src/01_intro/userinfo.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/02_standstard)
add_executable(conf src/02_standard/conf.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/03_fileio)
add_executable(lseek src/03_fileio/lseek.c)
add_executable(hole src/03_fileio/hole.c)
add_executable(cat src/03_fileio/cat.c)