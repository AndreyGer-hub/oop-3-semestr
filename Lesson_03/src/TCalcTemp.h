#ifndef TCALCTEMP_H
#define TCALCTEMP_H

#include <iostream>

class TCalcTemp
{
private:

public:
    template <typename T1,typename T2 > T1 Sum(T1,T2);
    template <typename T1,typename T2 > T1 Substruct(T1,T2);
    template <typename T1,typename T2 > T1 Mult(T1,T2);
    template <typename T1,typename T2 > T1 Diff(T1,T2);

    TCalcTemp() {};
    ~TCalcTemp() {};
};

template <typename T1,typename T2 > T1 TCalcTemp::Sum(T1 a,T2 b)
{
    return a+b;
}
template <typename T1,typename T2 > T1 TCalcTemp::Substruct(T1 a ,T2 b)
{
    return a-b;
}
template <typename T1,typename T2 > T1 TCalcTemp::Mult(T1 a ,T2 b)
{
    return a*b;
}
template <typename T1,typename T2 > T1 TCalcTemp::Diff(T1 a ,T2 b)
{
    return a/b;
}
#endif
