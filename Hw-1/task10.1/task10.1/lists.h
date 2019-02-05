#pragma once

struct ListElement;

struct List;

// print list
void printList(List* list);

// create new list
List *createList();

// add new head
void push(List* list, int value);

// add new element to end
void addToEnd(List* list, int value);

// delete head
void deleteHead(List *list);

// delete list
void deleteList(List *list);

// get value of listElement
int getValue(List* list, int num);

// get head of list
ListElement *getHead(List *list);

// get number of elements
int getNumberOfElementsList(List *list);

// get value of head
int getValueHead(List *list);
