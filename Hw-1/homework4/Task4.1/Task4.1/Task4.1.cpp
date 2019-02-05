// Task4.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "binary.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	const int n = 32;
	bool array1[n] = {};
	bool array2[n] = {};
	
	int number1 = 0;
	cout << "Введите число в десятичной системе счисления" << endl;
	cin >> number1;
	cout << "Представление числа " << number1 << " в двоичной системе счисления: ";
	binaryCode(array1, number1);
	coutArray(array1, n);
	
	int number2 = 0;
	cout << "Введите число в десятичной системе счисления" << endl;
	cin >> number2;
	cout << "Представление числа " << number2 << " в двоичной системе счисления: ";
	binaryCode(array2, number2);
	coutArray(array2, n);
	
	bool sumArray[n] = {};
	sum(array1, array2, sumArray, n);
	cout << "Сумма чисел в двоичной системе счисления: ";
	coutArray(sumArray, n);
	
	cout << "Сумма чисел в десятичной системе счисления: " << decimal(sumArray, n) << endl;
	
	return 0;
}

