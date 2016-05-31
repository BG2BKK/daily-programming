
cpp daily tips
====================

* [affinity.c](affinity.c)
	* [设置进程的CPU亲和性](http://blog.csdn.net/dlutbrucezhang/article/details/9074891)

* [cpu_time_slice.c](cpu_time_slice.c)
	* [获取进程的cpu时间片长度](http://blog.csdn.net/dlutbrucezhang/article/details/9074891)
	* 这个函数将SCHED_RR调度策略下进程的时间片传回

* [server.c](server.c)
* [client.c](client.c)
	* 测试TCP_FAST_OPEN特性，可以通过tcpdump抓包进行分析

* [context.c](context.c)
	* 使用ucontext_t进行context切换，实现c语言协程

* [interview.c](interview.c)
	* int类型和long类型在32位时都是4byte大小，而long类型在64位时是8byte大小

* [man_cpu_zero.c](man_cpu_zero.c)
	* man CPU_ZERO中的示例代码

* [pthread.c](pthread.c)
	* 设置linux thread的栈大小等属性，操作thread

* [sizeof_c.c](sizeof_c.c)
	* 本质上是实际测试得到***结构体中的零长数组***，它不占内存，不会计入大小；
	* 零长数组作为不完全类型，采用sizeof是不能得到长度的，sizeof是一个运算符，而不是函数；这是一个编译时的操作。
	* http://blog.csdn.net/w57w57w57/article/details/6626840

* [sizeof_cpp.cpp](sizeof_cpp.cpp)
	* sizeof_c.c 的cpp版本

* [sa_restart.c](sa_restart.c)
	* 系统调用比如read被打断后，如果之前设置了SA_RESTART的话，将会重启系统调用
	* 效果待检验

* [heapsort.c](heapsort.c)
	* 堆排序

[Back to TOP](#cpp daily tips)
