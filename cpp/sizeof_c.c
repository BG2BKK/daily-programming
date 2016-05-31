// http://blog.csdn.net/w57w57w57/article/details/6626840
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

struct A{

	int num1;
	int num2;
	double num3;
};
struct B{

	int num1;
	double num3;
	int num2;
};

struct myin {
	char ch1:4;
	char ch2:4;
};


int pfunc(int n){
	int t[n];		// C99之后可以实现动态数组
	printf("%d\n", sizeof(t));
	return n;
}

int main(){

	printf("%d\n", sizeof(struct poll_list));

	void *p;
	printf("%d\n", sizeof(*p));
//	pfunc(5);

	printf("%d\n", sizeof(pfunc));
	printf("%d\n", sizeof(struct A));
	printf("%d\n", sizeof(struct B));
	printf("%d\n", sizeof(struct myin));
}
