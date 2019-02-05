#pragma once

#include <string>
#include <fstream>

struct ListElement;

/*get elment->next*/
ListElement *getNext(ListElement *element);

/*get name of element*/
std::string getName(ListElement *element);

/*get phone of element*/
std::string getPhone(ListElement *element);

/*add new head*/
void push(ListElement *&head, const std::string &name, const std::string &phone);

/*add element to end of list*/
void addToEnd(ListElement *&head, const std::string &name, const std::string &phone);

/*read list from file*/
void readFromFile(std::ifstream &fin, ListElement *&head);

/*prin list*/
void printList(ListElement *head);

/*delete list*/
void deleteList(ListElement *&head);