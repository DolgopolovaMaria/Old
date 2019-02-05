#pragma once

struct ListElement;

/*print list*/
void print(ListElement *head);

/*add element in  sorted list*/
void insert(ListElement *&head, int elementForInsert);

/*delete element from list*/
bool deleteOfElement(ListElement *&head, int elementForDelete);

/*delete list*/
void deleteList(ListElement *&head);

/*test list functions*/
bool testList();

/*print list*/
void print(ListElement *head);

/*insert element in list*/
void insert(ListElement *&head, int elementForInsert);

/*delete element from list*/
bool deleteOfElement(ListElement *&head, int elementForDelete);

/*delete list*/
void deleteList(ListElement *&head);