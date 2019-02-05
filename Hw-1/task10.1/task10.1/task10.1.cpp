// task10.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include "graph.h"
#include "country.h"

using namespace std;

int main()
{
	if (!testCountries())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	ifstream fin("text.txt");

	Table *graph = nullptr;
	ArrayOfLists *countries = nullptr;
	
	readFromFile(fin, graph, countries);
	createCountries(countries, graph);
	printArrayOfLists(countries);
	
	deleteArrayOfLists(countries);
	deleteGraph(graph);
	fin.close();
	
	return 0;
}

