// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int divideNumbersOfPositive(int number1, int number2)
{
	int result = 0;
	while (result * number2 <= number1)
	{
		result++;
	}
	return result - 1;
}

int divideNumbersOfNegative(int number1, int number2)
{
	int result = 0;
	while (result * number2 >= number1)
	{
		result++;
	}
	return result;
}

int main()
{
	setlocale(0, "");
	
	int a = 0;
	int b = 0;
	int res = 0;
	cout << "������ �" << endl;
	cin >> a;
	cout << "������� b" << endl;
	cin >> b;
	
	if ((a >= 0) && (b > 0))
	{ 
		res = divideNumbersOfPositive(a, b);
	}
	else
	{
		if ((a <= 0) && (b < 0))
		{
			res = divideNumbersOfNegative(a, b);
		}
		else
		{
			if (a < 0)
			{
				a = -a;
				res = divideNumbersOfPositive(a, b);
				res = - res - 1;
			}
			else
			{
				b = -b;
				res = divideNumbersOfPositive(a, b);
				res = -res;
			}
		}
	}
	
	cout << "�������� ������� �� ������� � �� b: " << res << endl;
	
	return 0;
}

