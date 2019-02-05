#include "stdafx.h"
#include <iostream>

#include "graph.h"

using namespace std;

struct Table
{
	int **array;
	int numberOfElements;
};

Table *createGraph(int number)
{
	Table *graph = new Table{ new int*[number], number };
	
	for (int i = 0; i < number; i++)
	{
		graph->array[i] = new int[number];
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			graph->array[i][j] = 0;
		}
	}
	graph->numberOfElements = number;
	
	return graph;
}

void putLength(Table *graph, int element1, int element2, int length)
{
	graph->array[element1 - 1][element2 - 1] = length;
	graph->array[element2 - 1][element1 - 1] = length;
}

void deleteGraph(Table *graph)
{
	for (int i = 0; i < graph->numberOfElements; i++)
	{
		delete[] graph->array[i];
	}
	delete graph;
}

int getLength(Table *graph, int element1, int element2)
{
	return graph->array[element1][element2];
}

int getNumberOfElements(Table *graph)
{
	return graph->numberOfElements;
}