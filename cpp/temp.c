

#include <stdio.h>
#include <unistd.h>

int main()
{
	unsigned int usec = 100;
	while (1) {
		printf("\x07");
		usleep(usec);
	}
	return 0;
}
