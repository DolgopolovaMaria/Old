#include "stdafx.h"
#include "binary.h"
#include <iostream>

using namespace std;

void coutArray(bool array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		(array[i]) ? cout << 1 : cout << 0;
	}
	cout << endl;
}

void binaryCode(bool binaryArray[], int number)
{
	int n = 32;
	int binary = 1;
	for (int i = 0; i < sizeof(number) * 8; i++)
	{
		binaryArray[n - 1 - i] = (!((number & binary) == 0));
		binary = binary << 1;
	}
}

void sum(bool array1[], bool array2[], bool sumArray[], int length)
{
	int summa = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (summa > 1)
		{
			summa = 1;
		}
		else
		{
			summa = 0;
		}

		if (array1[i])
		{
			summa++;
		}
		if (array2[i])
		{
			summa++;
		}

		sumArray[i] = (!((summa == 0) || (summa == 2)));
	}
}

int decimal(bool array[], int length)
{
	bool neg = false;

	int res = 0;
	int powOfTwo = 1;
	
	for (int i = 0; i < length; i++)
	{
		if (array[length - 1 - i])
		{
			res = res + powOfTwo;
		}
		powOfTwo = powOfTwo * 2;
	}

	return res;

}