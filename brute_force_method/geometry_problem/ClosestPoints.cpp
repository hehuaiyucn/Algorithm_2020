#include <stdio.h>

// 最近对问题
double ClosestPoints(double p[][2], int *ind1, int *ind2, int num)
{
    int mind = 6535;
    double dis = 0;
    ind1 = 0;
    ind2 = 0;
    for (int i = 0; i <= num - 2; i++)
    {
        for (int j = i + 1; j <= num - 1; j++)
        {
            dis = (p[j][0] - p[i][0]) * (p[j][0] - p[i][0]) + (p[j][1] - p[i][1]) * (p[j][1] - p[i][1]);
            if (dis < mind)
            {
                mind = dis;
                *ind1 = i;
                *ind2 = j;
            }
        }
    }
    return mind;
}