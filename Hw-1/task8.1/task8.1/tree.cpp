#include "stdafx.h"
#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

struct Array
{
	string key;
	string value;
};

struct Tree
{
	Array array;
	Tree *leftChild;
	Tree *rightChild;
	Tree *parent;
};

void rightRotation(Tree *&child, Tree *&parent)
{
	parent->leftChild = child->rightChild;
	child->parent = parent->parent;
	parent->parent = child;
	child->rightChild = parent;
}

void leftRotation(Tree *&child, Tree *&parent)
{
	parent->rightChild = child->leftChild;
	child->parent = parent->parent;
	parent->parent = child;
	child->leftChild = parent;
}

void zig(Tree *&child, Tree *&parent)
{
	if (parent->leftChild == child)
	{
		rightRotation(child, parent);
	}
	else
	{
		leftRotation(child, parent);
	}
}

void zigzig(Tree *&child, Tree *&parent)
{
	if (parent->leftChild == child)
	{
		rightRotation(parent, parent->parent);
		rightRotation(child, parent);
	}
	else
	{
		leftRotation(parent, parent->parent);
		leftRotation(child, parent);
	}
}

void zigzag(Tree *&child, Tree *&parent)
{
	if (parent->leftChild == child)
	{
		leftRotation(child, parent);
		rightRotation(child, parent);
	}
	else
	{
		rightRotation(child, parent);
		leftRotation(child, parent);
	}
}

void splayTree(Tree *&element)
{
	while (element->parent != nullptr)
	{
		Tree *parent = element->parent;

		if (parent->parent == nullptr)
		{
			zig(element, parent);
			break;
		}
		else if (((parent->leftChild == element) && (parent->parent->leftChild == parent)) ||
			((parent->rightChild == element) && (parent->parent->rightChild == parent)))
		{
			zigzig(element, parent);
			break;
		}
		else if (((parent->rightChild == element) && (parent->parent->leftChild == parent)) ||
			((parent->leftChild == element) && (parent->parent->rightChild == parent)))
		{
			zigzag(element, parent);
			break;
		}
	}
}

Tree *searchKey(Tree *root, const string &keyForFind)
{
	if (root == nullptr)
	{
		return root;
	}
	if ((root->array.key == keyForFind))
	{
		splayTree(root);
		return root;
	}
	if (keyForFind > root->array.key)
	{
		return searchKey(root->rightChild, keyForFind);
	}
	return searchKey(root->leftChild, keyForFind);
}

void insert(Tree *&root, Tree *&parent, const string &keyForInsert, const string &valueForInsert)
{
	if (root == nullptr)
	{
		Array newArray = { keyForInsert, valueForInsert };
		root = new Tree{ newArray, nullptr, nullptr, parent };
		return;
	}

	if (keyForInsert < root->array.key)
	{
		insert(root->leftChild, root, keyForInsert, valueForInsert);
	}
	if (keyForInsert > root->array.key)
	{
		insert(root->rightChild, root, keyForInsert, valueForInsert);
	}
	if (root->array.key == keyForInsert)
	{
		searchKey(root, keyForInsert)->array.value == valueForInsert;
	}
}

void insertElement(Tree *&root, const string &keyForInsert, const string &valueForInsert)
{
	Tree *parent = nullptr;
	insert(root, parent, keyForInsert, valueForInsert);
	splayTree(root);
}

bool deleteElement(Tree *&root, const string &keyForDelete)
{
	if (root == nullptr)
	{
		return false;
	}
	
	if (keyForDelete < root->array.key)
	{
		return deleteElement(root->leftChild, keyForDelete);
	}
	if (keyForDelete > root->array.key)
	{
		return deleteElement(root->rightChild, keyForDelete);
	}

	if (keyForDelete == root->array.key)
	{
		if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
		{
			Tree *elementForSplay = root->parent;
			delete root;
			root = nullptr;
			if (elementForSplay != nullptr)
			{
				splayTree(elementForSplay);
			}
			return true;
		}

		if (root->leftChild == nullptr)
		{
			Tree *elementForSplay = root->parent;
			Tree *oldElement = root;
			Tree *newRoot = root->rightChild;
			root->rightChild->parent = root->parent;

			if (root->parent)
			{
				root->parent->leftChild = root->rightChild;
			}
			root = newRoot;
			delete oldElement;
			oldElement = nullptr;

			if (elementForSplay != nullptr)
			{
				splayTree(elementForSplay);
			}
			return true;
		}

		if (root->rightChild == nullptr)
		{
			Tree *elementForSplay = root->parent;
			Tree *oldElement = root;
			Tree *newRoot = root->leftChild;
			root->leftChild->parent = root->parent;

			if (root->parent)
			{
				root->parent->rightChild = root->leftChild;
			}
			root = newRoot;
			delete oldElement;

			if (elementForSplay != nullptr)
			{
				splayTree(elementForSplay);
			}
			return true;
		}

		Tree *newroot = root->rightChild;
		while (newroot->leftChild != nullptr)
		{
			newroot = newroot->leftChild;
		}
		Array temp = root->array;
		root->array = newroot->array;
		newroot->array = temp;
		return deleteElement(newroot, keyForDelete);
	}
}

string getValue(Tree *root, const string &key)
{
	return searchKey(root, key)->array.value;
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
}

void increasePrint(Tree *root)
{
	if (root == nullptr)
	{
		return;
	}
	increasePrint(root->leftChild);
	cout << root->array.key << " ";
	increasePrint(root->rightChild);
}