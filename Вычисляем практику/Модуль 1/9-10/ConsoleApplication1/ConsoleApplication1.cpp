//

#define NOMINMAX
#include <iostream>
#include "Sity.h"
#include <string>
#include <fstream>
#include <Windows.h>
#include <limits>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	short color_c = 9;
	bool exit = 0;
	ifstream fin;
	fin.open("C:\\Users\\mmm\\Desktop\\sity.txt");

	int n;
	//cout << "Введите количество районов в городе: ";
	fin >> n;
	Sity MySity(n);
	fin >> MySity;

	while (!exit) {
		system("cls");
		cout << "Город " << MySity.get_sity_name() << ": \n";
		SetConsoleTextAttribute(hConsole, color_c); cout << "  1"; SetConsoleTextAttribute(hConsole, 15); cout << ". Отобразить районы\n";
		SetConsoleTextAttribute(hConsole, color_c); cout << "  2"; SetConsoleTextAttribute(hConsole, 15); cout << ". Сортировать районы\n";
		SetConsoleTextAttribute(hConsole, color_c); cout << "  3"; SetConsoleTextAttribute(hConsole, 15); cout << ". Показать районы с определённым колиеством домов\n";
		SetConsoleTextAttribute(hConsole, color_c); cout << "  4"; SetConsoleTextAttribute(hConsole, 15); cout << ". Выход\n";

		int menu;
		cin >> menu;
		switch (menu)
		{
		default:
			system("cls");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка! Данного варианта нет в списке!\n";
			SetConsoleTextAttribute(hConsole, 4);
			for (int i = 0; i < 100; ++i) {
				cout << "•";
				Sleep(10);
			}
			SetConsoleTextAttribute(hConsole, 15);
			break;
		case 1:
			system("cls");
			cout << MySity;
			system("pause");
			break;
		case 2:
			system("cls");
			MySity.sort();
			cout << MySity;
			system("pause");
			break;
		case 3:
			system("cls");
			MySity.searchAndDisplay();
			system("pause");
			break;
		case 4:
			system("cls");
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Спасибо за испозование программы!";
			Sleep(3000);
			exit = 1;
			SetConsoleTextAttribute(hConsole, 15);
			break;


		}
	}
	return 0;
}