#include <stdio.h>
#include <stdlib.h>

void printfArr(int arr[],int n);
void quikSort(int arr[],int left,int right,int flag);



int main()
{
    int n ,*arr,k;
    printf("n = ");
    scanf("%d",&n);
    if(n<=0||n>1000) return 0;
    arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("mang truoc khi sap xep: ");
    printfArr(arr, n);
    printf("\n");
    quikSort(arr,0, n-1, 1);
    printf("mang sau khi sap xep: ");
    printfArr(arr, n);


    free(arr);
    return 0;
}

void printfArr(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void quikSort(int arr[],int left,int right,int flag)
{
    if (left>=right) return;
    int pivot = arr[(left+right)/2];
    int i=left, j=right;
    while (i<j)
    {
        if (flag==1)
        {
            while (arr[i]<pivot) i++;
            while (arr[j]>pivot) j--;
        }else
        {
            while (arr[i]>pivot) i++;
            while (arr[j]<pivot) j--;
        }
        if (i<=j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    quikSort(arr, left, j,flag);
    quikSort(arr, i, right,flag);
}