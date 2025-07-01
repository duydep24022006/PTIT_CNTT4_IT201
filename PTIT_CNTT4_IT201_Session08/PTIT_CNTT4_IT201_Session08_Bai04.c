#include <stdio.h>
#include <stdlib.h>



void printfArr(int arr[],int n);
void selectionSort(int arr[],int n);


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
    selectionSort(arr,n);
    printf("mang sau khi sap xep: ");
    printfArr(arr, n);

    free(arr);
    return 0;
}

void printfArr(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

