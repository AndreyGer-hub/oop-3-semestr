#include "Triangle.h"

TriAngle::TriAngle (double mA, double mH)
{
 a=mA;
 h=mH;
}
double TriAngle:: calcSquare()
{
    return (1./2)*a*h;
}
