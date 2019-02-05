// Task4.4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct record
{
	string number = {};
	string name = {};
};


void addNote(struct record arrayOfRecords[], int lengthOfArray)
{
	cout << "������� ���" << endl;
	string newName;
	cin >> newName;
	cout << "������� ����� ��������" << endl;
	string newNumber;
	cin >> newNumber;

	int i = 0;
	while ((newName < arrayOfRecords[i].name) && (i < lengthOfArray))
	{
		i++;
	}
	for (int j = lengthOfArray - 1; j > i; j--)
	{
		arrayOfRecords[j].name = arrayOfRecords[j - 1].name;
		arrayOfRecords[j].number = arrayOfRecords[j - 1].number;
	}
	arrayOfRecords[i].name = newName;
	arrayOfRecords[i].number = newNumber;
}


void print(struct record array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i].name != "")
		{
			cout << array[i].name << " " << array[i].number << endl;
		}
	}
}


void findNumber(struct record arrayOfRecords[], int length, string name)
{
	int i = 0;
	while ((i < length - 1) && (arrayOfRecords[i].name != name))
	{
		i++;
	}
	if (arrayOfRecords[i].name == name)
	{
		cout << arrayOfRecords[i].name << " " << arrayOfRecords[i].number << endl;
	}
	else
	{
		cout << "����� '" << name << "' ��� � ���������� �����������" << endl;
	}
}

	
void findName(struct record arrayOfRecords[], int length, string number)
{
	int i = 0;
	while ((i < length - 1) && (arrayOfRecords[i].number != number))
	{
		i++;
	}
	if (arrayOfRecords[i].number == number)
	{
		cout << arrayOfRecords[i].name << " " << arrayOfRecords[i].number << endl;
	}
	else
	{
		cout << "������ '" << number << "' ��� � ���������� �����������" << endl;
	}
}


void saveInFile(struct record arrayOfRecords[], int length)
{
	ofstream fout("Phone.txt");
	for (int i = 0; i < length; i++)
	{
		fout << arrayOfRecords[i].name << " " << arrayOfRecords[i].number << endl;
	}
	fout.close();
}


void readingFromFile(struct record arrayOfRecords[], int length)
{
	ifstream fin("Phone.txt");
	for (int i = 0; i < length; i++)
	{
		fin >> arrayOfRecords[i].name >> arrayOfRecords[i].number;
	}
	fin.close();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	
	const int n = 100;
	record arrayOfRecords[n] = {};
	
	readingFromFile(arrayOfRecords, n);

	cout << "0 - �����" << endl;
	cout << "1 - �������� ������" << endl;
	cout << "2 - ����������� ��� ��������� ������" << endl;
	cout << "3 - ����� ������� �� �����" << endl;
	cout << "4 - ����� ��� �� ��������" << endl;
	cout << "5 - ��������� ������� ������ � ����" << endl;
	cout << endl;
	
	string name = {};
	string number = {};
	bool exit = false;
	
	while (!exit)
	{
		int doing;
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

