// task6.2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool balance(string str, StackElement *&head)
{
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
		{
			pop(head, '(');
			break;
		}
		case '{':
		{
			pop(head, '{');
			break;
		}
		case '[':
		{
			pop(head, '[');
			break;
		}
		case ')':
		{
			if (getElement(head) != '(')
			{
				return false;
			}
			break;
		}
		case '}':
		{
			if (getElement(head) != '{')
			{
				return false;
			}
			break;
		}
		case ']':
		{
			if (getElement(head) != '[')
			{
				return false;
			}
			break;
		}
		}
	}

	return (getElement(head) == '0');
}

bool test()
{
	StackElement *head = createStack();
	
	string str1 = "({[]})";
	string str2 = "((())";
	string str3 = "({)}";
	string str4 = ")(";

	return ((balance(str1, head)) && (!balance(str2, head)) && (!balance(str3, head)) && (!balance(str4, head)));
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	StackElement *head = createStack();
	
	setlocale(LC_ALL, "Russian");
	
	string str;
	cout << "������� ������" << endl;
	cin >> str;

	if (balance(str, head))
	{
		cout << "������ ������ � ������ �� �������" << endl;
	}
	else
	{
		cout << "������ ������ � ������ �������" << endl;
	}
	
	deletestack(head);
	
	return 0;
}

