#include<stdio.h>

// 计数排序
void countingSort1(int *A,int min, int max,int *B,int size){
    int C[] = {};
    for(int i = 0;i<size;i++){
        C[i] = 0;
    }
    for(int i = 0;i<size;i++){
        C[A[i] - min] = C[A[i]-min]+1;
    }
}