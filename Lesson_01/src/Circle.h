#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

class Circle:public IShape
{
   private:
    double r;
public:
    Circle (double aR);
   double calcSquare();
};



#endif
