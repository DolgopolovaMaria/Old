// task8.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

bool test()
{
	Tree *root = nullptr;

	string key1 = "key1";
	string key2 = "key2";
	string value1 = "value1";
	string value2 = "value2";

	insertElement(root, key1, value1);
	insertElement(root, key2, value2);
	deleteElement(root, key1);
	bool ok = ((searchKey(root, key1) == nullptr) && (getValue(root, key2) == "value2"));
	deleteTree(root);

	return ok;
}

void mainProcedure(Tree *&root)
{
	int doing = 5;
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
			cout << "������� ���� ��� ���������� � ������" << endl;
			string key;
			cin >> key;

			cout << "������� �������� ��� ���������� � ������" << endl;
			string value;
			cin >> value;

			insertElement(root, key, value);

			break;
		}
		case 2:
		{
			cout << "������� ����" << endl;
			string key;
			cin >> key;

			if (searchKey(root, key) == nullptr)
			{
				cout << "������ ����� ��� � �������" << endl;
			}
			else
			{
				cout << getValue(root, key) << endl;
			}

			break;
		}
		case 3:
		{
			cout << "������� ����" << endl;
			string key;
			cin >> key;

			if (searchKey(root, key) == nullptr)
			{
				cout << "������ ����� ��� � �������" << endl;
			}
			else
			{
				cout << "����� ���� ���� � �������" << endl;
			}

			break;
		}
		case 4:
		{
			cout << "������� ���� ��� �������� �� �������" << endl;
			string key;
			cin >> key;

			if (!deleteElement(root, key))
			{
				cout << "������ ����� ��� � �������" << endl;
			}
			break;
		}
		default:
		{
			cout << "�� ����� ������������ ��������" << endl;
			break;
		}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		cout << "error!";
		return 0;
	}

	Tree *root = nullptr;

	cout << "0 - ?????" << endl;
	cout << "1 - ???????? ???????? ?? ????????? ????? ? ????????????? ??????" << endl;
	cout << "2 - ???????? ???????? ?? ????????? ????? ?? ?????????????? ???????" << endl;
	cout << "3 - ????????? ??????? ????????? ?????" << endl;
	cout << "4 - ??????? ???????? ???? ? ????????? ? ??? ???????? ?? ?????????????? ???????" << endl;

	mainProcedure(root);

	deleteTree(root);
	return 0;
}