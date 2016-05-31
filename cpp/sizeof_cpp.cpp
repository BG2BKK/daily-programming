#include <stdio.h>
#include <stdlib.h>

struct pollfd {
	int fd;
	short events;
	short revents;
};

struct poll_list {
	struct poll_list *next;
	int len;
	struct pollfd entries[0];
};

int main(){
	
	printf("%d\n", sizeof(struct poll_list));

	void *p;
	printf("%d\n", sizeof(p));

	int*a = new int[10];int n = sizeof(a);
	printf("%d\n", n);
}
