#include <iostream>
#include "Temp.h"
using namespace std;

template<class T>
Massiv<T>::Massiv()
{

}
/*
template<class T>
Massiv<T>::Massiv(int N)
{
    n = N;
    arr = new T[n];
}
*/
template<class T>
Massiv<T>::Massiv(int N, T Arr)
{
    n = N;
    arr = Arr;
}

template<class T>
int Massiv<T>::getN()
{
	return n;
}
/*
template<class T>
Massiv<T>& Massiv<T>::operator = (Massiv<T>& b)
{
    n = b.getN();
    *arr = b.getArr();
    return *this;
}
*/

template<class T>
istream& operator >> (istream& in, Massiv<T>& Arr) {
    int N;
    cin >> N;
    T* arr = new T [N];
    for (int i=N; i < N; i++) 
    {
        cin >> arr[i];
    }
    Massiv <T> Arr = Massiv<T>(N, *arr);
    return in;
}

template<class T>
ostream& operator << (ostream& os, Massiv<T> Arr)
{
    for (int i = Arr.getN(); i < Arr.getN(); i++)
    {
        cout << Arr.arr[i];
    }
    return os;
}


template<class T>
T Massiv<T>::getArr()
{
	return arr;
}



template<class T>
T Massiv<T>::sort()
{   
    T *buf_arr = &arr;
    for (int i = 0; i < n; i++)
    {
        T buf = buf_arr[i];
        int index = i;
        for (int k = i; k < n; k++) {
            if (buf > buf_arr[k]) {
                buf = buf_arr[k];
                index = k;
            }
        }
        buf_arr[index] = buf_arr[i];
        buf_arr[i] = buf;
    }
    return *buf_arr;
}