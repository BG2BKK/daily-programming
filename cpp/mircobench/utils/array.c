#include <stdio.h>
#include <unistd.h>

int main() {
	char *arr = (char *)malloc(sizeof(char) * 1024);

	char **p = arr;
	printf("%p\t%p\t%p\n", arr, p, *p);

	*p = (char *)&arr[16];
	*(char **)&arr[16] = (char *)&arr[32];

	printf("%p\t%p\t%p\n", arr, p, *p);

	p = *p;

	printf("%p\t%p\t%p\n", arr, p, *p);
}
