#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define TYPE long 

static TYPE **
enough_duration(register long N, register TYPE ** p)
{
#define	ENOUGH_DURATION_TEN(one)	one one one one one one one one one one
	while (N-- > 0) {
		ENOUGH_DURATION_TEN(p = (TYPE **) *p;);
	}
	return (p);
}
int main(char argc, char *argv[]) {
	unsigned long n = atoi(argv[1]);
	printf("%d\n", sizeof(n));
	printf("loop count: %lu\n", n);

	TYPE *x = (TYPE *)&x;
	TYPE **p = (TYPE **)&x;

	struct timeval st, ed;
	gettimeofday(&st, NULL);
	while(n--) {
		enough_duration(n, p);
	}
	gettimeofday(&ed, NULL);

	printf("%d\t%d\n", st.tv_sec, st.tv_usec);
	printf("%d\t%d\n", ed.tv_sec, ed.tv_usec);
}
