#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

volatile int cnt = 0;

void alarm_handler() {
	printf("alarm : %d\n", cnt++);
}

int main() {
	signal(SIGALRM, alarm_handler);

	struct itimerval it;
	it.it_value.tv_sec = 6;
	it.it_value.tv_usec = 0;

	it.it_interval.tv_sec = 4;
	it.it_interval.tv_usec = 0;

	struct itimerval old;
	setitimer(ITIMER_REAL, &it, &old);
	while(1) {
		struct itimerval t;
		getitimer(ITIMER_REAL, &t);
		printf("%d\t%d\t%d\t%d\n", t.it_interval.tv_sec,t.it_interval.tv_usec,t.it_value.tv_sec,t.it_value.tv_usec);
		sleep(1);
	}
}
