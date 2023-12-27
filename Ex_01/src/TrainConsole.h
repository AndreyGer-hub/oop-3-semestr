#ifndef TRAINCONSOLE_H
#define TRAINCONSOLE_H

#include <string>
#include <iostream>
#include "TTrain.h"

class TrainConsole
{
private:
    TTrain* _train = nullptr;
public:

    TTrain* getNewTrain();
    void consoleMenu();

    TrainConsole();
    ~TrainConsole();
};

#endif
