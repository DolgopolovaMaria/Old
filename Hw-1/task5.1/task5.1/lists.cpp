#include "stdafx.h"
#include "lists.h"
#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void print(ListElement *head)
{
	auto i = head;
	while (i != nullptr)
	{
		cout << i->value << " ";
		i = i->next;
	}
	cout << endl;
}

void push(ListElement *&head, int value)
{
	auto newElement = new ListElement{ value, head };
	head = newElement;
}

void insert(ListElement *&head, int elementForInsert)
{
	if (head == nullptr)
	{
		head = new ListElement{ elementForInsert, nullptr };
	}
	else
	{
		push(head, elementForInsert);

		for (auto j = head; j->next != nullptr; j = j->next)
		{
			if (j->value > j->next->value)
			{
				swap(j->value, j->next->value);
			}
		}
	}
}

void sort(ListElement *head)
{
	for (auto i = head; i != nullptr; i = i->next)
	{
		for (auto j = head; j->next != nullptr; j = j->next)
		{
			if (j->value > j->next->value)
			{
				swap(j->value, j->next->value);
			}
		}
	}
}

void deleteOfHead(ListElement *&head)
{
	ListElement *oldHead = head;
	head = head->next;
	delete oldHead;
}

bool deleteOfElement(ListElement *&head, int elementForDelete)
{
	auto i = head;
	while ((i->value != elementForDelete) && (i->next != nullptr))
	{
		i = i->next;
	}
	if (i->value == elementForDelete)
	{
		swap(i->value, head->value);
		deleteOfHead(head);
		sort(head);
		return true;
	}
	else
	{
		return false;
	}
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteOfHead(head);
	}
}

bool testList()
{
	ListElement *head = nullptr;
	insert(head, 3);
	insert(head, 1);
	insert(head, 2);
	deleteOfElement(head, 2);
	bool ok = ((head->value == 1) && (head->next->value == 3) && (head->next->next == nullptr));
	deleteList(head);
	return ok;
}
