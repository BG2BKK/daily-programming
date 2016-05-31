#include<iostream>
#include<functional>
#include<thread>
#include<future>
#include<utility>
#include<stdio.h>
#include<chrono>
#include<atomic>
#include<pthread.h>
using namespace std;
atomic<int> flag(0);//采用原子操作保护g_Flag的读写
void worker1(future<int> fut){//线程1
    printf("this is thread1\n");
    flag=1;
    fut.get();//线程1阻塞至线程2设置共享状态
    printf("thread1 exit\n");
}
void worker2(promise<int> prom){//线程2
    printf("this is thread2\n");//C++11的线程输出cout没有boost的好，还是会出现乱序，所以采用printf，有点不爽
    flag=2;
    prom.set_value(10);//线程2设置了共享状态后，线程1才会被唤醒
    printf("thread2 exit\n");
}
int main(){
    promise<int> prom;
    future<int> fut=prom.get_future();
    thread one(worker1,move(fut));//注意future和promise不允许拷贝，但是具备move语义
    thread two(worker2,move(prom));
    while(flag.load()==0);
    one.detach();
    two.detach();
    pthread_exit(NULL);//主线程到这里退出
    printf("main thread exit\n");
    return 0;
}
