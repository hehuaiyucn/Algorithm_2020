#include <stdio.h>

//部分子集和函数
int Sum(int x[], int w[], int k)
{
    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        sum = sum + x[i] * w[i];
    }
    return sum;
}

// 求解正整数集合w中第k+1到第n项和
int TailSum(int w[], int k, int n)
{
    int sum = 0;
    for (int i = k + 1; i <= n; i++)
    {
        sum = sum + w[i];
    }
    return sum;
}

void SubSum(int n,int w[],int M){
    int top = 0;
    int level;
    // for (int i = 1; i < = n; i++)
    // {
    //     x[i] = 0;
    // }
}