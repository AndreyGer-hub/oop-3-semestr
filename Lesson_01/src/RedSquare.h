#ifndef REDSQUARE_H
#define REDSQUARE_H

#include <vector>
#include "IShape.h"

class RedSquare
{
private:
    std::vector<IShape*> _data;

public:
    void addShape(IShape* _figure);
    double calcSquare();

};


#endif
