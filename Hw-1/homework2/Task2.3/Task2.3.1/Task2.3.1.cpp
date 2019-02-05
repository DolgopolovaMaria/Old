// Task2.3.1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void bubbleSort(int mainArray[], int lengthOfMainArray)
{	
	for (int i = 0; i < lengthOfMainArray - 1; i++)
	{
		for (int j = 0; j < lengthOfMainArray - i - 1; j++)
		{
			if (mainArray[j] < mainArray[j + 1])
			{
				std::swap(mainArray[j], mainArray[j + 1]);
			}
		}
	}
}

void countingSort(int mainArray[], int lengthOfMainArray)
{
	const int max = 21;
	int additionalArray[max] = {};
	int lengthOfAdditionalArray = max;
	
	for (int i = 0; i < lengthOfAdditionalArray; i++)
	{
		additionalArray[i] = 0;
	}
	
	for (int i = 0; i < lengthOfMainArray; i++)
	{
		additionalArray[mainArray[i]]++;
	}
	
	int numberOfElement = 0;
	for (int i = 0; i < lengthOfAdditionalArray; i++)
	{
		for (int j = 1; j <= additionalArray[i]; j++)
		{
			mainArray[numberOfElement] = i;
			numberOfElement++;
		}
	}
}

int main()
{
	setlocale(0, "");
	const int max = 21;
	const int lengthOfArray = 7;
	cout << "¬ведите " << lengthOfArray << " значений (в интервале от 0 до " << max - 1 << ") элементов массива дл€ сортировки" << endl;
	
	int arrayForSort[lengthOfArray] = {};
	for (int i = 0; i < lengthOfArray; i++)
	{
		cin >> arrayForSort[i];
	}
	
	countingSort(arrayForSort, lengthOfArray);
	
	for (int i = 0; i < lengthOfArray; i++)
			cout << arrayForSort[i] << " ";
	cout << endl;
	
	bubbleSort(arrayForSort, lengthOfArray);

	for (int i = 0; i < lengthOfArray; i++)
		cout << arrayForSort[i] << " ";
	
	return 0;
}

