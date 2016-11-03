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
		*(char **)&(buf[i-stride]) = (char *)&(buf[i]);
	}
	printf("%p\t%p\n", (char *)&buf[i-stride], (char *)&buf[0]);
	*(char **)&(buf[i-stride]) = (char *)&(buf[0]);
	return buf;
}

char cooldown(char *buf) {
	if(buf)
		free(buf);
}

#define ONE p = (char **)*p;
#define FIVE ONE ONE ONE ONE ONE 
#define TEN FIVE FIVE 
#define FIFTY TEN TEN TEN TEN TEN 
#define HUN	FIFTY FIFTY 

int main() {
	struct timespec st, ed;
	int buflen = 32768*1024;
	int stride = 32;
	int loop = 1000000;
	int iterations = loop;
	char *buf = prepare(buflen, stride);
	if(!buf) {
		printf("prepare error\n");
		exit(1);
	}

	int count = buflen / (stride * 100) + 1;
	
	char **p = &buf;
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

