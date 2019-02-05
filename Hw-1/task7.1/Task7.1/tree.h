#pragma once

struct Tree;

/*добавление значения в двоичное дерево */
void insert(Tree *&root, int valueForInsert);

/*поиск элемента в двоичном дереве*/
bool search(Tree *root, int valueForFind);

/*удаление элемента*/
bool deleteElement(Tree *&root, int valueForDelete);

/*печать элементов в возрастающем порядке*/
void increasePrint(Tree *root);

/*печать элементов в убывающем порядке*/
void decreasePrint(Tree *root);

/*удаление дерева*/
void deleteTree(Tree *&root);

