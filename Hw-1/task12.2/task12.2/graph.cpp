#include "stdafx.h"
#include <iostream>
#include <fstream>

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
	graph->array[element1][element2] = length;
	graph->array[element2][element1] = length;
}

void deleteGraph(Table *graph)
{
	for (int i = 0; i < graph->numberOfElements; i++)
	{
		delete[] graph->array[i];
	}
}

void printGraph(Table *graph)
{
	for (int i = 0; i < graph->numberOfElements; i++)
	{
		for (int j = 0; j < graph->numberOfElements; j++)
		{
			cout << graph->array[i][j] << " ";
		}
		cout << endl;
	}
}

Table *readFromFile(ifstream &fin)
{
	int numberOfElement = 0;
	fin >> numberOfElement;
	Table *graph = createGraph(numberOfElement);

	for (int i = 0; i < numberOfElement; i++)
	{
		for (int j = 0; j < numberOfElement; j++)
		{
			int length = 0;
			fin >> length;
			putLength(graph, i, j, length);
		}
	}

	return graph;
}

Table *minTree(Table *graph)
{
	int elements = graph->numberOfElements;
	int visitedElements = 0;

	Table *resTree = createGraph(elements);

	bool *free = new bool[elements];
	free[0] = false;
	for (int i = 1; i < elements; i++)
	{
		free[i] = true;
	}
	visitedElements++;

	while (visitedElements < elements)
	{
		int min = INT_MAX;
		int minI = -1;
		int minJ = -1;

		for (int i = 0; i < elements; i++)
		{
			if (!free[i])
			{
				for (int j = 0; j < elements; j++)
				{
					if (free[j])
					{
						if ((graph->array[i][j] > 0) && (graph->array[i][j] < min))
						{
							min = graph->array[i][j];
							minI = i;
							minJ = j;
						}
					}
				}
			}
		}
		putLength(resTree, minI, minJ, min);
		free[minI] = false;
		free[minJ] = false;
		visitedElements++;
	}

	delete[] free;
	return resTree;
}

bool testMinTree()
{
	ifstream fin("test.txt");

	Table *graph = readFromFile(fin);
	Table *tree = minTree(graph);

	bool res = ((tree->array[0][3] == 0) && (tree->array[1][3] == 20) && (tree->array[4][2] == 30));
	deleteGraph(graph);
	deleteGraph(tree);
	fin.close();

	return res;
}
