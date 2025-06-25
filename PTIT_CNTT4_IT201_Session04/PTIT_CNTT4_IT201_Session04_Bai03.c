#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr,int n);

int main()
{
    int n,*arr,minIndex,minValiue;
    printf("n = ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    inputArr(arr,n);

    minValiue=arr[0];
    minIndex=0;
    for(int i=0;i<n;i++)
    {
        if(minValiue>arr[i])
        {
            minValiue=arr[i];
            minIndex=i;
        }
    }
    printf("%d \n",minIndex);
    free(arr);
    return 0;
}

void inputArr(int *arr,int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
