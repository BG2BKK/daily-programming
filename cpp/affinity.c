#define _GNU_SOURCE

#include <stdio.h>
#include <sched.h>
int main(){
    int ret, i;
    cpu_set_t set;

    CPU_ZERO(&set);
    ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
    if(ret == -1)
    printf("调用失败!\n");
    for(i = 0; i < 10; i++){
    int cpu = CPU_ISSET(i, &set);
    printf("cpu=%i is %s\n", i, cpu?"set":"unset");
    }

    CPU_ZERO(&set);
    CPU_SET(0, &set);
    CPU_CLR(1, &set);
    ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
    if(ret == -1)
    printf("调用失败!\n");
    for(i = 0; i < 10; i++){
    int cpu = CPU_ISSET(i, &set);
    printf("cpu=%i is %s\n", i, cpu?"set":"unset");
    }
    return 0;
}
