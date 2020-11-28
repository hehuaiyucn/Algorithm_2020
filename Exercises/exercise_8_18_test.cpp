#include <stdio.h>
#define MAX 10000000
int num[MAX];

int deleteNum(int a[], int n)
{
    int i, j;
    for (i = n - 1, j = i - 1; i > 0; i--)
    {
        printf("\na[%d]=%d,a[%d]=%d", i, a[i], j, a[j]);
        if (a[i] > a[j])
        {
            printf("\n%d\n", i);
            return i;
        }
        else
            j--;
    }
    return i;
}

int main(int argc, const char *argv[])
{
    // insert code here...
    //printf("Hello, World!\n");

    int i, n, k, j, flag[1000];
    long a = 76867329;
    //
    k = 4;
    i = 0;
    while (a)
    {
        num[i++] = a % 10;
        a = a / 10;
    }
    n = i;
    printf("\n%d\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\nn=%d", n);

    for (i = 0; i < k; i++)
    {
        flag[i] = deleteNum(num, n);
        for (j = flag[i]; j < n - 1; j++)
        {
            num[j] = num[j + 1];
            printf("num[]:");
            for (i = 0; i < n; i++)
            {
                printf("%d ", num[i]);
            }
        }
        n--;
    }
    //printf("\nn=%d\n",n);
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}