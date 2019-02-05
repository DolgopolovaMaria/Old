#include "stdafx.h"
#include "hashTable.h"
#include "list.h"
#include <string>
#include <iostream>

using namespace std;

struct HashTable
{
	ListElement *head[sizeOfHashTable];
	int number[sizeOfHashTable];
};

HashTable *createHashTable()
{
	HashTable *hashTable = new HashTable;
	
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		hashTable->head[i] = nullptr;
		hashTable->number[i] = 0;
	}
	
	return hashTable;
}

void deleteHashTable(HashTable *hashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		deleteList(hashTable->head[i]);
	}
	
	delete hashTable;
	hashTable = nullptr;
}

int createHash(std::string &key)
{
	int result = ((int)key[0] + (int)key[1] + (int)key[2]) % sizeOfHashTable;
	return result;
}

void add(HashTable *hashTable, std::string &value)
{
	int hash = createHash(value);
	push(hashTable->head[hash], value);
	hashTable->number[hash] = 1;
}

void addWord(HashTable *hashTable, std::string &word)
{
	ListElement *element = nullptr;
	int key = createHash(word);
	
	if (search(hashTable->head[key], word, element))
	{
		increaseElementNumber(element);
	}
	else
	{
		push(hashTable->head[key], word);
		hashTable->number[key]++;
	}
}

int maxLength(HashTable *hashTable)
{
	int max = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable->number[i] > max)
		{
			max = hashTable->number[i];
		}
	}

	return max;
}

double mediumLength(HashTable *hashTable)
{
	double length = 0;
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		length = length + hashTable->number[i];
	}
	
	return length / sizeOfHashTable;
}

void printTable(HashTable *hashTable)
{
	for (int i = 0; i < sizeOfHashTable; i++)
	{
		if (hashTable->head[i] != nullptr)
		{
			print(hashTable->head[i]);
		}
	}
}

ListElement *getHead(HashTable *table, string str)
{
	return table->head[createHash(str)];
}