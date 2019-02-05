#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>

using namespace std;

struct ListElement
{
	std::string value;
	int number;
	ListElement *next;
};

void increaseElementNumber(ListElement *&element)
{
	element->number++;
}

int getNumber(ListElement *&element)
{
	return element->number;
}

void push(ListElement *&head, string &value)
{
	auto newElement = new ListElement{ value, 1, head };
	head = newElement;
}

void deleteOfHead(ListElement *&head)
{
	ListElement *oldHead = head;
	head = head->next;
	delete oldHead;
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteOfHead(head);
	}
}

bool search(ListElement *head, string &valueForSearch, ListElement *&searchElement)
{
	searchElement = head;
	while (searchElement != nullptr)
	{
		if (searchElement->value == valueForSearch)
		{
			return true;
		}
		searchElement = searchElement->next;
	}
	return false;
}

void print(ListElement *head)
{
	ListElement *element = head;
	while (element != nullptr)
	{
		cout << element->value << " " << element->number << endl;
		element = element->next;
	}
}