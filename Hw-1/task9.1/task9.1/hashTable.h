#pragma once

#include <string>
#include "list.h"

const int sizeOfHashTable = 20;

struct HashTable;

/*create hash table*/
HashTable *createHashTable();

/*get head of table*/
ListElement *getHead(HashTable *table, std::string str);

/*delete table*/
void deleteHashTable(HashTable *hashTable);

/*add world*/
void addWord(HashTable *hashTable, std::string &word);

/*get max length*/
int maxLength(HashTable *hashTable);

/*get min length*/
double mediumLength(HashTable *hashTable);

/*print table*/
void printTable(HashTable *hashTable);