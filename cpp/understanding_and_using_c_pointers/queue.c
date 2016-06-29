#include "stdio.h"
#include "queue.h"
#include "list.h"

void initializeQueue(Queue *queue) {
	queue->head = queue->tail = NULL;
}

void enqueue(Queue *queue, void *data) {
	Node *node = (Node *) malloc( sizeof(Node) );
	node->data = data;
	node->next = NULL;

	if(queue->head == NULL) {
		queue->head = node;
		queue->tail = node;
	} else {
		queue->tail->next = node;
		queue->tail = node;
	} 
}

Node *dequeue(Queue *queue) {
	if (queue->head == NULL ) {
		return NULL;
	} else if (queue->head == queue->tail) {
		Node *tmp = queue->head;
		queue->head = queue->tail = NULL;
		return queue->head;
	} else {
		Node *tmp = queue->head;
		queue->head = queue->head->next;
		return tmp;
	}
}

void displayQueue(Queue *queue, DISPLAY display) {
	printf("print queue\n");
	Node *temp = queue->head;
	while(temp) {
		display(temp->data);
		temp = temp->next;
	}
}
