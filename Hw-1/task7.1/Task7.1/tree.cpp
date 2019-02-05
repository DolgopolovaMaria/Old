#include "stdafx.h"
#include "tree.h"
#include <iostream>

using namespace std;

struct Tree
{
	int value;
	Tree *leftChild;
	Tree *rightChild;
};

void insert(Tree *&root, int valueForInsert)
{
	if (root == nullptr)
	{
		Tree *newElement = new Tree{ valueForInsert, nullptr, nullptr};
		root = newElement;
		return;
	}
	if (valueForInsert < root->value)
	{
		insert(root->leftChild, valueForInsert);
	}
	if (valueForInsert > root->value)
	{
		insert(root->rightChild, valueForInsert);
	}
}

bool search(Tree *root, int valueForFind)
{
	if (root == nullptr)
	{
		return false;
	}
	if (valueForFind > root->value)
	{
		return search(root->rightChild, valueForFind);
	}
	if (valueForFind < root->value)
	{
		return search(root->leftChild, valueForFind);
	}
	return true;
}

bool deleteElement(Tree *&root, int valueForDelete)
{
	if (!search(root, valueForDelete))
	{
		return false;
	}
	if (valueForDelete < root->value)
	{
		deleteElement(root->leftChild, valueForDelete);
	}
	if (valueForDelete > root->value)
	{
		deleteElement(root->rightChild, valueForDelete);
	}

	if (valueForDelete == root->value)
	{

		if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
		{
			delete root;
			root == nullptr;
			return true;
		}

		if (root->leftChild == nullptr)
		{
			Tree *oldElement = root;
			root = oldElement->rightChild;
			delete oldElement;
			return true;
		}

		if (root->rightChild == nullptr)
		{
			Tree *oldElement = root;
			root = oldElement->leftChild;
			delete oldElement;
			return true;
		}

		Tree *newroot = root->rightChild;
		while (newroot->leftChild != nullptr)
		{
			newroot = newroot->leftChild;
		}

		root->value = newroot->value;
		newroot->value = valueForDelete;
		deleteElement(root, valueForDelete);
	}
}

void increasePrint(Tree *root)
{
	if (root == nullptr)
	{
		return;
	}
	increasePrint(root->leftChild);
	cout << root->value << " ";
	increasePrint(root->rightChild);
}

void decreasePrint(Tree *root)
{
	if (root == nullptr)
	{
		return;
	}
	decreasePrint(root->rightChild);
	cout << root->value << " ";
	decreasePrint(root->leftChild);
}

void deleteTree(Tree *&root)
{
	if (root == nullptr)
	{
		return;
	}
	if ((root->rightChild == nullptr) && (root->leftChild == nullptr))
	{
		delete root;
		return;
	}
	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	delete root;
	
	return;
}