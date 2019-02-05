#include "stdafx.h"
#include "phoneNumbers.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void addNote(Record arrayOfRecords[], int lengthOfArray)
{
	cout << "Введите имя" << endl;
	string newName;
	cin >> newName;
	cout << "Введите номер телефона" << endl;
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

void print(Record array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i].name != "")
		{
			cout << array[i].name << " " << array[i].number << endl;
		}
	}
}

void findNumber(Record arrayOfRecords[], int length, string name)
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
		cout << "Имени '" << name << "' нет в телефонном справочнике" << endl;
	}
}

void findName(Record arrayOfRecords[], int length, string number)
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
		cout << "Номера '" << number << "' нет в телефонном справочнике" << endl;
	}
}

void saveInFile(Record arrayOfRecords[], int length)
{
	ofstream fout("phoneNumbers.txt");
	for (int i = 0; i < length; i++)
	{
		fout << arrayOfRecords[i].name << " " << arrayOfRecords[i].number << endl;
	}
	fout.close();
}

void readingFromFile(Record arrayOfRecords[], int length)
{
	ifstream fin("phoneNumbers.txt");
	for (int i = 0; i < length; i++)
	{
		fin >> arrayOfRecords[i].name >> arrayOfRecords[i].number;
	}
	fin.close();
} 
