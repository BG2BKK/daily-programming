
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
	* [堆排序](https://www.slyar.com/blog/slyar-heap-sort-c.html)

* [const_char_star.c](const_char_star.c)
	* const char * string 和 char const * string是等价的，都是在.data段分配的全局变量
	* const char * string 和 char * const string不等价，const与谁最近，那么谁就是常量
		* 前者是指string指向的内容是常量，不可改变
		* 后者是指指针string是常量，指针指向的内容不可变
	* [参考链接](http://stackoverflow.com/questions/4949254/const-char-const-versus-const-char)

* [exit_with_assembly.c](exit_with_assembly.c)
	* [Linux通过汇编直接触发 exit 系统调用](http://www.chongh.wiki/blog/2016/04/08/linux-syscalls/)
	* gcc exit_with_assembly.c -o exit_with_assembly.o
	* ./exit_with_assembly.o
	* echo $?
	* 42

* [insertionSortList.cpp](insertionSortList.cpp)
	* [单链表的插入排序](http://www.lintcode.com/zh-cn/problem/insertion-sort-list/)实现

* [deleteDuplicates.cpp](deleteDuplicates.cpp)
	* 删除冗余节点
	* 要注意的是41行和43行，在使用双重指针 \*\*p 的时候，我们在意的是将哪个对象的指针赋给它，\*p = pointer\_of\_object;
	* 因此在41行的时候取 p = &(node-\>next)取出node的next指向的地址，而不是在43行取新node的地址，那没有意义

* [const_in_cpp.cpp](const_in_cpp.cpp)
	* [const关键字在c++的作用](https://msdn.microsoft.com/zh-cn/library/07x6b05d.aspx)
	* const关键字在编译时定义常量

* [raiiExample.c](raiiExample.c)
	* c版的变量自动清除的宏，一种实现思路
	* [参考链接](https://www.ibm.com/developerworks/community/blogs/karsten/entry/raii_with_c_libraries?lang=en)
	* [参考链接2](https://github.com/psevon/exceptions-and-raii-in-c)

* [最长公共子序列](longest_common_subsequence.cpp)
	* [lintcode之最长公共子序列](http://www.lintcode.com/zh-cn/problem/longest-common-subsequence/)

* [最长公共子串](longest_common_substring.cpp)
	* [lintcode之最长公共子串](http://www.lintcode.com/zh-cn/problem/longest-common-subsequence/)

* [C和指针 练习](understanding_and_using_c_pointers/list.c)
	* [list.c](understanding_and_using_c_pointers/list.c)
	* [queue.c](understanding_and_using_c_pointers/queue.c)
	* [stack.c](understanding_and_using_c_pointers/stack.c)
	* 将链表和节点分开，链表存储链表头和链表尾，可以在O(1)时间实现插入和删除，在O(N)时间实现查找；这种方式可以大大提高扩展性，很容易的实现了队列和栈
	* 下一步进行CPP化，并提供线程安全版本

* [linux定时器 setitimer](setitimer.c)
	* setitimer在定时时间结束后发出信号

* [string.cpp](string.cpp)
	* 学习cpp的构造函数、拷贝构造函数、赋值构造函数和析构函数

* [singleton.cpp](singleton.cpp)
	* [cpp单例模式](http://www.zkt.name/dan-li-mo-shi-singleton-ji-c-shi-xian/)

* [AVL树统计词频](AVL/AVL.cpp)
	* [AVL树统计词频](http://www.cnblogs.com/daoluanxiaozi/archive/2012/04/26/2471256.html)

[Back to TOP](#cpp daily tips)
