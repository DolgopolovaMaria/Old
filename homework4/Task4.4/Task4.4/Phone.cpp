#include <iostream>
#include "Phone.h"
#include <string>
#include <cstring>

/*struct record
{
	string number = {};
	string name = {};
};*/


void addNote(struct record arrayOfRecords[], int lengthOfArray)
{
	cout << "Введите имя" << endl;
	string newName;
	cin >> newName;
	cout << "Введите номер телефона" << endl;
	string newNumber;
	cin >> newNumber;

	int i = 0;
	while (/*(stricmp(arrayOfRecord[i].name, newName) < 0)*/ (newName < arrayOfRecords[i].name) && (i < lengthOfArray))
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