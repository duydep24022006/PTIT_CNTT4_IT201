#include <stdio.h>
#include <stdlib.h>


void inputArr(int *arr,int n);
int linearSearch(int arr[],int n,int key);

int main()
{
    int *arr,n,valiue,k;
    printf("n=");
    scanf("%d",&n);
    if (n<0||n>1000) return 0;
    arr=(int *)malloc(n*sizeof(int));

    inputArr(arr,n);
    printf("k=");
    scanf("%d",&k);

    valiue=linearSearch(arr,n,k);
    if (valiue==-1)
    {
        printf("khong tim thay phan tu\n");

    }else
    {
        printf("%d",valiue);
    }
    free(arr);
    return 0;
}

void inputArr(int *arr,int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}

int linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

