// Task2.2.2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int raiseToThePower1(int number, int power)
{
	if (number == 0)
	{
		return 0;
	}
	else
	{
		int result = 1;
		for (int i = 1; i <= power; i++)
		{
			result = result * number;
		}
		return result;
	}
}


int raiseToThePower2(int number, int power)
{
	if (power == 0)
	{
		return 1;
	}
	else if (power % 2 == 1)
	{
		return raiseToThePower2(number, power - 1) * number;
	}  
		else
	{
		int pow =  raiseToThePower2(number, power / 2);
		return pow * pow;
	}
}

int main()
{
	setlocale(0, "");
	
	cout << "1) ������� �����" << endl;
	int num1 = 0;
	cin >> num1;
	
	cout << "������� �������" << endl;
	int pow1 = 0;
	cin >> pow1;
	
	cout << "���������: " << raiseToThePower1(num1, pow1) << endl;
	
	cout << "2) ������� �����" << endl;
	int num2 = 0;
	cin >> num2;

	cout << "������� �������" << endl;
	int pow2 = 0;
	cin >> pow2;

	cout << "���������: " << raiseToThePower2(num2, pow2) << endl;
	
	return 0;
}

