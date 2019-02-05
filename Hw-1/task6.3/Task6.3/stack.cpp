#include "stdafx.h"
#include "stack.h"
#include <string>
#include <iostream>

using namespace std;

struct StackElement
{
	char value;
	StackElement *next;
};

StackElement *createStack()
{
	StackElement *head = new StackElement{ '0', nullptr };
	return head;
}

void push(StackElement *&head, char value)
{
	StackElement *newElement = new StackElement{ value, head };
	head = newElement;
}

void deleteOfHead(StackElement *&head)
{
	StackElement *oldHead = head;
	head = head->next;
	delete oldHead;
}

char pop(StackElement *&head)
{
	char value = head->value;
	deleteOfHead(head);
	return value;
}

void deleteStack(StackElement *&head)
{
	while (head != nullptr)
	{
		deleteOfHead(head);
	}
}

char getValue(StackElement *element)
{
	return element->value;
}
