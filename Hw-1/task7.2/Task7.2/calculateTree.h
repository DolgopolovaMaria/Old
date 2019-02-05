#pragma once
#include <string>

struct Tree;

/*create new tree*/
Tree *createNewTree();

/*create tree of calculate*/
void buildTree(Tree *&root, std::string str);

/*print tree*/
void print(Tree *root);

/*calculate tree*/
int calc(Tree *root);

/*delete tree*/
void deleteTree(Tree *&root);


