#include<stdio.h>
#include "..\..\tool.h"
int SeqSearch(int *A,int queryNum,int size) {
	int i = 0;
	/*for (int j = size - 1; j > 0; j--) {
		swap(&A[j],&A[)
	}*/
	A[0] = queryNum;
	i = size;
	while (A[i] != queryNum) {
		i--;
	}
	return i;
}

int main() {
	int A[7] = { 1,54,21,2,123,45,87 };
	int query = 1;
	int xx = SeqSearch(A, query, 7);
	if (xx != 0) {
		printf("找到了 在%d处", xx);
	}
	else {
		printf("没有找到！");
	}
	return 0;
}