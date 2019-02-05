#pragma once

#include <string>

struct Array;

struct Tree;

/*insert element in tree*/
void insertElement(Tree *&root, const std::string &keyForInsert, const std::string &valueForInsert);

/*search key in tree*/
Tree *searchKey(Tree *root, const std::string &keyForFind);

/*delete element from tree*/
bool deleteElement(Tree *&root, const std::string &keyForDelete);

/*get value of key*/
std::string getValue(Tree *root, const std::string &key);

/*delete tree*/
void deleteTree(Tree *&root);

void increasePrint(Tree *root);