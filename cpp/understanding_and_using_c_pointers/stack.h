#ifndef STACK_H
#define STACK_H

#include "list.h"
typedef LinkedList Stack;

void initializeStack(Stack *);
void push(Stack *, void *);
Node *pop(Stack *);

#endif
