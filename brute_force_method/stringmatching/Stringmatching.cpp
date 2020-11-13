#include<stdio.h>

int BruteforceIndex(int* w, int* m,int w_size,int m_size) {
	for(int i = 0; i < w_size - m_size; i++) {
		int j = 0;
		while ((j < m_size) && w[i + j] == m[j]) {
			j++;
			if (j == m_size)
				return i;
		}
	}
	return -1; //查询失败
}

// int main(){
// 	printf("程序1");
// 	return 0;
// }
