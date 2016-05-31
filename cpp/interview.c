#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct test{
	char *ch1;
	int i;
	long ch2;
} aa;

int main()
{
	int a = 0;
	int b = 1;
	int c = MAX(a++, b++);
	printf("%d\n", c);

	printf("%lu\n", (unsigned long)sizeof(aa));
	printf("%lu\n", (unsigned long)sizeof(aa));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	
}
