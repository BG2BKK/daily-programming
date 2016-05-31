
#define _GNU_SOURCE
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

	int
main(int argc, char *argv[])
{
	int ret, i;  
	struct timespec tp;  
	ret = sched_rr_get_interval(0, &tp);  
	if(ret == -1)  
		printf("sched_rr_get_interval error.\n");  
	printf("The time is %ds:%ldns.\n", (int)tp.tv_sec, tp.tv_nsec);  
	return 0;  
}

