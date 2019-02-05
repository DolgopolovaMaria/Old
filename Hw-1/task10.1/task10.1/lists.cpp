#include "stdafx.h"
#include <iostream>

#include "lists.h"

using namespace std;

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	int numberOfElements;
	ListElement* head;
};

void printList(List *list)
{
	ListElement* position = list->head;

	while (position != nullptr)
	{
		cout << position->value << " ";
		position = position->next;
	}
	cout << endl;
}

List *createList()
{
	List *newList = new List;
	newList->numberOfElements = 0;
	newList->head = nullptr;
	
	return newList;
}

void push(List *list, int value)
{
	ListElement* newHead = new ListElement{ value, list->head };
	list->head = newHead;
	
	list->numberOfElements++;
}

void addToEnd(List *list, int value)
{
	ListElement* position = list->head;
	
	while (position->next != nullptr)
	{
		position = position->next;
	}
	
	ListElement* newEnd = new ListElement{ value, nullptr };
	position->next = newEnd;
	
	list->numberOfElements++;
}

void deleteHead(List *list)
{
	ListElement *oldHead = list->head;
	list->head = list->head->next;
	delete oldHead;
	
	list->numberOfElements--;
}

void deleteList(List *list)
{
	while (list->head != nullptr)
	{
		deleteHead(list);
	}
}

int getValue(List *list, int num)
{
	ListElement* position = list->head;
	
	for (int i = 0; i < num; i++)
	{
		position = position->next;
	}
	return position->value;
}

ListElement *getHead(List *list)
{
	return list->head;
}

int getNumberOfElementsList(List *list)
{
	return list->numberOfElements;
}

int getValueHead(List *list)
{
	return list->head->value;
}
