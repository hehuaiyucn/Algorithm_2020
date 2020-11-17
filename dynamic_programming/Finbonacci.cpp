#include<stdio.h>

// 斐波那契数列：动态规划-备忘录方法
int topDownFibonacci(int n, int *f){
    // 初始化
    for (int i = 0; i < n; i++)
    {
        f[i] = -1;
    }
    f[0]=0;
    f[1]=1;
    return fibonacci(n,f);
}

int fibonacci(int n,int *f){
    if(f[n] != -1){
        return f[n];
    }
    int u = fibonacci(n-1,f) + fibonacci(n-2,f);
    f[n] = u;
    return u;
}