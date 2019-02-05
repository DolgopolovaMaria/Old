// Task4.1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� ����� � ���������� ������� ���������" << endl;
	cin >> number1;
	cout << "������������� ����� " << number1 << " � �������� ������� ���������: ";
	binaryCode(array1, number1);
	coutArray(array1, n);
	
	int number2 = 0;
	cout << "������� ����� � ���������� ������� ���������" << endl;
	cin >> number2;
	cout << "������������� ����� " << number2 << " � �������� ������� ���������: ";
	binaryCode(array2, number2);
	coutArray(array2, n);
	
	bool sumArray[n] = {};
	sum(array1, array2, sumArray, n);
	cout << "����� ����� � �������� ������� ���������: ";
	coutArray(sumArray, n);
	
	cout << "����� ����� � ���������� ������� ���������: " << decimal(sumArray, n) << endl;
	
	return 0;
}

