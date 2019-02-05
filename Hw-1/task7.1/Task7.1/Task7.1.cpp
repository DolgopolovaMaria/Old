// Task7.1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
			cout << "������� �������� ��� ���������� � ���������" << endl;
			int newValue = 0;
			cin >> newValue;

			insert(root, newValue);

			break;
		}
		case 2:
		{
			cout << "������� �������� ��� �������� �� ���������" << endl;
			int delValue = 0;
			cin >> delValue;

			if (!deleteElement(root, delValue))
			{
				cout << "�������� �� ����������� ���������" << endl;
			}

			break;
		}
		case 3:
		{
			cout << "������� �������� ��� ��������" << endl;
			int value = 0;
			cin >> value;

			if (search(root, value))
			{
				cout << "�������� ����������� ���������" << endl;
			}
			else
			{
				cout << "�������� �� ����������� ���������" << endl;
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
			cout << "������� ������������ ��������" << endl;

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
	
	cout << "0 - �����" << endl;
	cout << "1 - �������� �������� � ���������" << endl;
	cout << "2 - ������� �������� �� ���������" << endl;
	cout << "3 - ���������, ����������� �� �������� ���������" << endl;
	cout << "4 - ������ ������� ��������� ��������� � ������������ �������" << endl;
	cout << "5 - ������ ������� ��������� ��������� � ��������� �������" << endl;

	mainProcedure(root);
	
	deleteTree(root);
	
	return 0;
}

