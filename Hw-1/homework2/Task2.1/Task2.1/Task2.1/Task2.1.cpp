// Task2.1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int fibonacci(int number)
{
	int r1 = 1;
	int r2 = 1;
	int r3 = 2;
	for (int i = 4; i <= number; i++)
	{
		r1 = r2;
		r2 = r3;
		r3 = r1 + r2;
	}
	return r3;
}
int main()
{
	setlocale(0, "");
	int n = 0;
	cout << "¬ведите n" << endl;
	cin >> n;
	if (n == 1 || n == 2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << fibonacci(n) << endl;
	}
	return 0;
}

