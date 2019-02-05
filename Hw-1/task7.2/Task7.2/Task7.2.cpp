
// Task7.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "calculateTree.h"

using namespace std;

bool test()
{
	Tree *root = createNewTree();

	string str = "(*(- 5 3) (+ 6 2))";
	buildTree(root, str);
	bool ok = (calc(root) == 16);

	deleteTree(root);
	
	return ok;
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	FILE *fin = fopen("Text.txt", "r");

	Tree *root = createNewTree();

	string str;
	char symbol = fgetc(fin);
	while (!feof(fin))
	{
		str = str + symbol;
		symbol = fgetc(fin);
	}
	
	buildTree(root, str);

	print(root);
	cout << endl;
	cout << "result: " << calc(root) << endl;

	deleteTree(root);
	fclose(fin);

	return 0;
}