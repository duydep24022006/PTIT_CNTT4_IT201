#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr,int n);

int main()
{
    int n,k,*arr,valueIndex;
    printf("n = ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    inputArr(arr,n);

    printf("k = ");
    scanf("%d",&k);

    valueIndex=-1;
    for(int i=0;i<n;i++)
    {
        if(k==arr[i])
        {
            valueIndex=i;
        }
    }
    if(valueIndex==-1)
    {
        printf("khong tim thay phan tu\n");
    }else printf("%d \n",valueIndex);

    free(arr);
    return 0;
}

void inputArr(int *arr,int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
