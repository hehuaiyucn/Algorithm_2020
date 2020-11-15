#include<stdio.h>

int statMode(int *A,int n){
    int i = 0;
    int modestat = 0;
    int modeval;
    while (i<=n-1)
    {
        int curlength = 1;
        int curval = A[i];
        while((i+curlength <=n-1)&&(A[i+curlength]==curval)){
            curlength++;
        }
        if(curlength>modestat){
            modestat = curlength;
            modeval = curval;
        }
        i += curlength;
    }
    return modestat;
}