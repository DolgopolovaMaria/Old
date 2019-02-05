// Task4.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "phoneNumbers.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 100;
	Record arrayOfRecords[n] = {};

	readingFromFile(arrayOfRecords, n);

	cout << "0 - выйти" << endl;
	cout << "1 - добавить запись" << endl;
	cout << "2 - распечатать все имеющиеся записи" << endl;
	cout << "3 - найти телефон по имени" << endl;
	cout << "4 - найти имя по телефону" << endl;
	cout << "5 - сохранить текущие данные в файл" << endl;
	cout << endl;

	string name;
	string number;
	bool exit = false;

	while (!exit)
	{
		int doing = 0;
		cin >> doing;
		switch (doing)
		{
		case 0:
			exit = true;
			break;
		case 1:
			addNote(arrayOfRecords, n);
			break;
		case 2:
			print(arrayOfRecords, n);
			break;
		case 3:
			cout << "введите имя" << endl;
			cin >> name;
			findNumber(arrayOfRecords, n, name);
			break;
		case 4:
			cout << "введите номер" << endl;
			cin >> number;
			findName(arrayOfRecords, n, number);
			break;
		case 5:
			saveInFile(arrayOfRecords, n);
			break;
		default:
			cout << "Error!";
		}
	}
	
	return 0;
}
