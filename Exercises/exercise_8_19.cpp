#include <stdio.h>

// ≈≈–ÚÀ„∑®
// upOrDownŒ™’Ê°™°™>…˝–Ú ∑Ò‘Ú£¨Ωµ–Ú
void sort(int *a, int n, bool upOrDown)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (upOrDown == true)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            else
            {
                if (a[i] < a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

int main()
{
    int a[] = {5,6,2,1,5,23,54};
    long min,max;
    for (int i = 0; i < 7; i++)
    {
        /* code */
    }
    
    sort(a,7,true);
}