#include <stdio.h>

void sort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int CaculateNUM(int m)
{
    int count = 0;
    while (m != 0)
    {
        m = m / 10;
        count++;
    }
    return count;
}

void SplitInteger(int *array, int n)
{
    int i = 0;
    while (n != 0)
    {
        array[i] = n % 10;
        n = n / 10;
        i++;
    }
}

// k 删除的字母个数
int greedy(int array[], int k, int n)
{
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        
    }
}

//
int deleteNum(int array[],int n){
    int i,j;

}
int main()
{
    int a;
    scanf("%d", &a);
    int n = CaculateNUM(a);
    printf("%d\n", n);
    int array[n];
    SplitInteger(array, a);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    sort(array, n);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}