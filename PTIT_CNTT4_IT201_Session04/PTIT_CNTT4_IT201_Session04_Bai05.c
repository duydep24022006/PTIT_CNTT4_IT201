#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr,int n);
int compareInt(const void *a, const void *b);
int binarySearch(int arr[],int n,int tager);


int main()
{
    int n,k,*arr,valueIndex;
    printf("n = ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    inputArr(arr,n);

    qsort(arr,n,sizeof(int),compareInt);
    printf("k = ");
    scanf("%d",&k);


    valueIndex=binarySearch(arr,n,k);
    if(valueIndex==-1)
    {
        printf("khong tim thay phan tu\n");
    }else printf("phan tu co trong mang");

    free(arr);
    return 0;
}

void inputArr(int *arr,int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}

int compareInt(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int binarySearch(int arr[],int n,int tager)
{
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if (arr[mid] == tager) return mid;
        else if (arr[mid]>tager) right=mid-1;
        else left=mid+1;
    }
    return -1;
}

