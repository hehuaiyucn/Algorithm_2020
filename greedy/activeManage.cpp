#include <stdio.h>

// s:起始时间
// f:结束时间
// a:对应活动是否选入解集合
// 已经按结束时间非减序排列 1——>n
int activeManage(int *s, int *f, bool *a, int n)
{
    a[1] = 1;
    int j = 1;
    int count = 1;
    for (int i = 2; i <= n; i++)
    {
        if(s[i] >= f[j]){
            s[i] = 1;
            j = i;
            count++;
        }
        else
        {
            a[i] = 0;
        }
        
    }
    return count;   
}