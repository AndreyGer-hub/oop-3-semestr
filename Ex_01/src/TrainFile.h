#ifndef TRAINFILE_H
#define TRAINFILE_H

#include <string>
#include <iostream>
#include <fstream>

#include "TTrain.h"

class TrainFile
{
private:
    TTrain* _train =nullptr;
    std::string _filePath;
public:

    TTrain* getNewTrain();
    int readFile();
    void setFilePath(std::string fpath);

    TrainFile();
    ~TrainFile();
};

#endif
