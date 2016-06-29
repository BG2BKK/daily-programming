
#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"
typedef LinkedList Queue;

void initializeQueue(Queue *);
void enqueue(Queue *, void *);
Node *dequeue(Queue *);
#endif
