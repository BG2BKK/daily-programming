#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

char *prepare(unsigned long len, int stride) {
	int i;
	char *buf = (char *)malloc(sizeof(char) * len);
	if(!buf)
		return NULL;
	for(i = stride; i < len; i += stride) {
		*(long **)&(buf[i-stride]) = (long *)&(buf[i]);
	}
	printf("%p\t%p\n", (char *)&buf[i-stride], (char *)&buf[0]);
	*(long **)&(buf[i-stride]) = (long *)&(buf[0]);
	return (long *)buf;
}

char cooldown(char *buf) {
	if(buf)
		free(buf);
}

//#define	ONE	{ printf("%p\t%p\t\t", p, (char **)*p); p = (char **)*p; printf("%p\t%p\t\n", p, (char **)*p);}
#define ONE p = (long **)*p;
#define FIVE ONE ONE ONE ONE ONE 
#define TEN FIVE FIVE 
#define FIFTY TEN TEN TEN TEN TEN 
#define HUN	FIFTY FIFTY 

int main() {
	struct timespec st, ed;
	int buflen = 32*1024*32;
	int stride = 1024;
	int loop = 1000000;
	int iterations = loop;
	long *buf = prepare(buflen, stride);
	if(!buf) {
		printf("prepare error\n");
		exit(1);
	}

	int count = buflen / (stride * 100) + 1;
	
	long **p = (long **)&buf;
	clock_gettime(CLOCK_REALTIME, &st);
	while(iterations--)
		for(int i = 0; i < count; i++) {
			HUN
		}
	clock_gettime(CLOCK_REALTIME, &ed);
	long colapse = (ed.tv_sec - st.tv_sec) * 1000000000 + (ed.tv_nsec - st.tv_nsec);
	double latency = colapse * 1. / loop / count / 100.;
	printf("colapsed: %ld\t latency: %lf\n", colapse, latency);
}

