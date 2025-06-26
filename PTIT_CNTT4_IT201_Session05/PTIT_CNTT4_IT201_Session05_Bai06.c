#include <stdio.h>
#include <stdlib.h>

int sumArr(int arr[],int n);

int main()
{
    int n,*arr,sum;
    printf("n= ");
    scanf("%d",&n);
    if(n<=0) return 0;
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sum=sumArr(arr, n);
    printf("%d\n",sum);
}

int sumArr(int arr[],int n)
{
    if (n==0) return n;
    return arr[n-1]+sumArr(arr,n-1);
}
