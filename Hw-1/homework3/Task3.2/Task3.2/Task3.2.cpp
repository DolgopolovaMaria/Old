// Task3.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int findPivot(int array[], int left, int right)
{
	int i = left;
	while (array[i + 1] == array[i] && i < right - 1)
	{
		i++;
	}
	if (array[i + 1] > array[i])
	{
		return i + 1;
	}
	else
	{
		return i;
	}
}

void partition(int array[], int &left, int &right, int pivot)
{
	int i = left;
	int j = right;
	int p = array[pivot];
	while (i < j)
	{
		while ((array[i] < p) && (i < right))
		{
			i++;
		}
		while ((array[j] >= p) && (j > left))
		{
			j--;
		}
		if (i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}
	left = i;
	right = j;
}

void qsort(int array[], int left, int right)
{
	int pivot = findPivot(array, left, right);
	int newLeft = left;
	int newRight = right;

	partition(array, newLeft, newRight, pivot);

	if (left < newRight)
	{
		qsort(array, left, newRight);
	}
	if (newLeft < right)
	{
		qsort(array, newLeft, right);
	}
}

bool search(int array[], int lengthOfArray, int searchValue)
{
	bool res = false;
	int left = 0;
	int right = lengthOfArray - 1;
	int middle = (right - left + 1) / 2;
	while ((left <= right) && (!res))
	{
		if (array[middle] == searchValue)
		{
			res;
		}
		else if (searchValue < array[middle])
		{
			right = middle - 1;
			middle = left + (right - left + 1) / 2;
		}
		else
		{
			left = middle + 1;
			middle = left + (right - left + 1) / 2;
		}
	}
	return res;
}

bool testQsort(int array[], int length)
{
	qsort(array, 0, length - 1);
	bool res = true;
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i + 1] < array[i])
		{
			!res;
		}
	}
	return res;
}

bool testSearch()
{
	const int n = 10;
	int array[n] = { 0, 8, 11, 3, 9, 100, 56, 4, 8, 2 };
	return (search(array, n, 0) && search(array, n, 2) && search(array, n, 9) && !search(array, n, 50));
}

bool tests()
{
	const int n = 10;
	int array1[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int array2[n] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int array3[n] = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
	int array4[n] = { 2, 6, 1, 9, 8, 0, 1, 2, 3, 100 };
	return testSearch && testQsort(array1, n) && testQsort(array2, n) && testQsort(array3, n) && testQsort(array4, n);
}

int main()
{
	setlocale(0, "");
	
	if (!tests())
	{
		cout << "error" << endl;
	}
	else
	{
		cout << "ok" << endl;

		int n = 0;
		cout << "введите n " << endl;
		cin >> n;

		int *array = new int[n];

		srand(time(nullptr));
		for (int i = 0; i < n; i++)
		{
			array[i] = rand() % 1000000000;
		}

		for (int i = 0; i < n; i++)
		{
			cout << array[i] << ' ';
		}
		cout << endl;

		qsort(array, 0, n - 1);

		int k = 0;
		cout << "введите k " << endl;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			int value = rand() % 1000000000;
			if (search(array, n, value))
			{
				cout << value << " содержится в массиве" << endl;
			}
			else
			{
				cout << value << "  не содержится в массиве" << endl;
			}
		}
		delete[] array;
	}
	return 0;
}

