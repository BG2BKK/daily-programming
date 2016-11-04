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
}
char *prepare(unsigned long len, int stride) {
	int i;
	char *buf = (char *)malloc(sizeof(char) * len);
	if(!buf)
		return NULL;

	printf("%p\t%p\n", (char **)&buf[stride*2], *(char **)&buf[stride*2]);

	for(i = stride; i < len; i += stride) {
		*(char **)&(buf[i-stride]) = (char *)&(buf[i]);
	}
	*(char **)&(buf[i-stride]) = (char *)&(buf[0]);

	printf("%p\t%p\n", (char **)&buf[stride*2], *(char **)&buf[stride*2]);

	return buf;
}

char cooldown(char *buf) {
	if(buf)
		free(buf);
}

//#define	ONE	{ printf("%p\t%p\t\t", p, (char **)*p); p = (char **)*p; printf("%p\t%p\t\n", p, (char **)*p);}
#define ONE p = (char **)*p;
#define FIVE ONE ONE ONE ONE ONE 
#define TEN FIVE FIVE 
#define FIFTY TEN TEN TEN TEN TEN 
#define HUN	FIFTY FIFTY 

int main() {
	struct timespec st, ed;
	int buflen = 32*32*4096;
	int stride = 256;
	int loop = 10000;

	test_array();

	char *buf = prepare(buflen, stride);
	if(!buf) {
		printf("prepare error\n");
		exit(1);
	}

	int count = 100 * ( buflen / (stride * 100) + 1);
	
	char **p = (char **)&buf;
	int iterations = loop;
	clock_gettime(CLOCK_REALTIME, &st);
	while(iterations--)
		for(int i = 0; i < count; i++) {
			HUN
		}
	clock_gettime(CLOCK_REALTIME, &ed);
	long colapse = (ed.tv_sec - st.tv_sec) * 1000000000 + (ed.tv_nsec - st.tv_nsec);
	double latency = colapse * 1. / loop / count /100.;
	printf("colapsed: %ld\t latency: %lf\n", colapse, latency);
}

