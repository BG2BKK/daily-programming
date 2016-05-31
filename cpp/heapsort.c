#include <stdio.h>
#include <stdlib.h>

// 建造最小堆
void MinHeapFixdown(int a[], int i, int n)
{
	int temp = a[i];		// 保存活动值，直到下沉到合适的位置
	int j = 2 * i + 1;		// 节点的左孩子
	while(j < n)
	{
		if(j + 1 < n && a[j+1] < a[j])
			j++;			// 如果有右孩子，选出孩子里最小的
		if(a[j] > temp)		// 如果比最小的孩子还小，说明这个位置的节点符合最小堆条件，
			break;			// 跳出后可以被赋值
		
		a[i] = a[j];		// i节点下沉
		i = j;				// 下沉到孩子的位置
		j = 2*i + 1;		// 继续比较
	}
	a[i] = temp;
}

void MakeMinHeap(int a[], int len)
{
	int i = len / 2 - 1;
	for(; i >= 0; i--){
		MinHeapFixdown(a, i, len);		// 调整每一个非叶子节点，使其符合最小堆定义
	}
}

//排序最小堆

void MinHeapSortTodescend(int a[], int n)
{
	int i = n - 1;
	int temp;
	for (; i > 0; i --)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		MinHeapFixdown(a, 0, i);		// 最小堆的定义是父节点比每个孩子都小，但是不要求其与其他节点的孩子比较
										// 因此在对最小堆排序时，每次先抽出最小的，即堆顶元素，可以将它放在最后
										// 然后重新调整，剩下的堆元素组成最小堆，重复取出对顶元素，即可完成排序
	}
}

void printarray(int a[], int n)
{
	int i = 0;
	printf("=============array begin============\n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n\n--------------array end-------------\n\n");
}

int main()
{
	int a[] = {3,254,23,25,563,134,7543,14,78,99};
	int len = sizeof(a) / sizeof(int);
	printarray(a, len);

	MakeMinHeap(a, len);
	MinHeapSortTodescend(a, len);

	printarray(a, len);

}
