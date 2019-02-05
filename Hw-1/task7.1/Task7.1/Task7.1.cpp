// Task7.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"
#include <iostream>

using namespace std;

bool test()
{
	Tree *root = nullptr;

	int value1 = 1;
	int value2 = 2;
	
	insert(root, value1);
	insert(root, value2);
	deleteElement(root, value1);
	
	bool ok = ((!search(root, value1)) && search(root, value2));

	deleteTree(root);

	return ok;
}

void mainProcedure(Tree *root)
{
	int doing = 6;

	while (doing != 0)
	{
		cin >> doing;
		switch (doing)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			cout << "введите значение для добавления в множество" << endl;
			int newValue = 0;
			cin >> newValue;

			insert(root, newValue);

			break;
		}
		case 2:
		{
			cout << "введите значение для удаления из множества" << endl;
			int delValue = 0;
			cin >> delValue;

			if (!deleteElement(root, delValue))
			{
				cout << "значение не принадлежит множеству" << endl;
			}

			break;
		}
		case 3:
		{
			cout << "введите значение для проверки" << endl;
			int value = 0;
			cin >> value;

			if (search(root, value))
			{
				cout << "значение принадлежит множеству" << endl;
			}
			else
			{
				cout << "значение не принадлежит множеству" << endl;
			}

			break;
		}
		case 4:
		{
			increasePrint(root);
			cout << endl;

			break;
		}
		case 5:
		{
			decreasePrint(root);
			cout << endl;

			break;
		}
		default:
		{
			cout << "введено некорректное значение" << endl;

			break;
		}
		}
	}
}

int main()
{
	if (!test())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	setlocale(LC_ALL, "Russian");
	
	Tree *root = nullptr;
	
	cout << "0 - выход" << endl;
	cout << "1 - добавить значение в множество" << endl;
	cout << "2 - удалить значение из множества" << endl;
	cout << "3 - проверить, принадлежит ли значение множеству" << endl;
	cout << "4 - печать текущих элементов множества в возрастающем порядке" << endl;
	cout << "5 - печать текущих элементов множества в убывающем порядке" << endl;

	mainProcedure(root);
	
	deleteTree(root);
	
	return 0;
}

