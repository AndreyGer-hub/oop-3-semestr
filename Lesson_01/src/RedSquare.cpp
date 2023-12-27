#include "RedSquare.h"

void RedSquare::addShape(IShape *_figure)
{
    _data.push_back(_figure);

}

double RedSquare::calcSquare()
{
    double sqr=0;
    for(int i =0; i<_data.size();i++)
    {
        sqr+=_data.at(i)->calcSquare();
    }
    return sqr;
}
