#include "stdio.h"
#include "stdlib.h"
#include "list.h"

void initializeList(LinkedList *list) {
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void addHead(LinkedList *list, void *data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;

	if(list->head == NULL) {
		list->tail = node;
		node->next = NULL;
	} else {
		node->next = list->head;
	}
	list->head = node;
}

void addTail(LinkedList *list, void *data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL) {
		list->head = node;
	} else {
		list->tail->next = node;
	}
	list->tail = node;
}

Node *getNode(LinkedList *list, COMPARE compare, void *data) {
	if( isEmpty(list) || data == NULL)
		return NULL;
	Node *node = list->head;
	while(node) {
		if(compare(node->data, data) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int isEmpty(LinkedList *list) {
	return list->head == NULL && list->head == list->tail;
}

void delNode(LinkedList *list, COMPARE compare, void *data) {
	if( isEmpty(list) || data == NULL)
		return;
	if(compare(list->head->data, data) == 0){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
		free(data);
	} else {
		Node *temp = list->head;
		while(temp->next != NULL && compare(temp->next->data, data)) {
			temp = temp->next;
		}
		if(temp->next != NULL) {
			temp->next = temp->next->next;
			free(data);
		} 
	}
}

void displayLinkedList(LinkedList *list , DISPLAY display) {
	printf("LinkedList:\n");
	Node *node = list->head;
	while(node) {
		display(node->data);
		node = node->next;
	}
}
