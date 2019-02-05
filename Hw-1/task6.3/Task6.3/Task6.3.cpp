// Task6.3.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>

#include "stack.h"

using namespace std;

string change(const string &str, StackElement *&head)
{
	string newStr = "";

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
		{
			push(head, str[i]);
			break;
		}
		case ')':
		{
			while (getValue(head) != '(')
			{
				newStr += pop(head);
			}
			deleteOfHead(head);
			break;
		}

		case '+':
		case '-':
		{
			while ((getValue(head) == '+') || (getValue(head) == '-') || (getValue(head) == '/') || (getValue(head) == '*'))
			{
				newStr += pop(head);
			}
			push(head, str[i]);
			break;
		}
		case '*':
		case '/':
		{
			while ((getValue(head) == '/') || (getValue(head) == '*'))
			{
				newStr += pop(head);
			}
			push(head, str[i]);
			break;
		}
		default:
		{
			newStr += str[i];
			break;
		}
		}
	}

	while (getValue(head) != '0')
	{
		newStr += pop(head);
	}

	return newStr;

}

bool test()
{
	StackElement *head = createStack();
	
	string str1 = "3*(2+4)";
	string str2 = "2+3/1";

	string newStr1 = change(str1, head);
	string newStr2 = change(str2, head);
	
	deleteStack(head);
	
	return ((newStr1 == "324+*") && (newStr2 == "231/+"));
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
	cout << "Ââåäèòå ñòðîêó" << endl;
	cin >> str;

	cout << change(str, head) << endl;

	deleteStack(head);

	return 0;
}

