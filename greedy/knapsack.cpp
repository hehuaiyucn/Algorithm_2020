#include <stdio.h>

// 背包问题
// 背包容量 C
// n个物品
// x:问题的解空间
float knapsack(float *w, float *v, float *x, float C, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    int i = 1;
    int total = 0;

    while (w[i] < C)
    {
        x[i] = 1;
        total = total + v[i];
        C = C - w[i];
        i++;
    }
    x[i] = C / w[i];
    total = total + x[i] * v[i];
    return total;
}