#include <stdio.h>
#define MAX 10000000
int num[MAX];

//返回删除的位置
int deleteNum(int a[],int n)
{
    int i,j;
    for(i=n-1,j=i-1;i>0;i--)
    {
        //printf("\n%d %d",a[i],a[j]);
        if(a[i]>a[j])
        {
            //printf("\n%d\n",i);
            return i;
        }
        else j--;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    
    int i,n,k,j,flag[1000];
    long a;
    scanf("%ld",&a);
    scanf("%d",&k);
    i=0;
    while(a)
    {
        num[i++]=a%10;
        a=a/10;
    }
    n=i;
    /*printf("\n%d\n",n);
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    //printf("\nn=%d",n);
    */
    for(i=0;i<k;i++)
    {
        flag[i]=deleteNum(num,n);
         //删除操作
        for(j=flag[i];j<n-1;j++)
        {
            num[j]=num[j+1];
        }
        n--;
    }
    //printf("\nn=%d\n",n);
    for(i=n-1;i>=0;i--)
    {
        printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}