// Task6.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int string1InString2(string str1, string str2)
{
	int length1, length2;
	length1 = str1.length();
	length2 = str2.length();
	int number = 0;
	for (int i = 0; i < length2; i++)
	{
		if (str2[i] == str1[0])
		{
			int j = 0;
			while ((str2[i + j] == str1[j]) && (j<length1) && (j+i<length2))
			{
				j++;
			}
			if (j == length1)
			{
				number++;
			}

		}
	}
	return number;
}
int main()
{
	setlocale(0, "");
	string s, s1;
	cout << "¬ведите S" << endl;
	getline(cin,s);
	cout << "¬ведите S1" << endl;
	getline(cin,s1);
	int res = string1InString2(s1, s);
	cout << res << endl;
	return 0;
}

