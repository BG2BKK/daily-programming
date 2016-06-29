#include "list.h"
#include "stack.h"
#include "stdio.h"

void initializeStack(Stack *stack) {
	stack->head = stack->tail = NULL;
}

void push(Stack *stack, void *data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(stack->head == NULL) {
		stack->head = stack->tail = node;
	} else {
		node->next = stack->head;
		stack->head = node;
	}
}

Node *pop(Stack *stack) {
	
	if(stack->head == NULL) {
		return NULL;
	} else if (stack->head == stack->tail) {
		Node *temp = stack->head;
		stack->head = stack->tail = NULL;
	} else {
		Node *temp = stack->head;
		stack->head = stack->head->next;
		return temp;
	}
}

Node *top(Stack *stack) {
	return stack->head;
}

void displayStack(Stack *stack, DISPLAY display) {
	printf("print stack\n");
	Node *temp = stack->head;
	while(temp) {
		display(temp->data);
		temp = temp->next;
	}
}
