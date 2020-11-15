#include <stdio.h>

// 交换两个整数的位置
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// 打印数组
void print_array(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

//检验数组中元素的唯一性
bool uniqueness(int *A, int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (A[i] == A[j])
			{
				return false;
			}
		}
	}
	return true;
}

//检验已排序数组中元素的唯一性
bool sortUniqueness(int *A, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		if (A[i] == A[i + 1])
		{
			return false;
		}
	}
	return true;
}
