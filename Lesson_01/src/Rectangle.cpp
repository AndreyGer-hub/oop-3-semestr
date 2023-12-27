#include "Rectangle.h"

Rectangle::Rectangle (double mA,double mB)
{
 a=mA;
 b=mB;
}
double Rectangle:: calcSquare()
{
    return a*b;
}
