#include <iostream>

#include "TCalc.h"
#include "TCalcTemp.h"
#include "TTaskTwo.h"
#include "TMyVector.h"

using namespace std;

int main()
{
    TCalc Calc;
    cout<<"Int Result= "<<Calc.Mult(5,6)<<endl;
    cout<<"Double Result= "<<Calc.Mult(3.2,5.4)<<endl;

    TCalcTemp CalcTemp;
    cout<<"Int(temp) Result= "<<CalcTemp.Mult(5,6)<<endl;
    cout<<"Double(temp) Result= "<<CalcTemp.Sum(3.2,5.4)<<endl;
    cout<<"Double/int(temp) Result= "<<CalcTemp.Mult(3,5.3)<<endl;

    TTaskTwo TaskTwo;
    cout<<"More Result= "<<TaskTwo.More(4.2,4)<<endl;
    cout<<"Less Result= "<<TaskTwo.Less(4.2,4)<<endl;
    cout<<"Equally Result= "<<TaskTwo.Equally(4.2,4.2)<<endl;

    string c = "2";
    string d ="1";
    string f ="3";

    cout<<"Sum digit Result= "<<TaskTwo.Sum(5,5)<<endl;
    cout<<"Sum str Result= "<<TaskTwo.Sum(c,d)<<endl;
    cout<<"More str Result= "<<TaskTwo.More(d,f)<<endl;
    cout<<"Less str Result= "<<TaskTwo.Less(d,f)<<endl;
    cout<<"Equally str Result= "<<TaskTwo.Equally(d,f)<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++"<<endl;

    TMyVector<int> vec;
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(19);
    vec.PrintVector();
    vec.insert(1,13);
    vec.PrintVector();
    vec.insert(2,23);
    vec.PrintVector();
    vec.pop_back();
    vec.PrintVector();
    TMyVector<int> vec2(2,2);
    vec2.PrintVector();
    vec2.insert(1,4);
    vec2.PrintVector();
    vec2.insert(1,421);
    vec2.PrintVector();
    vec2.insert(1,1313);
    vec2.PrintVector();
    vec2.insert(4,777);
    vec2.PrintVector();
    TMyVector<double> vec3;
    vec3.push_back(2.3);
    vec3.push_back(4.3);
    vec3.push_back(13.242);
    vec3.PrintVector();
    TMyVector<char> vec4;
    vec4.push_back('e');
    vec4.push_back('d');
    vec4.push_back('a');
    vec4.PrintVector();
    vec4.insert(2,'A');
    vec4.PrintVector();
    return 0;
}
