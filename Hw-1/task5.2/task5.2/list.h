#pragma once

struct listElement
{
	int value;
	listElement *next;
};

// create new list
listElement* creationOfList(int size);

// delete element from list
int deleteElement(listElement *&first, int m);
