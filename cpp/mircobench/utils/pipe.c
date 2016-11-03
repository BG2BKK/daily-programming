#include <stdio.h>
#include <unistd.h>

int main() {
	int p[2];

	int ret = pipe(p);
	if(ret)
		printf("pipe error: %d\n", ret);
	char buf[32768];
	memset(buf, 0, 32768);
	while(1) {
		int n = write(p[1], buf, 32768);
		printf("%d\n", n);
		sleep(1);
	}
}
