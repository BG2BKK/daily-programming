#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

volatile int cond = 0;
int semid;
struct sembuf sem[2];

void func(int n)
{

//	printf("ppid = %d, getpid = %d\n", getppid(), getpid());

	int i = 0, j = 0;
	for(j=0; j<5; j++){

		sem[1].sem_num = 1;
		sem[1].sem_op = -1;
		sem[1].sem_flg = 0;
		semop(semid, &sem[1], 1);

		printf("\n----------------------------------\n");
		printf("child: ");
		for(i=0; i < 10; i++ )
			printf("%d\t", i);
		printf("\n");

		sem[0].sem_num = 0;
		sem[0].sem_op = 1;
		sem[0].sem_flg = 0;
		semop(semid, &sem[0], 1);
	}
}

int main()
{
	semid = semget(IPC_PRIVATE, 2, 0666| IPC_CREAT);
	if(semid < 0){
		printf("semget error for %s", strerror(errno));
		exit(1);
	}

	pthread_t tid;
	int s = pthread_create(&tid, NULL, func, getpid());
	if(s != 0){
		printf("pthread_create error for %s", strerror(errno));
		exit(1);
	}

	int i = 0, j = 0;
	for(j=0; j < 5; j++){

		sem[0].sem_num = 0;
		sem[0].sem_op = -1;
		sem[0].sem_flg = 0;
		sem[1].sem_num = 1;
		sem[1].sem_op = 1;
		sem[1].sem_flg = 0;

		semop(semid, &sem[1], 1);
		semop(semid, &sem[0], 1);

		printf("master: ");
		for(i=0; i < 100; i++ )
			printf("%d\t", i);
		printf("\n");
		printf("==================================\n");

		sem[1].sem_num = 1;
		sem[1].sem_op = 1;
		sem[1].sem_flg = 0;
	}

	s = pthread_join(tid, NULL);
	if(s != 0){
		printf("pthread_join error for %s", strerror(errno));
		exit(1);
	}
}
