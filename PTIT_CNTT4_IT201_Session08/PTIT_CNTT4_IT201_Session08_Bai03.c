#include <stdio.h>
#include <stdlib.h>



void printfArr(int arr[],int n);
void bubbleSort(int arr[],int n);


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
    bubbleSort(arr,n);
    printf("mang sau khi sap xep: ");
    printfArr(arr, n);

    free(arr);
    return 0;
}

void printfArr(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j+1]=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=arr[j];
                flag=1;
            }
        }
        if(flag==1) return;
    }
}

