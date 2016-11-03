#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

void function() 
{ 
	unsigned int i,j; 
	double y; 
	for(i=0;i<1000;i++) 
		for(j=0;j<1000;j++) 
			y=sin((double)i); //耗时操作
} 

static int cmp( unsigned long p1, unsigned long p2) {
	return (p1 > p2)?(1):(p1<p2? -1:0);
}

double average(unsigned long *arr, int len) {
	double avg = 0;
	for(int i = 0; i < len; i++) {
		avg = avg *( i / (double)(i+1) ) + arr[i]/(double)(i+1);
	}
	return avg;
}

int main() {
	struct timespec st, ed;

	int count = 50;
	unsigned long *results = (unsigned long *)malloc(sizeof(unsigned long) * count);
	memset(results, 0, sizeof(unsigned long) * count);

	for(int i = 0; i < count; i++) {
		clock_gettime(CLOCK_REALTIME, &st);
		function();
		clock_gettime(CLOCK_REALTIME, &ed);
		results[i] = (ed.tv_sec - st.tv_sec) * 1000000000 + (ed.tv_nsec - st.tv_nsec);
	}

	for(int i = 0; i < count; i++) {
		printf("%ld\n", results[i]);
	}
	printf("avg: %lf\n", average(results, count));
}

