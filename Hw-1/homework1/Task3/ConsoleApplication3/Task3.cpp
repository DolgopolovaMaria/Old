// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int n = 5, m = 3;
int A[m + n];
int i;
void change(int *massiv, int first, int last)
{
	int j, k;
	for (j = first; j <= ((last - first)/2 + first); j++)
	{
		k = massiv[j];
		massiv[j] = massiv[last+first-j ];
		massiv[last+first-j ] = k;
	};
}
int main()
{
	for (i = 0; i < m + n; i++)
	{
		cin >> A[i];
	}
	change(A, 0, n - 1);
	change(A, n, m + n - 1);
	change(A, 0, m + n - 1);
	for (i = 0; i < m + n; i++)
	{
		cout << A[i];
	}
	return 0;
}

