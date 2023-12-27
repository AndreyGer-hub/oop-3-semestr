cmake_minimum_required(VERSION 3.0.0)

set(SOURCES
    ./src/TCalc.cpp
    ./src/TCalc.h
    ./src/TCalcTemp.h
    ./src/TTaskTwo.h
    ./src/TMyVector.h
    )

include_directories(
    ./src/
    )
add_executable(Lesson03 ./main.cpp ${SOURCES})
