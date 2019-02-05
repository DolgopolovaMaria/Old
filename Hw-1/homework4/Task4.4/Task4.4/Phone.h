#pragma once
#include <iostream>
#include <string>

using namespace std;

void addNote(struct record, int); //добавить запись

void print(); // распечатать все имеющиеся записи

int findNumber(string name); //найти телефон по имени

int findName(string number); //найти имя по телефону

void saveInFile(); //сохранить текущие даные в файл