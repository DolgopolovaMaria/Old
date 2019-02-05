// Task4.3.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "0 - �����" << endl;
	cout << "1 - �������� ������" << endl;
	cout << "2 - ����������� ��� ��������� ������" << endl;
	cout << "3 - ����� ������� �� �����" << endl;
	cout << "4 - ����� ��� �� ��������" << endl;
	cout << "5 - ��������� ������� ������ � ����" << endl;
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
			cout << "������� ���" << endl;
			cin >> name;
			findNumber(arrayOfRecords, n, name);
			break;
		case 4:
			cout << "������� �����" << endl;
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
