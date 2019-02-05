 task12.1.cpp: определяет точку входа для консольного приложения.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "stringInFile.h"

using namespace std;

 bool test()
 {
	ifstream fin("test.txt");
	
	string str = "for";
	int res = boyermooreFind(fin, str);
	 
	fin.close();
	return (res == 4);

 }
 
 int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	cout << "enter the string" << endl;
	string str;
	cin >> str;
	
	ifstream fin("text.txt");

	int res = boyermooreFind(fin, str);
	if (res == -1)
	{
		cout << "the line is not contained in the file" << endl;
	}
	else
	{
		cout << "the position of the first occurrence of the entered lines in the file: " << res << endl;
	}

	fin.close();
	return 0;
}

