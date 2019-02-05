#pragma once
#include <string>

struct ListElement;

/*increase number of element*/
void increaseElementNumber(ListElement *&element);

/*get number of element*/
int getNumber(ListElement *&element);

/*add element in head*/
void push(ListElement *&head, std::string &value);

/*delete list*/
void deleteList(ListElement *&head);

/*search element in list*/
bool search(ListElement *head, std::string &valueForSearch, ListElement *&searchElement);

/*print list*/
void print(ListElement *head);