// Task3.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void insertionSort(int array[], int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		int j = i;
		while (j > 0 && array[j] <= array[j - 1])
		{
			swap(array[j], array[j - 1]);
			j--;
		}
	}
}

int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(array[i], array[j]);
			i++;
		}
	}
	swap(array[i], array[high]);
	return i;
}

void qsort(int array[], int low, int high)
{
	if (high - low + 1 < 10)
	{
		insertionSort(array, low, high);
	}
	else
	{
		if (low < high)
		{
			int p = partition(array, low, high);
			qsort(array, low, p - 1);
			qsort(array, p + 1, high);
		}
	}
}

int main()
{
	srand(time(0));
	
	const int n = 40;
	int arrayForSort[n] = {};
	for (int i = 0; i < n; i++)
	{
		arrayForSort[i] = rand() % 50;
	}
	
	qsort(arrayForSort, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arrayForSort[i] << " ";
	}
	cout << endl;
	
	return 0;
}

