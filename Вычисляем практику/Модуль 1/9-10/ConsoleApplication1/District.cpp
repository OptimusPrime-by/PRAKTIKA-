#include "District.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

District::District()
{
	amount = 0;
	district_name = { 0 };
}

District::District(int House_amount)
{
	amount = House_amount;
	district_name = { 0 };
}

District::~District()
{
}

int District::get_amount()
{
	return amount;
}

void District::set_district_name(string name)
{
	district_name = name;
}

string District::get_district_name()
{
	return district_name;
}

void District::set_sity_name(string name)
{
	district_name = name;
}

ifstream& operator >>(ifstream& in, District& district) {
	string str;
	in.ignore();
	getline(in, str);
	district.set_district_name(str);
	in >> district.amount;
	return in;
}

istream& operator >>(istream& in, District& district) {
	cout << "Введите название района: b57 а a";
	string str;
	in.ignore();
	getline(in, str);
	district.set_district_name(str);
	cout << "Введите количество домов в районе: ";
	in >> district.amount;
	return in;
}

ofstream& operator <<(ofstream& out, District& district) {
	out << district.get_district_name() << endl;
	out << district.get_amount();
	return out;
}

ostream&  operator <<(ostream& out, District& district) {
	out << "Район: " << district.get_district_name() << endl;
	out << "Количество домов: " << district.get_amount();
	return out;
}