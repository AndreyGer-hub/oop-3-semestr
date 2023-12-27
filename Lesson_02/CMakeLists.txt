cmake_minimum_required(VERSION 3.0.0)

set(SOURCES
    ./src/TComplex.h
    ./src/TComplex.cpp
    )

include_directories(
    ./src/
    )
add_executable(Lesson02 ./main.cpp ${SOURCES})
