cmake_minimum_required(VERSION 3.15)
project(OOC C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(example EXAMPLE)
aux_source_directory(ooc/src SRCS)
add_executable(ooc ${EXAMPLE} ${SRCS} main.c)