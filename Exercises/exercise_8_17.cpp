#include <stdio.h>
#include <stdlib.h>

/**
 * 最优服务次序问题
 * 设有n个顾客同时等待一项服务，顾客i需要的服务时间为ti，1≤i≤n，共有s处可以提供此项服务。
 * 应如何安排n个顾客的服务次序才能使平均等待时间达到最小？
 * 平均等待时间是n个顾客等待服务时间的总和除以n。
 */

//排序算法
void sort(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                count++;
            }
        }
    }
    printf("移动了%d\n", count);
}

// n个顾客
// s个位置
int greedy(int a[], int n, int s)
{
    // 第j处服务点 从0开始
    int j = 0;
    // 顾客i在j处所等待的时间
    int *se = (int *)malloc(sizeof(int) * s);
    // 在j处服务点服务的所有顾客的总等待时间
    int *sc = (int *)malloc(sizeof(int) * s);

    for (int i = 0; i < s; i++)
    {
        se[i] = 0;
        sc[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        se[j] += a[i];
        sc[j] += se[j];
        j++;
        if (j == s)
        {
            j = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < s; i++)
    {
        sum+=sc[i];
    }
    return sum/n;
}

int main()
{
    // ti顾客服务时间
    int t[] = {2, 4, 3, 8, 5, 1, 34, 12};
    sort(t, 8);
    int time = greedy(t,8,3);
    printf("平均等待时间：%d",time);
}
