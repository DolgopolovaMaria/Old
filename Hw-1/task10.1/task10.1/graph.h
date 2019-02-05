#pragma once

struct Table;

// create new graph
Table *createGraph(int number);

// put length in graph
void putLength(Table *graph, int element1, int element2, int length);

// delete graph
void deleteGraph(Table *graph);

// get length from graph
int getLength(Table *graph, int element1, int element2);

// get number of element from graph
int getNumberOfElements(Table *graph);