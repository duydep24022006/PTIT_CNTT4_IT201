#include <stdio.h>
#include <stdlib.h>



void printfArr(int arr[],int n);
void insertionSort(int arr[],int n);
int linearSearch(int arr[],int n,int number);
int binarySearch(int arr[],int n,int number);



int main()
{
    int n ,*arr,k,firstIndex,secondIndex ;
    printf("n = ");
    scanf("%d",&n);
    if(n<=0||n>1000) return 0;
    arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("mang truoc khi sap xep: ");
    printfArr(arr, n);
    printf("\n");
    insertionSort(arr,n);
    printf("mang sau khi sap xep: ");
    printfArr(arr, n);
    printf("\n k = ");
    scanf("%d",&k);
    firstIndex=linearSearch(arr, n, k);
    secondIndex=binarySearch(arr, n, k);
    if (firstIndex!=1&&secondIndex!=1)
    {
        printf("gia tri tra ve cua tim kiem tuyen tinh la:%d",firstIndex);
        printf("\n");
        printf("gia tri tra ve cua tim kiem nhi phan la:%d",secondIndex);
    }else printf("khong ton tai phan tu");

    free(arr);
    return 0;
}

void printfArr(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }
}
int linearSearch(int arr[],int n,int number)
{
    for (int i=0;i<n;i++)
    {
        if (number==arr[i]) return i;
    }
    return -1;
}

int binarySearch(int arr[],int n,int number)
{
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(arr[mid]==number) return mid;
        else if(arr[mid]<number) left=mid+1;
        else right=mid-1;
    }
    return -1;
}
