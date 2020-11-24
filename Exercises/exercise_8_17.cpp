#include <stdio.h>
#include <stdlib.h>

/**
 * ���ŷ����������
 * ����n���˿�ͬʱ�ȴ�һ����񣬹˿�i��Ҫ�ķ���ʱ��Ϊti��1��i��n������s�������ṩ�������
 * Ӧ��ΰ���n���˿͵ķ���������ʹƽ���ȴ�ʱ��ﵽ��С��
 * ƽ���ȴ�ʱ����n���˿͵ȴ�����ʱ����ܺͳ���n��
 */

//�����㷨
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
    printf("�ƶ���%d\n", count);
}

// n���˿�
// s��λ��
int greedy(int a[], int n, int s)
{
    // ��j������� ��0��ʼ
    int j = 0;
    // �˿�i��j�����ȴ���ʱ��
    int *se = (int *)malloc(sizeof(int) * s);
    // ��j��������������й˿͵��ܵȴ�ʱ��
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
    // ti�˿ͷ���ʱ��
    int t[] = {2, 4, 3, 8, 5, 1, 34, 12};
    sort(t, 8);
    int time = greedy(t,8,3);
    printf("ƽ���ȴ�ʱ�䣺%d",time);
}
