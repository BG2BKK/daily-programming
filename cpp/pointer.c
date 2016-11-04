#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

void test() {
	char a = 33;
	printf("%p\n", &a);

	char *p = &a;
	printf("%p\t%p\t%d\n", p, &p, *p);

	char **pp = &p;
	printf("%p\t%p\t%p\t%d\n", pp, &pp, *pp, **pp);
}

void test_array() {
	char *a = malloc(1024);
	printf("%p\t%p\n", &a, a);
	a[0] = 40;	a[1] = 41;	a[2] = 42;	a[3] = 43;
	a[4] = 44;	a[5] = 45;	a[6] = 46;	a[7] = 47;

	for(int i = 0; i < 8; i++) 
		printf("%d\t", a[i]);
	printf("\n");

	char *p = &a[0];
	printf("%p\t%p\t%d\n", p, &p, *p);

	char **pp = &p;
	printf("%p\t%p\t%p\t%d\n", pp, &pp, *pp, **pp);

	char **ppp = (char **)&a[0];
	printf("%p\t%p\t%d\n", ppp, &ppp, *ppp);

	*ppp = (char **)&a[1];
	printf("%p\t%p\t%p\n", ppp, &ppp, *ppp);

	for(int i = 0; i < 8; i++) 
		printf("%d\t", a[i]);
	printf("addr of a[1] is %p\n", a+1);

	char **ap0 = a[0];
	char **ap1 = &a[0];
	printf("%p\t%p\t%p\t%x\n", a, ap0, ap1, *ap1);
}

int main() {
	test_array();
}
