#pragma once
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159265
class deg
{
private:
    int degree;
    int minute;
    int second;
public:
    deg();
    deg(int a, int b, int c);
    deg operator + (const deg& other);
    deg operator - (const deg& other);
    deg operator / (deg& other);
    deg operator * (deg& other);
    bool operator == (deg& other);
    bool operator != (deg& other);
    friend ostream& operator << (ostream& out, const deg& other);
    friend istream& operator >> (istream& in, deg& other);
    long double Rad();
    float get_Numb();
    deg get_Grad(long  double x);
    float get_cos();
    float get_sin();
    float get_tg();
    float get_ctg();
    float get_arccos();
    float get_arcsin();
    float get_arctg();
    float get_arcctg();
};
