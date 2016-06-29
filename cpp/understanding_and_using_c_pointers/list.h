#ifndef LIST_H
#define LIST_H
typedef void(*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);


typedef struct _node {
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

void initializeList(LinkedList *);
void addHead(LinkedList *, void *);
void addTail(LinkedList *, void *);
void delNode(LinkedList *, COMPARE, void *);
Node *getNode(LinkedList *, COMPARE, void *);
void displayLinkedList(LinkedList *, DISPLAY);
int isEmpty(LinkedList *);

#endif
