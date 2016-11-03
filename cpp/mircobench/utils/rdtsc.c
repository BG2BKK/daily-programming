#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define cycles_t unsigned long long

#define rdtsc(low,high) __asm__ \
	 __volatile__("rdtsc" : "=a" (low), "=d" (high))

unsigned long long get_cycles()
{
	unsigned low, high;
	unsigned long long val;
	rdtsc(low,high);
	val = high;
	val = (val << 32) | low; //将 low 和 high 合成一个 64 位值
	return val;
}

int main()
{
	cycles_t c1, c2;

	for(;;)
	{
		c1 = get_cycles(); 
		sleep(1);
		c2 = get_cycles();
		printf("begin: %ld\n", c1);
		printf("end: %ld\n", c2);
	}
}
