#include<stdio.h>

// 交换两个整数的位置
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// 打印数组
void print_array(int A[], int size){
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
