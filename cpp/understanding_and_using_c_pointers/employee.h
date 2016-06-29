#include "stdio.h"
#include "string.h"

typedef struct _employee {
	char name[32];
	unsigned char age;
} Employee;


int compareEmployee(Employee *e1, Employee *e2);

void displayEmployee(Employee *e);
