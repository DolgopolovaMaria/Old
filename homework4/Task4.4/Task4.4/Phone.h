#pragma once
#include <iostream>
#include <string>

using namespace std;

void addNote(struct record, int); //�������� ������

void print(); // ����������� ��� ��������� ������

int findNumber(string name); //����� ������� �� �����

int findName(string number); //����� ��� �� ��������

void saveInFile(); //��������� ������� ����� � ����