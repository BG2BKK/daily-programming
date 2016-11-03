#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

/*
   int main() {
   struct timeval st, ed;
   int loop = 300;
   int count = 3000000;
   for(int i = 0; i < loop; i ++) {
   int t = gettimeofday(&st, NULL);
   for(int i = 0; i < count; i++) {
   int t = gettimeofday(&ed, NULL);
   }
   double sec = ed.tv_sec - st.tv_sec;
   double usecs = sec * 1000000 + ed.tv_usec - st.tv_usec;
   printf("%lf\n", usecs);
   }
   }
   */

void function() 
{ 
	unsigned int i,j; 
	double y; 
	for(i=0;i<1000;i++) 
		for(j=0;j<1000;j++) 
			y=sin((double)i); //耗时操作
} 

main() 
{ 
	struct timeval tpstart,tpend; 
	float timeuse; 

	gettimeofday(&tpstart,NULL); //记录开始时间戳
	function(); 
	gettimeofday(&tpend,NULL); //记录结束时间戳
	timeuse = 1000000*(tpend.tv_sec-tpstart.tv_sec)+ 
		tpend.tv_usec-tpstart.tv_usec; //计算差值
	timeuse /= 1000000; 
	printf("Used Time:%f\n",timeuse); 
	exit(0); 
}

