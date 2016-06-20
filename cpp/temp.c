

#include <stdio.h>
#include <unistd.h>

int main()
{
	int x = 0x80000000;
	printf("%d\n", x);
	printf("%x\n", x);
	printf("%p\n", x);
}
