#pragma once

#include <string>

struct Record
{
	std::string number;
	std::string name;
};

/*добавить запись*/
void addNote(Record arrayOfRecords[], int lengthOfArray);

/*распечатать все имеющиеся записи*/
void print(Record array[], int length);

/*найти номер телефона по имени*/
void findNumber(Record arrayOfRecords[], int length, std::string name);

/*найти имя по номеру телефона*/
void findName(Record arrayOfRecords[], int length, std::string number);

/*сохранить текущие данные в файл*/
void saveInFile(Record arrayOfRecords[], int length);

/*прочитать данные из файла*/
void readingFromFile(Record arrayOfRecords[], int length);