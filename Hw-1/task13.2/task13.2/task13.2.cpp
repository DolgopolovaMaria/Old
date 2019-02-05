// task13.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createTable(ifstream &fin, int table[][4])
{
	int state = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fin >> state;
			table[i][j] = state;
		}
	}
}

void printComments(ifstream &file, int table[][4])
{
	int state = 0;
	char previous = '0';
	char symbol = '0';
	while (!file.eof())
	{
		file >> symbol;
		switch (symbol)
		{
			case '/':
			{
				state = table[0][state];
				break;
			}
			case '*':
			{
				state = table[1][state];
				break;
			}
			default:
			{
				state = table[2][state];
				break;
			}
		}
		
		switch (state)
		{
			case 0:
			{
				if ((symbol == '/') && (previous == '*'))
				{
					cout << '/' << endl;
				}
				break;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				if ((symbol == '*') && (previous == '/'))
				{
					cout << '/';
				}
				cout << symbol;
				break;
			}
			case 3:
			{
				cout << symbol;
			}
		}
	
		previous = symbol;
	}
}

void test()
{
	ifstream fin("table.txt");
	int table[3][4];
	createTable(fin, table);
	fin.close();

	ifstream file("test.txt");
	printComments(file, table);
	file.close();
	cout << endl;
}

int main()
{
	test();
	
	ifstream fin("table.txt");
	int table[3][4];
	createTable(fin, table);
	fin.close();
	
	ifstream file("Text.txt");
	printComments(file, table);
	file.close();
	
	return 0;
}

