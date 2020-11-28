#include <stdio.h>
#define MAXNUM 50000

int x[MAXNUM], y[MAXNUM];

bool cmp(int a, int b)
{
    return a > b;
}

//todo 
void sort(int *x,int *y){

}

//todo 
void sort(int *x,int *y,bool cmp){

}

//todo
void memset(int *x,int m,int n){

}

int m_min(int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] * x[i - 1] + 1;
        x[i - 1] = 0;
        sort(x, x + n);
    }
    return x[n - 1];
}

int m_max(int n)
{
    for (int i = 0; i < n; i++)
    {
        y[i] = y[i] * y[n - 1] + 1;
        y[i - 1] = 999999;
        sort(y, y + n, cmp);
    }
    return y[n - 1];
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int a, b, c, sum;
        int m = n;
        memset(x, 0, sizeof(x));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
            y[i] = x[i];
        }
        sort(x,x+n);
        int min = m_min(n);
        sort(y,y+n,cmp);
        int max = m_max(n);
        printf("%d",max-min);
    }
    return 0;
    
}