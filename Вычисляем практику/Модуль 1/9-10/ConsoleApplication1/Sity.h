#pragma once

#include "District.h"
#include <string>

class Sity {
private:
	int amount;
	District* districts;
	string sity_name;
public:
	Sity();
	Sity(int Districts_amount);
	~Sity();
	void set_sity_name(string name);
	string get_sity_name();
	District get_districts();
	template <typename T> void sorting(T* arr);
	void sort();
	void searchAndDisplay();
	friend ifstream& operator >>(ifstream& in, Sity& sity);
	friend istream& operator >>(istream& in, Sity& sity);
	friend ofstream& operator <<(ofstream& out, Sity& sity);
	friend ostream& operator <<(ostream& out, Sity& sity);
};