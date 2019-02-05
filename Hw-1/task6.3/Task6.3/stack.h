#pragma once
#include <string>

struct StackElement;

StackElement *createStack();

/*add element in stack*/
void push(StackElement *&head, char value);

/*delete "head" from stack*/
void deleteOfHead(StackElement *&head);

/*get value of element*/
char pop(StackElement *&head);

/*delete stack*/
void deleteStack(StackElement *&head);

/*get value of element*/
char getValue(StackElement *element);

