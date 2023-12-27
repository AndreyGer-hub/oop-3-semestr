#ifndef TTASKTWO_H
#define TTASKTWO_H

#include <iostream>
#include <math.h>

class TTaskTwo
{
private:

public:
    template <typename T1,typename T2 > T1 Sum(T1,T2);
    template <typename T1,typename T2 > bool More(T1,T2);
    template <typename T1,typename T2 > bool Less(T1,T2);
    template <typename T1,typename T2 > bool Equally(T1,T2);

    int SumCharStr(std::string str);

    TTaskTwo() {};
    ~TTaskTwo() {};
};

int TTaskTwo::SumCharStr(std::string str)
{
    int sum=0;
    for(int i=0;i<str.length();i++)
    {
        sum=sum+str[i]*pow(10,str.length()-i-1);
    }
    return sum;
}

template <typename T1,typename T2 > T1 TTaskTwo::Sum(T1 a,T2 b)
{
    return a+b;
}

template <> std::string TTaskTwo::Sum(std::string a,std::string b)
{
    std::string res;
    res = a+b;
    return res;
}

template <> bool TTaskTwo::More(std::string a,std::string b)
{
    bool res = true;
    if (a.length()!=b.length())
    {
          if (a.length()<b.length()) res =false;
    } else
    {
        if(SumCharStr(a)<SumCharStr(b)) res =false;
    }
    return res;
}

template <> bool TTaskTwo::Less(std::string a,std::string b)
{
    bool res = true;
    if (a.length()!=b.length())
    {
          if (a.length()>b.length()) res =false;
    } else
    {
        if(SumCharStr(a)>SumCharStr(b)) res =false;
    }
    return res;
}

template <> bool TTaskTwo::Equally(std::string a,std::string b)
{
    bool res = true;
    if (SumCharStr(a)!= SumCharStr(b))
    {
        res =false;
    }
    return res;
}

template <typename T1,typename T2 > bool TTaskTwo::More(T1 a,T2 b)
{
    bool res = true;
    if(a<b)
    {
        res = false;
    }
    return res;
}

template <typename T1,typename T2 > bool TTaskTwo::Less(T1 a,T2 b)
{
    bool res = true;
    if(a>b)
    {
        res = false;
    }
    return res;
}

template <typename T1,typename T2 > bool TTaskTwo::Equally(T1 a,T2 b)
{
    bool res = true;
    if(a!=b)
    {
        res = false;
    }
    return res;
}
#endif
