// task13.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool lexicalAnalyzer(string str)
{
	char symbol = '-1';
	int state = 0;
	for (int i = 0; i < str.length(); i++)
	{
		symbol = str[i];
		switch (state)
		{
			case 0:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 1;
				}
				else
				{
					return false;
				}
				break;
			}
			case 1:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 1;
				}
				else if (symbol == '.')
				{
					state = 2;
				}
				else if (symbol == 'E')
				{
					state = 4;
				}
				else
				{
					return false;
				}
				break;
			}
			case 2:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 3;
				}
				else
				{
					return false;
				}
				break;
			}
			case 3:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 3;
				}
				else if (symbol == 'E')
				{
					state = 4;
				}
				else
				{
					return false;
				}
				break;
			}
			case 4:
			{
				if ((symbol == '+') || (symbol == '-'))
				{
					state = 5;
				}
				else if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 6;
				}
				else
				{
					return false;
				}
				break;
			}
			case 5:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 6;
				}
				else
				{
					return false;
				}
				break;
			}
			case 6:
			{
				if ((symbol >= '0') && (symbol <= '9'))
				{
					state = 6;
				}
				else
				{
					return false;
				}
				break;
			}
		}
	}
	return true;
}

bool test()
{
	string str1 = "12";
	string str2 = "12.3";
	string str3 = "12.3E-55";
	string str4 = "12E.2";
	return ((lexicalAnalyzer(str1)) && (lexicalAnalyzer(str2)) && (lexicalAnalyzer(str3)) && (!lexicalAnalyzer(str4)));
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	string str;
	cout << "enter a number" << endl;
	cin >> str;
	if (lexicalAnalyzer(str))
	{
		cout << "it is a real number" << endl;
	}
	else
	{
		cout << "it is not a real number" << endl;
	}
	return 0;
}

