// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int i, j, k, m, n, res=0;
int main()
{
	res = 0;
	for (m = 0; m <= 27; m++)
	{
		n = 0;
		for (i = 0; i <= 9; i++)
		{
			for (j = 0; j <= 9; j++)
			{
				for (k = 0; k <= 9; k++)
				{
					if (i + j + k == m)
					{
						n++;
					}
				}
			}
		}
		res = res + n*n;
	}
	cout << res;
	return 0;
}

