// task6.4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

#include "listPhone.h"
#include "mergesort.h"

using namespace std;

bool test()
{
	ListElement *head = nullptr;

	ifstream fin("test.txt");
	readFromFile(fin, head);

	bool sortNumber = true;

	mergeSort(head, sortNumber);
	
	bool ok = true;

	ListElement *position = head;
	while (getNext(position) != nullptr)
	{
		if (getPhone(getNext(position)) < getPhone(position))
		{
			return false;
		}
		position = getNext(position);
	}

	fin.close();
	deleteList(head);

	return ok;
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	ListElement *head = nullptr;
	
	ifstream fin("Phone.txt");
	readFromFile(fin, head);
	
	bool sortNumber = false;
	cout << "for sort by name press 0, for sort by number press 1" << endl;
	cin >> sortNumber;

	mergeSort(head, sortNumber);
	printList(head);
	
	fin.close();
	deleteList(head);
	
	return 0;
}

