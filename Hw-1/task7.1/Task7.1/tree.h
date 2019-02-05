#pragma once

struct Tree;

/*���������� �������� � �������� ������ */
void insert(Tree *&root, int valueForInsert);

/*����� �������� � �������� ������*/
bool search(Tree *root, int valueForFind);

/*�������� ��������*/
bool deleteElement(Tree *&root, int valueForDelete);

/*������ ��������� � ������������ �������*/
void increasePrint(Tree *root);

/*������ ��������� � ��������� �������*/
void decreasePrint(Tree *root);

/*�������� ������*/
void deleteTree(Tree *&root);

