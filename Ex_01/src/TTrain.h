#ifndef TTRAIN_H
#define TTRAIN_H

#include <string>
#include <TWagon.h>
#include <iostream>

class TTrain
{
private:
    TWagon* _headWagon = nullptr;
    int _size=0;
public:
    //void changeSize();
    void push(TWagon* newWagon);
    void PrintTrain();

    int getSize();
    TWagon* at(int index);
    TWagon* pop();
    TWagon* getHead();

    TTrain();
    ~TTrain();
};

#endif
