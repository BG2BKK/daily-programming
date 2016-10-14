#include "stdio.h"


/*
 *
//i++实现代码为：                                    
int operator++(int)                                  
{
	int temp = *this;                                     
	++*this;                                             
	return temp;                                    
}//返回一个int型的对象本身
++i的实现代码：

// ++i实现代码为：
int& operator++()
{
	*this += 1;
	return *this;
}//返回一个int型的对象引用

*/

int main()
{

	int i = 1;
	printf("%d,%d\n", ++i, ++i);    //3,3
	printf("%d,%d\n", ++i, i++);    //5,3
	printf("%d,%d\n", i++, i++);    //6,5
	printf("%d,%d\n", i++, ++i);    //8,9
	return 0;
}
