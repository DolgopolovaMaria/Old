#include "stdafx.h"
#include "calculateTree.h"
#include <string>
#include <iostream>

using namespace std;

struct Tree
{
	int value;
	char operation;
	Tree *leftChild;
	Tree *rightChild;
};

Tree *createNewTree()
{
	Tree *root = new Tree{ 0, '0', nullptr, nullptr };
	return root;
}

void buildTree(Tree *&root, string str)
{
	if (str[0] == '(')
	{
		string newStr = str.substr(1, str.length() - 2);
		str = newStr;
	}
	
	int index = 0;
	char symbol = str[index];
	
	if ((symbol == '*') || (symbol == '/') || (symbol == '+') || (symbol == '-'))
	{
		root->operation = symbol;
		index++;
		if (str[index] == ' ')
		{
			index++;
		}
		
		if (str[index] == '(')
		{
			int ind = 1;
			string newstr = "(";
			while (ind != 0)
			{
				index++;
				
				if (str[index] == '(')
				{
					ind++;
				}
				if (str[index] == ')')
				{
					ind--;
				}

				newstr = newstr + str[index];
			}
			
			root->leftChild = new Tree{ 0, '0', nullptr, nullptr };
			buildTree(root->leftChild, newstr);
		
			index++;
			if (str[index] == ' ')
			{
				index++;
			}
		}
		else
		{
			if (str[index] == ' ')
			{
				index++;
			}
			string newstr = "";
			while ((str[index] >= '0') && (str[index] <= '9'))
			{
				newstr = newstr + str[index];
				index++;
			}
			
			root->leftChild = new Tree{ atoi(newstr.c_str()), '0', nullptr, nullptr };
		
			if (str[index] == ' ')
			{
				index++;
			}
		}
	
		if (str[index] == ' ')
		{
			index++;
		}

		if (str[index] == '(')
		{
			int ind = 1;
			string newstr = "(";
			while (ind != 0)
			{
				index++;

				if (str[index] == '(')
				{
					ind++;
				}
				if (str[index] == ')')
				{
					ind--;
				}

				newstr = newstr + str[index];
			}
		
			root->rightChild = new Tree{ 0, '0', nullptr, nullptr };
			buildTree(root->rightChild, newstr);
		
			if (str[index] == ' ')
			{
				index++;
			}
		}
		else
		{
			if (str[index] == ' ')
			{
				index++;
			}
			string newstr = "";
			while ((str[index] >= '0') && (str[index] <= '9'))
			{
				newstr = newstr + str[index];
				index++;
			}
			
			root->rightChild = new Tree{ atoi(newstr.c_str()), '0', nullptr, nullptr };
		
			if (str[index] == ' ')
			{
				index++;
			}
		}
	}
}

void print(Tree *root)
{
	if (root == nullptr)
	{
		return;
	}

	if ((root->operation == '*') || (root->operation == '/') || (root->operation == '+') || (root->operation == '-'))
	{
		cout << "(" << root->operation << " ";
		print(root->leftChild);
		print(root->rightChild);
		cout << ")";
	}
	else
	{
		cout << root->value << " ";
	}
}

int calc(Tree *root)
{
	switch (root->operation)
	{
		case '*':
		{
			return calc(root->leftChild) * calc(root->rightChild);
			break;
		}
		case '/':
		{
			return calc(root->leftChild) / calc(root->rightChild);
			break;
		}
		case '+':
		{
			return calc(root->leftChild) + calc(root->rightChild);
			break;
		}
		case '-':
		{
			return calc(root->leftChild) - calc(root->rightChild);
			break;
		}
		default:
		{
			return root->value;
			break;
		}
	}
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
	