#pragma once
#include <fstream>

struct Table;

// create new graph
Table *createGraph(int number);

// put length in graph
void putLength(Table *graph, int element1, int element2, int length);

// delete graph
void deleteGraph(Table *graph);

// print graph
void printGraph(Table *graph);

// read graph from file
Table *readFromFile(std::ifstream &fin);

// create min tree
Table *minTree(Table *graph);

// test function "minTree"
bool testMinTree();