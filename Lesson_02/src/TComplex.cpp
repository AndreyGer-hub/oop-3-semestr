#include "TComplex.h"


TComplex TComplex::operator+(TComplex &obj)
{
    double re_v;
    double im_v;
    re_v=_re_value+obj.real();
    im_v=_im_value+obj.imag();
    TComplex Sum(re_v,im_v);
    return Sum;
}
TComplex TComplex::operator-(TComplex &obj)
{
    double re_v;
    double im_v;
    re_v=_re_value-obj.real();
    im_v=_im_value-obj.imag();
    TComplex Differ(re_v,im_v);
    return Differ;
}

TComplex TComplex::operator*(TComplex &obj)
{
    double re_v;
    double im_v;
    re_v=_re_value*obj.real()-_im_value*obj.imag();
    im_v=_re_value*obj.imag()+_im_value*obj.real();
    TComplex Multiplication(re_v,im_v);
    return Multiplication;
}

void TComplex::setReal(double re_v)
{
    _re_value = re_v;
}

void TComplex::setImag(double im_v)
{
    _im_value=im_v;
}

double TComplex::real()
{
    return _re_value;
}

double TComplex::imag()
{
    return _im_value;
}

TComplex::TComplex()
{

}

TComplex::TComplex(double re, double im)
{
    _re_value=re;
    _im_value=im;
}

TComplex::TComplex(TComplex &obj)
{
  _re_value=obj.real();
  _im_value=obj.imag();
}

TComplex::~TComplex()
{

}
