#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <signal.h>

void prot() {
	printf("page fault\n");
}

void setup_signal() {
	struct sigaction sa;

	sa.sa_handler = prot;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, 0);
	sigaction(SIGBUS, &sa, 0);
}

int main(char argc, char *argv[]) {
	if(argc < 2) {
		printf("./mmap filename\n");
		exit(1);
	}

	int fd = open(argv[1], 0);
	if(fd == -1) {
		printf("open file %s error for %s\n", argv[1], strerror(errno));
	}
	char *where = mmap(0, 4096, PROT_READ, MAP_SHARED, fd, 0);
	if(!where) {
		printf("mmap eror\n");
		exit(1);
	}

	setup_signal();

	*where = 1;
}
