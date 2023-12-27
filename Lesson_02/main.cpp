#include <iostream>
#include "TComplex.h"

using namespace std;

int main()
{
    double real_v=2;
    double imag_v =4;

    TComplex A(real_v,imag_v);
    TComplex B(real_v*2,imag_v*2);
    TComplex C;
    cout<<"A="<<A.real()<<"+"<<A.imag()<<"i"<<endl;
    cout<<"B="<<B.real()<<"+"<<B.imag()<<"i"<<endl;
    C=A-A;
    cout<<"C=A-A="<<C.real()<<"+"<<C.imag()<<"i"<<endl;
    C=A+B;
    cout<<"C=A+B="<<C.real()<<"+"<<C.imag()<<"i"<<endl;
    C=A*B;
    cout<<"C=A*B="<<C.real()<<"+"<<C.imag()<<"i"<<endl;
    return 0;
}
