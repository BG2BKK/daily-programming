#include <stdio.h>
#include <stdlib.h>

void MinHeapFixdown(int a[], int i, int n)
{
	int temp = a[i];
	int j = 2 * i + 1;
	while(j < n)
	{
		if(j + 1 < n && a[j+1] < a[j])
			j++;
		if(a[j] > temp)
			break;
		a[i] = a[j];
		i = j;
		j = 2*i + 1;		
	}
	a[i] = temp;
}

void MakeMinHeap(int a[], int len)
{
	int i = len / 2 - 1;
	for(; i >= 0; i--){
		MinHeapFixdown(a, i, len);
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

		MinHeapFixdown(a, 0, i);
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
