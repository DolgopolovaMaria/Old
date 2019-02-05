// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
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
	cout << "Ведите а" << endl;
	cin >> a;
	cout << "Введите b" << endl;
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
	
	cout << "Неполное частное от деления а на b: " << res << endl;
	
	return 0;
}

