#pragma once

#include "lists.h"
#include "graph.h"
#include <fstream>

struct ArrayOfLists;

// create new array of lists
ArrayOfLists *createArrayOfLists(int capitalsNumber);

// add capital to array
void addCapital(ArrayOfLists *arrayOfLists, int capital);

// delete array of lists
void deleteArrayOfLists(ArrayOfLists *&arrayOfLists);

// print array of lists
void printArrayOfLists(ArrayOfLists *arrayOfLists);

// create new countries
void createCountries(ArrayOfLists *countries, Table *graph);

// read countries from file
void readFromFile(std::ifstream &fin, Table *&graph, ArrayOfLists *&countries);

// test countries functions
bool testCountries();