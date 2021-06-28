#pragma once
#include <iostream>

#ifndef TEMP_
#define TEMP_
using namespace std;

template <class T> class Massiv
{
	int n;
	T arr;
protected:
public:
	Massiv();
	//Massiv(int n);
	Massiv(int N, T Arr);
	int getN();
	T sort();
	T getArr();
	//Massiv<T>& operator = (Massiv<T>& b);
	friend istream& operator >> (istream& in, Massiv<T>& Arr);
	friend ostream& operator << (ostream& os, Massiv<T> Arr);
};
#endif