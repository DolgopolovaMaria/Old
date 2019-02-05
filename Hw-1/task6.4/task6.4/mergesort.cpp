#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "listPhone.h"

using namespace std;

ListElement *middle(ListElement *&head)
{
	ListElement *secondHalf = nullptr;
	ListElement *firstHalf = nullptr;

	ListElement *middleElement = head;
	ListElement *element = head;

	int index = 1;
	while (getNext(element) != nullptr)
	{
		element = getNext(element);
		if (index % 2 == 0)
		{
			push(firstHalf, getName(middleElement), getPhone(middleElement));
			middleElement = getNext(middleElement);
		}
		index++;
	}
	push(firstHalf, getName(middleElement), getPhone(middleElement));

	while (getNext(middleElement) != nullptr)
	{
		middleElement = getNext(middleElement);
		push(secondHalf, getName(middleElement), getPhone(middleElement));
	}

	deleteList(head);
	head = firstHalf;

	return secondHalf;
}

ListElement *merge(ListElement *&firstHalf, ListElement *&secondHalf, bool sortOfNumber)
{
	ListElement *resultPosition = nullptr;
	ListElement *firstPosition = firstHalf;
	ListElement *secondPosition = secondHalf;

	while ((firstPosition != nullptr) && (secondPosition != nullptr))
	{
		if ((sortOfNumber && (getPhone(firstPosition) < getPhone(secondPosition))) || (!sortOfNumber && (getName(firstPosition) < getName(secondPosition))))
		{
			addToEnd(resultPosition, getName(firstPosition), getPhone(firstPosition));
			firstPosition = getNext(firstPosition);
		}
		else
		{
			addToEnd(resultPosition, getName(secondPosition), getPhone(secondPosition));
			secondPosition = getNext(secondPosition);
		}
	}

	while (firstPosition != nullptr)
	{
		addToEnd(resultPosition, getName(firstPosition), getPhone(firstPosition));
		firstPosition = getNext(firstPosition);
	}
	while (secondPosition != nullptr)
	{
		addToEnd(resultPosition, getName(secondPosition), getPhone(secondPosition));
		secondPosition = getNext(secondPosition);
	}
	
	deleteList(firstHalf);
	deleteList(secondHalf);
	
	return resultPosition;
}

int listSize(ListElement *head)
{
	ListElement *element = head;
	int result = 0;
	while (element != nullptr)
	{
		element = getNext(element);
		result++;
	}

	return result;
}

void mergeSort(ListElement *&head, bool sortNumber)
{
	if (listSize(head) < 2)
	{
		return;
	}

	ListElement *secondHalf = middle(head);
	ListElement *firstHalf = head;

	mergeSort(firstHalf, sortNumber);
	mergeSort(secondHalf, sortNumber);
	
	head = merge(firstHalf, secondHalf, sortNumber);
}