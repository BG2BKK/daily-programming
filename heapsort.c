#include <stdio.h>
#include <stdlib.h>

/* i为根节点,n为节点总数 */
void sift(int a[], int i, int n)
{
    int child, tmp;
    for (tmp = a[i]; n >= 2 * i; i = child)
    {
        /* i的左孩子为2*i,右孩子为2*i+1 */
        child = 2 * i;
 
        /* 让child指向孩子中较大的一个 */
        if (child != n && a[child + 1] > a[child])
        {
            child++;
        }
 
        /* 如果孩子节点大 */
        if (tmp < a[child])
        {
            /* 交换孩子节点和根节点 */
            a[i] = a[child];
        }
        else break;
    }
    /* 将根放在合适位置 */
    a[i] = tmp;
}
 
/* 对a[1...n]进行排序 */
void heapsort(int a[], int n)
{
    int i, tmp;
 
    /* 将a[1...n]建成大根堆 */
    for (i = n / 2; i >= 1; i--)
    {
        sift(a, i, n);
    }
 
    /* 进行n-1趟排序 */
    for (i = n; i >= 2; i--)
    {
        /* 交换堆顶元素和最后一个元素 */
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
 
        /* 将a[1...i-1]重建为堆 */
        sift(a, 1, i-1);
    }
}

void printarray(int a[], int n)
{
	int i = 0;
	printf("-----------array begin-------------\n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n-----------array end-------------\n");
}

int main()
{
	int a[] = {3,254,23,25,563,134,7543,14,78};
	int len = sizeof(a) / sizeof(int);
	printarray(a, len);
	heapsort(a, len);
	printarray(a, len);

}
