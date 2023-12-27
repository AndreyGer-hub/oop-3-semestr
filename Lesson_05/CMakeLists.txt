cmake_minimum_required(VERSION 3.0.0)

set(SOURCES	
	./src/TBubbleSort.h
    )

include_directories(
    ./src/
    )
add_executable(Lesson05 ./main.cpp ${SOURCES})
