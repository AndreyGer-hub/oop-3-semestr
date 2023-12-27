cmake_minimum_required(VERSION 3.0.0)

set(SOURCES
    ./src/TShared_ptr.h
    ./src/TWeak_ptr.h
    )

include_directories(
    ./src/
    )
add_executable(Lesson04 ./main.cpp ${SOURCES})
