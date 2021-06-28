#include "Sity.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Sity::Sity()
{
	amount = 0;
	districts = new District[amount]{ 0 };
	sity_name = { 0 };
}

Sity::Sity(int Districts_amount)
{
	amount = Districts_amount;
	districts = new District[amount]{ 0 };
	sity_name = { 0 };
}

Sity::~Sity()
{
	delete[] districts;
}

void Sity::set_sity_name(string name)
{
	sity_name = name;
}

string Sity::get_sity_name()
{
	return sity_name;
}

District Sity::get_districts()
{
	return *districts;
}

void Sity::sort()
{
	sorting(districts);
}

void Sity::searchAndDisplay()
{
	int maximum = 0, minimum = 0;
	cout << "Введите диапазон количества домов: ";
	while (!(cin >> minimum >> maximum))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Некорректный ввод! Введите корректный диапазон количества домов: ";
	}

	bool is_found = 0;
	for (int i = 0; i < amount; i++) {

		if (districts[i].get_amount() > minimum && districts[i].get_amount() < maximum) {
			if (!is_found) {
				cout << "Районы, соответствующие диапазону количества домов [" << minimum << ", " << maximum << "]: \n";
			}
			cout << districts[i] << endl;
			is_found = 1;

		}
	}
	if (!is_found) {
		cout << "Нет районов в городе, соответствующих данному диапазону количества домов [" << minimum << ", " << maximum << "]\n" << endl;
	}
}

template <typename T> void Sity::sorting(T* arr)
{
	T buf;
	for (int i = 1; i < amount; ++i)
	{
		buf = arr[i];
		for (int k = i; k >= 0; --k) {
			if (buf.get_amount() < arr[k].get_amount()) {
				arr[k + 1] = arr[k];
				arr[k] = buf;
			}
		}
	}
}

ifstream& operator >>(ifstream& in, Sity& sity) {
	string str;
	in.ignore();
	getline(in, str);
	sity.set_sity_name(str);
	for (int i = 0; i < sity.amount; ++i) {
		in >> sity.districts[i];
	}
	return in;
}

istream& operator >>(istream& in, Sity& sity) {
	string str;
	cout << "Введите название города: ";
	in.ignore();
	getline(in, str);
	sity.set_sity_name(str);
	for (int i = 0; i < sity.amount; ++i) {
		in >> sity.districts[i];
	}
	return in;
}

ofstream& operator <<(ofstream& out, Sity& sity) {
	out << "Город " << sity.get_sity_name() << endl;
	for (int i = 0; i < sity.amount; ++i) {
		out << sity.districts[i] << endl;
	}
	return out;
}

ostream& operator <<(ostream& out, Sity& sity) {
	out << "Город " << sity.get_sity_name() << endl;
	for (int i = 0; i < sity.amount; ++i) {
		out << sity.districts[i] << endl;
	}
	return out;
}