#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>


class TComplex
{
private:
    double _re_value;
    double _im_value;
public:
    TComplex operator+(TComplex& obj);
    TComplex operator-(TComplex& obj);
    TComplex operator*(TComplex& obj);

    void setReal(double re_v);
    void setImag(double im_v);

    double real();
    double imag();

   TComplex();
   TComplex(double re, double im);
   TComplex(TComplex& obj);
  ~TComplex();
};

#endif
