// task12.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include "graph.h"

using namespace std;

int main()
{
	if (!testMinTree())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	ifstream fin("text.txt");
	
	Table *graph = readFromFile(fin);
	Table *tree = minTree(graph);
	printGraph(tree);
	
	deleteGraph(graph);
	deleteGraph(tree);
	fin.close();
	
	return 0;
}

