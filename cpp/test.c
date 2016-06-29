#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 《C和指针》
//

char *globalHeader = "hello";
char globalArrayHeader[] = "hello";

void func(){
	int len = 10000000;
	int a[len];		// 太大，栈上分配不到那么多，崩溃
	printf("%p\n", a);
	printf("%d\n", sizeof(a));
}

void test_restrict();

int main()
{
	// 二维数组的大小
	int matrix[10][10];
	printf("%d\n", sizeof(matrix));	// 对于 char arr[10]; 定义的arr，它的类型就是char[10]类型；对于matrix来说，可以理解它是一个有10个成员的一维数组，每个成员是char[10]类型的，也是一维数组；所以matrix是二维数组

	// 5.1 字符串基础
	printf("%d\n", sizeof(char));	// sizeof(char)计算的是char类型的大小
	printf("%d\n", sizeof('a'));	// 'a'是一个字符常量，字符常量通常由一个字符组成，也可以包括多个字符，比如转义字符包括两个字符；在C中，字符常量类型是int型，所以长度是4字节
	printf("%d\n", sizeof('\t'));	
	char a = 'a';
	printf("%d\n", sizeof(a));		// char型变量长度是1个字节

//	char *tabHeader = "Sound";
//	*tabHeader = 'L';				// "Sound"是常量，不可以修改
//	printf("%s\n", tabHeader);
	
//	char header[] = "Media Player";	// 合法操作，编译后header直接指向了 字符串常量"Media Player"，对它求sizeof就是求"Media Player"
//	printf("%d\n", sizeof(header));
//	printf("%p\n", "Media Player");
//	printf("%p\n", header);

//	char header[];					// 非法操作，test.c:27:7: error: array size missing in ‘header’
	
//	char header[0];
//	printf("%d\n", sizeof(header));	// 合法操作，零长数组，占地址为0
//	printf("%p\n", header);			// 合法操作，零长数组，占地址为0
//	printf("%d\n", *header);		// 合法操作，零长数组，占地址为0

	char header[0];
//	header = "Media Player";		// 非法操作，"Media Player"是字符串常量，不能赋值给header数组；在编译时header和字符串常量类型不匹配，非法操作
	*header = "Media Player";		// 合法操作，好像属于未定义内容
//	printf("%s\n", *header);		// segment fault， 打印*(header + 1) 乃至 *(header + 100) 都没有问题，但是%s会打印直到\0，由于一直没有\0,所以该函数会访问直到越界 segment fault
//
	
	static char *staticHeader = "hello";
	char *localHeader = "hello";
	static char staticArrayHeader[] = "hello";
	char localArrayHeader[] = "hello";
	char *heapHeader = (char *)malloc(strlen("hello") + 1);
	strcpy(heapHeader, "hello");


	printf("globalHeader\t%p\n", globalHeader);				// 全局变量段，text段
	printf("globalArrayHeader\t%p\n", globalArrayHeader);	// 全局变量段，data段
	printf("localHeader\t%p\n", localHeader);				// 指向text段的hello
	printf("localArrayHeader\t%p\n", localArrayHeader);		// 栈分配的变量

	printf("staticHeader\t%p\n", staticHeader);				// 静态变量, text段
	printf("staticArrayHeader\t%p\n", staticArrayHeader);	// 静态变量，data段
	printf("heapHeader\t%p\n", heapHeader);					// 堆内存


	char z[0];
//
	char b[3];
//	b[0] = 4;
	*z = "hello";
//	*z = 9;
	printf("%x\n", *z);
	printf("%p\n", "hello");
//	printf("%d\n", b[0]);
	
	char str[100];
//	str = "hello";	
	*str = "hello";				// "hello"这个全局变量的地址赋给了str的首元素，汇编看来是将"hello"的地址赋给str[0],str的其他元素不受影响，编译器的行为就是这样的
	printf("%s\n", str);		// 因此以字符串打印str的话，首字符是"hello"地址的地位8bit，str[1]是初始化值\0，所以打印结束
	printf("%x\n", *str);		// 打印出str[0]的值，只有低位8bit有效，有效值与上一条一样
	printf("%p\n", "hello");	// 打印出"hello"首地址，发现一样

	printf("%p\n", str);	
	printf("%p\n", &str);		// 对数组取地址，还是它自己
	printf("%p\n", &str[0]);	// 对数组进行引用没有意义，还是它自己
	printf("%p\n", ((char *)str));		// 

//	printf("%p\n", &((char *)str));		// 非法操作，左值指的是可以取地址的变量, &操作符要求操作数是左值，而显然((char *)str)不是，https://www.zhihu.com/question/26203703
//	str = "hello";						// 也可以解释为什么直接赋值数组是错的 char str[10]; str = "hello";，另一个原因是两者类型不匹配(待问)
//
	char error[] = "ERROR:";
	char errorMessage[] = "Not enough memory";
	strcat(error, errorMessage);
	printf("%s\n", error);
	printf("%s\n", errorMessage);


	int intary[] = {1, 2, 3, 4, 5};
	printf("%p\n", intary);
	printf("%p\n", &intary);	// 对一个地址取地址的操作，实际上是没有什么意义的，所以二者值一样

	int *p1 = intary;
	test_restrict(sizeof(intary)/sizeof(int), p1, intary);
	test_restrict(sizeof(intary)/sizeof(int), intary, intary);	// restrict 关键字的优化，c99引入，但是并未看到效果 http://blog.csdn.net/lovekatherine/article/details/1891806
}

void test_restrict(int size, int * restrict  p1, int *restrict  p2){
	printf("%d\n", sizeof(p1));
	printf("%d\n", sizeof(p2));
	for(int i=0; i<size;i++){
		p1[i] = p1[i] + p2[i];
	}
}
