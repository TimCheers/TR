#ifndef GRAPHKV_H
#define GRAPHKV_H
#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
template<class T>
class GRAPHKV
{
    vector<T> VList;
public:
    int SMatrix[20][20] = { 0 };
    GRAPHKV();
    ~GRAPHKV();
    void PushEdg(const T& vert1, const T& vert2, int weight);
    void PushVert(const T& vert);
    int GetVertPos(const T& vert);
    bool Empty();
    bool Full();
    string ShowMatrix();
};
template<class T>
void GRAPHKV<T>::PushVert(const T& vert)
{
    if (!this->Full())
    {
        this->VList.push_back(vert);
    }
    else {
        cout << "FUll " << endl;
        return;
    }
}
template<class T>
bool GRAPHKV<T>::Empty()
{
    if (this->VList.size() != 0)
        return false;
    else
        return true;
}
template<class T>
bool GRAPHKV<T>::Full()
{
    return (VList.size() == 20);
}
template <class T>
int GRAPHKV<T>::GetVertPos(const T& vert)
{
    for (int i = 0; i < this->VList.size(); ++i)
    {
        if (this->VList[i] == vert)
            return i;
    }
    return -1;
}
template<class T>
GRAPHKV<T>::GRAPHKV()
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            this->SMatrix[i][j] = 0;
        }
    }
}
template<class T>
void GRAPHKV<T>::PushEdg(const T& vert1, const T& vert2, int weight)
{
    cout<<"\nDone111\n";
    if (this->GetVertPos(vert1) != (-1) && this->GetVertPos(vert2) != (-1))
    {
        int vertPos1 = GetVertPos(vert1);
        int vertPos2 = GetVertPos(vert2);
        if (this->SMatrix[vertPos1][vertPos2] != 0
            && this->SMatrix[vertPos2][vertPos1] != 0)
        {
            return;
        }
        else
        {
            this->SMatrix[vertPos1][vertPos2] = weight;
            this->SMatrix[vertPos2][vertPos1] = weight;
        }
    }
    else
    {
        return;
    }
}
template<class T>
string GRAPHKV<T>::ShowMatrix()
{
    string S;
    if (!this->Empty()) {
        cout << "Matrix: " << endl;
        S+="Matrix: \n";
        for (int i = 0, VListSize = this->VList.size(); i < VListSize; ++i)
        {
            cout << this->VList[i] << " ";
            S+=to_string(this->VList[i]) + "\t";
            for (int j = 0; j < VListSize; ++j)
            {
                cout << " " << this->SMatrix[i][j] << " ";
                S+=to_string(this->SMatrix[i][j]) + "\t";
            }
            S+="\n";
            cout << endl;
        }
        return S;
    }

}
template<class T>
GRAPHKV<T>::~GRAPHKV() {}
#endif // GRAPHKV_H
