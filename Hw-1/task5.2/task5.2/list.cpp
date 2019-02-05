#include "stdafx.h"
#include "list.h"

void addElement(listElement *&last, int newValue)
{
	listElement *newElement = new listElement;
	newElement->value = newValue;
	last->next = newElement;
	last = newElement;
}

listElement* creationOfList(int size)
{
	listElement *first = new listElement{ 1, nullptr };
	listElement *last = first;
	for (int i = 2; i <= size; i++)
	{
		addElement(last, i);
	}
	last->next = first;

	return last;
}

void del(listElement *previous)
{
	listElement *delElement = previous->next;
	previous->next = delElement->next;
	delete delElement;
}

int deleteElement(listElement *&first, int m)
{
	listElement *element = first;

	while (element->next != element)
	{
		for (int i = 1; i < m; i++)
		{
			element = element->next;
		}

		del(element);
	}

	int res = element->value;

	first = element;
	
	return res;
}