// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const int n = 5;
	int A[n];
	int i,res = 0;
	for (i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < n; i++)
	{
		if (A[i] == 0)
		{
			res++;
		}
	}
	cout << res;
	return 0;
}

