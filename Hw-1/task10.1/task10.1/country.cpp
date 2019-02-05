#include "stdafx.h"
#include <iostream>
#include <fstream>

#include "graph.h"
#include "lists.h"
#include "country.h"

using namespace std;

struct ArrayOfLists
{
	int numberOfCapitals;
	List *array[100];
};

ArrayOfLists *createArrayOfLists(int capitalsNumber)
{
	ArrayOfLists *arrayOfLists = new ArrayOfLists;
	for (int i = 0; i < capitalsNumber; i++)
	{
		arrayOfLists->array[i] = createList();
	}
	arrayOfLists->numberOfCapitals = capitalsNumber;
	
	return arrayOfLists;
}

void addCapital(ArrayOfLists *arrayOfLists, int capital)
{
	int i = 0;
	while (getHead(arrayOfLists->array[i]) != nullptr)
	{
		i++;
	}
	
	push(arrayOfLists->array[i], capital);
}

void deleteArrayOfLists(ArrayOfLists *&arrayOfLists)
{
	for (int i = 0; i < arrayOfLists->numberOfCapitals; i++)
	{
		deleteList(arrayOfLists->array[i]);
	}
	delete arrayOfLists;
}

void printArrayOfLists(ArrayOfLists* arrayOfLists)
{
	for (int i = 0; i < arrayOfLists->numberOfCapitals; i++)
	{
		cout << "Country " << i << ": " << endl;
		printList(arrayOfLists->array[i]);
	}
}

void addCitiesToCountries(ArrayOfLists *countries, Table *graph, int numberOfCities, int &numberOfFreeCities, int &capitalForExam, bool *&freeCities)
{
	int shortestRoad = INT_MAX;
	int cityToAdd = -1;

	for (int cityForExam = 1; cityForExam <= numberOfCities; cityForExam++)
	{
		if (freeCities[cityForExam - 1])
		{
			for (int l = 0; l < getNumberOfElementsList(countries->array[capitalForExam]); l++)
			{
				int city = getValue(countries->array[capitalForExam], l); 
				int road = getLength(graph, cityForExam - 1, city - 1);  
				if ((road < shortestRoad) && (road != 0))
				{
					shortestRoad = road;
					cityToAdd = cityForExam;
				}
			}
		}
	}
	
	if (cityToAdd != -1)
	{
		freeCities[cityToAdd - 1] = false;
		numberOfFreeCities--;
		addToEnd(countries->array[capitalForExam], cityToAdd);
	}
	capitalForExam++;
	if (capitalForExam == countries->numberOfCapitals)
	{
		capitalForExam = 0;
	}
}

void createCountries(ArrayOfLists *countries, Table *graph)
{
	int numberOfCities = getNumberOfElements(graph);
	int numberOfFreeCities = numberOfCities - (countries->numberOfCapitals);
	
	bool *freeCities = new bool[numberOfCities];
	for (int i = 0; i < numberOfCities; i++)
	{
		freeCities[i] = true;
	}
	for (int i = 0; i < countries->numberOfCapitals; i++)
	{
		freeCities[getValueHead(countries->array[i]) - 1] = false;
	}
	
	int capitalForExam = 0; 
	while (numberOfFreeCities > 0)
	{
		addCitiesToCountries(countries, graph, numberOfCities, numberOfFreeCities, capitalForExam, freeCities);
	}
	
	delete[] freeCities;
}

void readFromFile(ifstream &fin, Table *&graph, ArrayOfLists *&countries)
{
	int	citiesNumber = 0;
	fin >> citiesNumber;
	graph = createGraph(citiesNumber);

	int roadsNumber = 0;
	fin >> roadsNumber;

	for (int i = 0; i < roadsNumber; i++)
	{
		int element1 = 0;
		int element2 = 0;
		int roadLength = 0;
		fin >> element1;
		fin >> element2;
		fin >> roadLength;
		putLength(graph, element1, element2, roadLength);
	}

	int capitalsNumber = 0;
	fin >> capitalsNumber;
	countries = createArrayOfLists(capitalsNumber);
	for (int i = 0; i < capitalsNumber; i++)
	{
		int capital = 0;
		fin >> capital;
		addCapital(countries, capital);
	}
}

bool testCountries()
{
	ifstream fin("test.txt");

	Table *graph = nullptr;
	ArrayOfLists *countries = nullptr;

	readFromFile(fin, graph, countries);
	createCountries(countries, graph);
	
	bool ok = ((getValueHead(countries->array[0]) == 1) && (getValue(countries->array[0], 1) == 2)
		&& (getValue(countries->array[0], 2) == 3) && (getValueHead(countries->array[1]) == 5)
		&& (getValue(countries->array[1], 1) == 6) && (getValue(countries->array[1], 2) == 4));

	deleteArrayOfLists(countries);
	deleteGraph(graph);
	fin.close();

	return ok;
}