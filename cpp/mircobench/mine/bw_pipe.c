
#include "bench.h"

#define TARGETLEN 4294967296

#define BUFLEN 10*1024*1024

typedef struct p_state_t {
	int fd[2];
	char *buf;
	int childpid;
	bench_f prepare;
	bench_f bench;
	bench_f cooldown;

} pipe_state_t;

typedef struct bw_result {
	unsigned long volume;
	unsigned long elapse;
} bw_result_t;

void writer(int fd, char *buf, int buflen) {
	int n = 0;
	while(1) {
		if((n = write(fd, buf + n, buflen - n)) < 0) {
			perror("write pipe error");
			exit(1);
		}
	}
}

void reader(int fd, char *buf, int buflen) {
	unsigned long read_len = 0;
	int n = 0;
	while(1) {
		if((n = read(fd, buf, buflen)) < 0) {
			perror("read pipe error");
			exit(1);
		}
		read_len += n;
		if(read_len >= TARGETLEN) {
			break;
		}
	}
}

void do_bw_pipe_prepare(pipe_state_t *state) {
	int pid, ret;
	ret = pipe(state->fd);
	if(ret != 0) {
		perror("pipe create error");
		exit(1);
	}
	switch((pid = fork())) {
		case 0:
			// child 
			state->buf = (char *)malloc(sizeof(char) * BUFLEN);
			if(!state->buf) {
				perror("child malloc buf error");
				exit(1);
			}
			close(state->fd[0]);
			writer(state->fd[1], state->buf, BUFLEN);
			break;
		case -1:
			perror("create child process error");
			break;
		default:
			break;
	}
	// parent
	state->childpid = pid;
	state->buf = (char *)malloc(sizeof(char) * BUFLEN);
	if(!state->buf) {
		perror("parent malloc buf error");
		exit(1);
	}
	close(state->fd[1]);
}

void do_bench_bandwidth_pipe(pipe_state_t *state) {
	reader(state->fd[0], state->buf, BUFLEN);
}

void do_bw_pipe_cooldown(pipe_state_t *state) {
	if(state->childpid > 0) {
		kill(state->childpid, SIGKILL);
		waitpid(state->childpid, NULL, 0);
	}
	close(state->fd[0]);
	if(state->buf) {
		free(state->buf);
	}
}

int cmp_bw_result(const void *p1, const void *p2) {
	bw_result_t *r1 = (bw_result_t *)p1;
	bw_result_t *r2 = (bw_result_t *)p2;
	return (r1->elapse > r2->elapse)? 1 : ((r1->elapse < r2->elapse)? -1 : 0);
}

void save_bw_result(bw_result_t *ret, int index, unsigned long elapse, unsigned long len) {
	ret[index].elapse = elapse;
	ret[index].volume = len;
}

double get_bandwidth(unsigned long elapse, unsigned long volume) {
	if(elapse <= 0)
		return -1;
	return volume * 1. / (elapse / 1000000.0) / (1024*1024);
}

double get_bw_pipe(pipe_state_t *state) {
	struct timespec st, ed;
	unsigned long elapse;
	int loopcnt, loop = 20;
	int index = loop >> 2;

	bw_result_t *r = (bw_result_t *)malloc(sizeof(bw_result_t) * loop);
	loopcnt = loop;

	while(loopcnt --) {

		if(state->prepare)
			state->prepare(state);

		clock_gettime(CLOCK_REALTIME, &st);
		state->bench(state);
		clock_gettime(CLOCK_REALTIME, &ed);

		elapse = get_total_us(&st, &ed);
		save_bw_result(r, loopcnt, elapse, TARGETLEN);

		if(state->cooldown)
			state->cooldown(state);
	}

	qsort(r, loop, sizeof(bw_result_t ), cmp_bw_result);
	double bandwidth = get_bandwidth(r[index].elapse, r[index].volume);
	return bandwidth;
}

void bench_bandwidth_pipe() {
	printf("\nbenchmark on Bandwidth of Pipe\n");
	printf("-------------------------------------\n");

	pipe_state_t state;
	memset(&state, 0, sizeof(pipe_state_t));
	state.prepare = do_bw_pipe_prepare;
	state.bench = do_bench_bandwidth_pipe;;
	state.cooldown = do_bw_pipe_cooldown;
	printf("bandwidth of pipe: %lf MB/s\n", get_bw_pipe(&state));

	printf("\n--------------end--------------------\n");
}
