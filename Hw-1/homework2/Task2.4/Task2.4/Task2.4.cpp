// Task2.4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sort(int array[], int lengthOfArray)
{
	int i = 1;
	int j = lengthOfArray - 1;
	while (i < j)
	{
		while ((array[i] < array[0]) && (i < lengthOfArray - 1))
		{
			i++;
		}
		while ((array[j] >= array[0]) && (j > 1))
		{
			j--;
		}
		if (i < j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
}
 
int main()
{
	const int n = 20;
	int arrayOfRandom[n];
	
	srand(time(0));
	
	for (int i = 0; i < n; i++)
	{
		arrayOfRandom[i] = rand() % 10;
	}
	
	sort(arrayOfRandom, n);

	for (int i = 0; i < n; i++)
	{
		cout << arrayOfRandom[i] << " ";
	}
	return 0;
}

