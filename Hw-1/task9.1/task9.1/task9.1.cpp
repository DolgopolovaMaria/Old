// task9.1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include "hashTable.h"
#include <stdio.h>
#include <string>
#include "list.h"

using namespace std;

bool test()
{
	HashTable *hashTable = createHashTable();
	string str1 = "text";
	string str2 = "table";
	for (int i = 1; i < 4; i++)
	{
		addWord(hashTable, str1);
	}
	addWord(hashTable, str2);
	
	ListElement *element1 = nullptr;
	ListElement *element2 = nullptr;
	search(getHead(hashTable, str1), str1, element1);
	search(getHead(hashTable, str2), str2, element2);

	bool ok = (getNumber(element1) == 3) && (getNumber(element2) == 1);
	deleteHashTable(hashTable);
	
	return ok;
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	setlocale(LC_ALL, "Russian");

	HashTable *hashTable = createHashTable();
	
	FILE *fin = fopen("text.txt", "r");
	
	double numberOfWords = 0;
	string str = "";
	
	char symbol = fgetc(fin);
	while (!feof(fin))
	{
		if (symbol == ' ')
		{
			if (str.length() > 0)
			{
				addWord(hashTable, str);
				numberOfWords++;
				str = "";
			}
		}
		else
		{
			str = str + symbol;
		}
	
		symbol = fgetc(fin);
	}
	if (str.length() > 0)
	{
		addWord(hashTable, str);
		numberOfWords++;
		str = "";
	}
	
	printTable(hashTable);
	cout << endl;

	cout << "коэффициент заполнени€ хеш-таблицы: " << (numberOfWords / sizeOfHashTable) << endl;
	cout << "максимальна€ длина списка в сегменте таблицы: " << maxLength(hashTable) << endl;
	cout << "средн€€ длина списка в сегменте таблицы: " << mediumLength(hashTable) << endl;

	fclose(fin);
	deleteHashTable(hashTable);
	
	return 0;
}

