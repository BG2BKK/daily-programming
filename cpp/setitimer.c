#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

volatile int cnt = 0;

void alarm_handler() {
	printf("alarm : %d\n", cnt++);
}

/*
 * 对于itimerval结构体中的it_interval和it_value来说，it_value表示减少的时间，每当它减小为0的时候发出信号，然后用it_interval填充；随后重新开始递减计时。
 * 当二者初始化为4s和6s时，首先使用it_value中的6s计时；然后发出信号；然后按照4s开始计时
 */

int main() {
	signal(SIGALRM, alarm_handler);

	struct itimerval it;

	it.it_interval.tv_sec = 4;
	it.it_interval.tv_usec = 0;

	it.it_value.tv_sec = 6;
	it.it_value.tv_usec = 0;

	struct itimerval old;
	setitimer(ITIMER_REAL, &it, &old);
	while(1) {
		struct itimerval t;
		getitimer(ITIMER_REAL, &t);
		printf("%d\t%d\t%d\t%d\n", t.it_interval.tv_sec,t.it_interval.tv_usec,t.it_value.tv_sec,t.it_value.tv_usec);
		sleep(1);
	}
}
