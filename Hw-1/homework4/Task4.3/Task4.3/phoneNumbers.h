#pragma once

#include <string>

struct Record
{
	std::string number;
	std::string name;
};

/*�������� ������*/
void addNote(Record arrayOfRecords[], int lengthOfArray);

/*����������� ��� ��������� ������*/
void print(Record array[], int length);

/*����� ����� �������� �� �����*/
void findNumber(Record arrayOfRecords[], int length, std::string name);

/*����� ��� �� ������ ��������*/
void findName(Record arrayOfRecords[], int length, std::string number);

/*��������� ������� ������ � ����*/
void saveInFile(Record arrayOfRecords[], int length);

/*��������� ������ �� �����*/
void readingFromFile(Record arrayOfRecords[], int length);