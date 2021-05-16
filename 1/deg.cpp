#include "deg.h"
deg::deg()
{
    degree = 0;
    minute = 0;
    second = 0;
}
deg::deg(int a, int b, int c)
{
    degree = a;
    minute = b;
    second = c;
}
deg deg:: operator+(const deg& other)
{
    deg tmp;
    int tmpG = 0, tmpM = 0, tmpS = 0;
    tmp.second = this->second + other.second;
    if (tmp.second >= 60)
    {
        tmpM = tmp.second / 60;
        tmpS = tmp.second - tmpM * 60;
        tmp.second = tmpS;
    }
    tmp.minute = this->minute + other.minute + tmpM;
    if (tmp.minute >= 60)
    {
        tmpG = tmp.minute / 60;
        tmpM = tmp.minute - tmpG * 60;
        tmp.minute = tmpM;
    }
    tmp.degree = this->degree + other.degree + tmpG;
    return tmp;
}
deg deg:: operator-(const deg& other)
{
    deg tmp;
    bool FM = 0;
    tmp.degree = this->degree - other.degree;
    tmp.minute = this->minute - other.minute;
    tmp.second = this->second - other.second;
    cout<<other.degree<<" "<<other.minute<<" "<<other.second<<endl;
    cout<<tmp.degree<<" "<<tmp.minute<<" "<<tmp.second<<endl;
    if (this->second < other.second)
    {
        FM = 1;
        tmp.second = 60 - abs(this->second - other.second);
    }
    if (this->minute < other.minute)
    {
        tmp.degree--;
        tmp.minute = 60 - abs(this->minute - other.minute);
        if (FM == 1)
        {
            tmp.minute--;
        }
    }
    return tmp;
}
deg deg:: operator /(deg& other)
{
    long  double x = (this->get_Numb() / other.get_Numb());
    return get_Grad(x);
}
deg deg:: operator *(deg& other)
{
    long  double x = (this->get_Numb() * other.get_Numb());
    return get_Grad(x);
}
bool deg:: operator ==(deg& other)
{
    return (this->degree==other.degree&&this->minute==other.minute&&this->second&&other.second);
}
bool deg:: operator !=(deg& other)
{
    return !(this->degree==other.degree&&this->minute==other.minute&&this->second&&other.second);
}
float deg::get_Numb()
{
    const int Sec_per_min = 60;
    const int Min_per_degree = 60;
    if(degree!=0||minute!=0||second!=0)
    {
        float tmp =(float(second) / Sec_per_min + float(minute)) / Min_per_degree + degree;

        return tmp;
    }
    return 0;
}
deg deg::get_Grad(long  double x)
{
    int tmpG = 0, tmpM = 0, tmpS = 0;
    tmpG = int(x);
    tmpM = (x - tmpG) * 60;
    tmpS = (((x - tmpG) * 60) - tmpM) * 60;
    cout << tmpG << "  " << tmpM << "   " << tmpS << endl;
    deg tmp(tmpG, tmpM, tmpS);
    return tmp;
}
float deg::get_cos()
{
    return cos(Rad());
}
float deg::get_sin()
{
    return sin(Rad());
}
float deg::get_tg()
{
    return tan(Rad());
}
float deg::get_ctg()
{
    return (1 / get_tg());
}
float deg::get_arccos()
{
    return acos(get_cos()) * (180 / PI);
}
float deg::get_arcsin()
{
    return asin(get_sin()) * (180 / PI);
}
float deg::get_arctg()
{
    return atan(get_tg()) * (180 / PI);
}
float deg::get_arcctg()
{
    float tmp = get_Numb()/sqrt(1+pow(get_Numb(),2));
    return acos(tmp) * (180 / PI);
}
long double deg::Rad()
{
    return ((get_Numb() * PI) / 180);
}
ostream& operator << (ostream& out, const deg& other)
{
    return (out << other.degree << "grad  " << other.minute << "'  " << other.second << "''  ");
}
istream& operator >> (istream& in, deg& other)
{
    char ch;
    in >> other.degree >> ch >> other.minute >> ch >> other.second;
    return in;
}
