#pragma once

#include <string>

using namespace std;

class District
{
private:
	string district_name;
	int amount;
public:
	District();
	District(int House_amount);
	~District();
	int get_amount();
	void set_district_name(string name);
	string get_district_name();
	void set_sity_name(string name);
	friend ifstream& operator >>(ifstream& in, District& district);
	friend istream& operator >>(istream& in, District& district);
	friend ofstream& operator <<(ofstream& out, District& district);
	friend ostream& operator <<(ostream& out, District& district);
};

