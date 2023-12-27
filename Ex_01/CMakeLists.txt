cmake_minimum_required(VERSION 3.0.0)

set(SOURCES
    ./src/TWagon.cpp
    ./src/TTrain.cpp
    ./src/TrainConsole.cpp
    ./src/TrainFile.cpp
    ./src/File.txt
    )
set(HEADERS
        ./src/TWagon.h
        ./src/TTrain.h
        ./src/TrainConsole.h
        ./src/TrainFile.h
    )
include_directories(
	./src/
    )
add_executable(TrainTomas ./main.cpp ${SOURCES} ${HEADERS})
