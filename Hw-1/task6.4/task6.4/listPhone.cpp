#include "stdafx.h"
#include <iostream>
#include "listPhone.h"
#include <fstream>
#include <string>

using namespace std;

struct ListElement
{
	std::string name;
	std::string phone;
	ListElement *next;
};

ListElement *getNext(ListElement *element)
{
	return element->next;
}

string getName(ListElement *element)
{
	return element->name;
}

string getPhone(ListElement *element)
{
	return element->phone;
}

void push(ListElement *&head, const string &name, const string &phone)
{
	auto newElement = new ListElement{ name, phone, head };
	head = newElement;
}

void addToEnd(ListElement *&head, const string &name, const string &phone)
{
	if (head == nullptr)
	{
		head = new ListElement{ name, phone, nullptr };
		return;
	}
	ListElement *position = head;
	while (position->next != nullptr)
	{
		position = position->next;
	}
	position->next = new ListElement{ name, phone, nullptr };
}

void readFromFile(ifstream &fin, ListElement *&head)
{
	string name;
	string phone;

	while (!(fin.eof()))
	{
		fin >> name;
		fin >> phone;
		push(head, name, phone);
	}
}

void printList(ListElement *head)
{
	auto i = head;
	while (i != nullptr)
	{
		cout << i->name << " " << i->phone << endl;
		i = i->next;
	}
}

void deleteHead(ListElement *&head)
{
	ListElement *oldhead = head;
	head = head->next;
	delete oldhead;
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		deleteHead(head);
	}
}
