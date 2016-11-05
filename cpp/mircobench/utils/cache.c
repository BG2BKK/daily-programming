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
	*(char **)&(buf[i-stride]) = (char *)&(buf[0]);

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

void do_cache(int buflen, int stride) {

	struct timespec st, ed;
	int loop = 10000;

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

	cooldown(buf);

}

int main() {
	int maxlen = 1 << 23;
	int buflen = 64 * 1024;
	int stride = 64;

	for(buflen = 4*1024; buflen <= maxlen; buflen = buflen << 1) {
		printf("buflen = %d\tstride = %d\n", buflen, stride);
		do_cache(buflen, stride);
		printf("===================\n\n");
	}


}

