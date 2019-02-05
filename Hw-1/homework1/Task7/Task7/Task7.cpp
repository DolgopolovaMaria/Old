// Task7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int n, j;
bool prost(int k)
{
	int i = 2;
	while ((i < k / 2) && (k%i>0))
	{
		i++;
	}
	if (k%i == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cin >> n;
	for (j = 2; j <= n; j++)
	{
		if (prost(j)==true)
		{
			cout << j<< endl;
		}
	}
	return 0;
}

