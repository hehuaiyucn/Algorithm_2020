#include<stdio.h>
#include"tool.h"

// 选择排序 
// 时间复杂度 O(n^2)
// 不稳定
void SelectionSort(int A[],int n) {
	;
	for (int i = 0; i <= n - 2; i++) {
		int min = i;
		for (int j = i + 1; j <= n - 1; j++) {
			if (A[j] < A[min]) {
				min = j;
			}	
		}
		swap(&A[i], &A[min]);
//		print_array(A, 7);
	}
}

// 冒泡排序
// 时间复杂度 O(n^2)
// 稳定
void BubbleSort(int A[],int size) {
	for (int i = 0; i <= size - 2; i++) {
		for (int j = 0; j <= size - 2 - i; j++) {
			if (A[j + 1] < A[j]) {
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}

//int main() {
//	int A[7] = { 1,54,21,2,123,45,87 };
//	int n = sizeof(A) / sizeof(A[0]);
////	SelectionSort(A,n);
//	BubbleSort(A, n);
//	print_array(A, n);
//	return 0;
//}