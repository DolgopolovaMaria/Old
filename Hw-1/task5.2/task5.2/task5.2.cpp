// task5.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "list.h"

using namespace std;

bool test()
{
	int m1 = 4;
	int n1 = 13;
	listElement *last1 = creationOfList(n1);
	int k1 = deleteElement(last1, m1);

	int m2 = 7;
	int n2 = 3;
	listElement *last2 = creationOfList(n2);
	int k2 = deleteElement(last2, m2);

	int m3 = 5;
	int n3 = 5;
	listElement *last3 = creationOfList(n3);
	int k3 = deleteElement(last3, m3);

	return ((k1 == 5) && (k2 == 3) && (k3 == 2));
}


int main()
{
	if (!test())
	{
		cout << "error!";
		return 0;
	}

	setlocale(LC_ALL, "Russian");

	cout << "введите n" << endl;
	int n = 0;
	cin >> n;

	cout << "введите m" << endl;
	int m = 0;
	cin >> m;

	listElement *last = creationOfList(n);
	cout << "k = " << deleteElement(last, m) << endl;

	delete last;
	
	return 0;
}
