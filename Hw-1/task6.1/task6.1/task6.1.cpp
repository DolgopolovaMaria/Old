// task6.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

double calculator(double value1, double value2, char operation)
{
	switch (operation)
	{
		case '+':
		{
			return value1 + value2;
		}
		case '-':
		{
			return value1 - value2;
		}
		case '*':
		{
			return value1 * value2;
		}
		case '/':
		{
			return value1 / value2;
		}
	}
}

void calc(char symbol, StackElement *&head)
{
	if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'))
	{
		double value1 = getElement(head);
		double value2 = getElement(head);

		double res = calculator(value2, value1, symbol);

		pop(head, res);
	}
	else
	{
		double value = symbol - '0';
		pop(head, value);
	}
}

bool test()
{
	string str = "96-12+*";
	StackElement *head = createStack();
	for (int i = 0; i < str.length(); i++)
	{
		calc(str[i], head);
	}
	
	return (getElement(head) == 9);
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	setlocale(LC_ALL, "Russian");
	
	StackElement *head = createStack();

	cout << "Введите выражение в постфиксной форме. Символ конца ввода - '_'" << endl;
	
	char symbol = '0';
	cin >> symbol;
	while (symbol != '_')
	{
		calc(symbol, head);
		cin >> symbol;
	}
	
	cout << getElement(head) << endl;
	
	deleteStack(head);
	
	return 0;
}

