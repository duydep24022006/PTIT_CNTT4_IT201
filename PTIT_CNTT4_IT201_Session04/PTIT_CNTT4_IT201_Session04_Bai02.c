#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr,int n);

int main()
{
    int n,*arr,maxFirst,maxSecond;
    printf("n = ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    inputArr(arr,n);
    maxFirst=arr[0];
    maxSecond=maxFirst;
    for(int i=0;i<n;i++)
    {
        if(maxFirst<arr[i])
        {
            maxSecond=maxFirst;
            maxFirst=arr[i];

        }
    }
    printf("%d",maxSecond);
    free(arr);
    return 0;
}

void inputArr(int *arr,int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
