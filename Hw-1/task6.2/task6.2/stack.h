#pragma once

struct StackElement;

/*создать стек*/
StackElement *createStack();

/*добавить элемент в список*/
void pop(StackElement *&head, char value);

/*взять элемент из списка*/
char getElement(StackElement *&head);

/*удалить список*/
void deletestack(StackElement *&head);


