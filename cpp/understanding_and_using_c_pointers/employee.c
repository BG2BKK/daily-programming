#include "employee.h"

int compareEmployee(Employee *e1, Employee *e2) {
	return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *e) {
	printf("%s\t%d\n", e->name, e->age);
}
