#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "employee.h"

int main() {

	LinkedList linkedList;

	Employee *samuel = (Employee *)malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 32;

	Employee *sally = (Employee *)malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 28;

	Employee *susan = (Employee *)malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 45;

	initializeList(&linkedList);
	addHead(&linkedList, samuel);
	addHead(&linkedList, sally);
	addHead(&linkedList, susan);


	Queue queue;
	initializeQueue(&queue);
	enqueue(&queue, samuel);
	enqueue(&queue, sally);
	enqueue(&queue, susan);

	displayQueue(&queue, displayEmployee);

	Node *node = dequeue(&queue);
	displayEmployee(node->data);
	
	displayQueue(&queue, displayEmployee);

	Stack stack;
	initializeStack(&stack);
	push(&stack, samuel);
	push(&stack, sally);
	push(&stack, susan);

	displayStack(&stack, displayEmployee);

	node = top(&stack);
	displayEmployee(node->data);

	node = pop(&stack);
	displayEmployee(node->data);

	displayStack(&stack, displayEmployee);
}
