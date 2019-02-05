#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "stringInFile.h"

using namespace std;

string newString(int pos, int lengthOfStr, string str)
{
	string newStr = "";

	for (int i = pos; i < lengthOfStr + pos; i++)
	{
		newStr = newStr + str[i];
	}
	return newStr;
}

void makeArrayOfSymbols(string str, int *arrayOfSymbols)
{
	for (int i = 0; i < 255; i++)
	{
		arrayOfSymbols[i] = 0;
	}
	for (int i = 0; i < str.length(); i++)
	{
		arrayOfSymbols[str[i]] = i + 1;
	}
}

void makeArrayOfSuffix(string str, int *&arrayOfSuffix)
{
	arrayOfSuffix[str.length()] = str.length();

	for (int i = 1; i < str.length(); i++)
	{
		string suffix = newString(i, str.length() - i, str);
		int j = i - 1;
		while ((j >= 0) && (newString(j, suffix.length(), str) != suffix))
		{
			j--;
		}
		if (j == -1)
		{
			arrayOfSuffix[suffix.length()] = str.length();
		}
		else
		{
			arrayOfSuffix[suffix.length()] = i - j;
		}
	}
}

int shift(string str, string workStr, int *&arrayOfSuffix, int *arrayOfSymbols)
{
	int i = str.length() - 1;
	if (str[i] != workStr[i])
	{
		return str.length() - arrayOfSymbols[workStr[i]];
	}
	i--;
	while ((i >= 0) && (str[i] == workStr[i]))
	{
		i--;
	}

	if (i == -1)
	{
		return 0;
	}
	return arrayOfSuffix[str.length() - i-1];
}

bool readStringFromFile(ifstream &fin, int lengthStr, string &str)
{
	int i = 0;
	string newStr = "";
	while ((i < lengthStr) && (!fin.eof()))
	{
		i++;
		char ch = '0';
		fin >> ch;
		newStr = newStr + ch;
	}
	str = newStr;
	return newStr.length() == lengthStr;
}

int boyermooreFind(ifstream &fin, const string &str)
{
	const int n = 255;
	int arrayOfSymbols[n];
	makeArrayOfSymbols(str, arrayOfSymbols);
	
	int *arrayOfSuffix = new int[str.length()];
	makeArrayOfSuffix(str, arrayOfSuffix);
	
	int position = 0;
	bool found = false;

	while ((!fin.eof()) && (!found))
	{
		string workStr;
		if (!readStringFromFile(fin, str.length(), workStr))
		{
			return -1;
		}
		int posShift = shift(str, workStr, arrayOfSuffix, arrayOfSymbols);
		if (posShift == 0)
		{
			found;
			return position;
		}
		else
		{
			position = position + posShift;
			int k = posShift - str.length();
			fin.seekg(k, ios::cur);
		}
	}
	return -1;
}
