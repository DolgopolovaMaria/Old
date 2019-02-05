#pragma once

struct StackElement;

/*create new stack*/
StackElement *createStack();

/*add new element in stack*/
void pop(StackElement *&head, char value);

/*get value of element from stack*/
double getElement(StackElement *&head);

/*delete stack*/
void deleteStack(StackElement *&head);

