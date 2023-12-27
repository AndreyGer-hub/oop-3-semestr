#ifndef TCALC_H
#define TCALC_H

#include <iostream>

class TCalc
{
private:

public:
    int Sum(int a, int b);
    int Substruct(int a,int b);
    int Mult(int a, int b);
    int Diff(int a, int b);

    double Sum(double a, double b);
    double Substruct(double a,double b);
    double Mult(double a, double b);
    double Diff(double a, double b);

    TCalc();
   ~TCalc();
};

#endif
