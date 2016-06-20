// https://msdn.microsoft.com/zh-cn/library/jj203382.aspx
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <vector>
using namespace std;

int main(){
	const int i = 5;
//	i = 10;	// 不可改变
//	i ++;	// 不可改变
//
	const int size = 255;
	char cchar[size];


	char *mybuf = 0, *yourbuf;
	char *const aptr = mybuf;

	*aptr = 'a';		// valid: 可以改变const类型aptr指向的内容
//	aptr = yourbuf;		// error: 不能改变const类型aptr本身

}

