#pragma once

struct StackElement;

/*������� ����*/
StackElement *createStack();

/*�������� ������� � ������*/
void pop(StackElement *&head, char value);

/*����� ������� �� ������*/
char getElement(StackElement *&head);

/*������� ������*/
void deletestack(StackElement *&head);


