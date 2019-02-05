// task5.1.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include "lists.h"

using namespace std;


int main()
{
	if (!testList())
	{
		cout << "error!" << endl;
		return 0;
	}
	
	cout << "0 - exit" << endl;
	cout << "1 - add element in sorted list" << endl;
	cout << "2 - delete element from the list" << endl;
	cout << "3 - print the list" << endl;
	
	ListElement *head = nullptr;

	bool exit = false;
	while (!exit)
	{
		int doing = 0;
		cin >> doing;
		switch (doing)
		{
			case 0:
			{
				exit = true;
				
				break;
			}
			case 1:
			{
				cout << "enter value for adding in the list" << endl;

				int value = 0;
				cin >> value;
				
				insert(head, value);

				break;
			}
			case 2:
			{
				cout << "enter value for deletion from the list" << endl;

				int value = 0;
				cin >> value;
				
				bool ok = deleteOfElement(head, value);
				if (!ok)
				{
					cout << "this value is not contained in the list" << endl;
				}
				
				break;
			}
			case 3:
			{
				print(head);
				
				break;
			}
			default:
			{
				cout << "you entered incorrect command" << endl;

				break;
			}
		}
	}

	deleteList(head);
	return 0;
}

