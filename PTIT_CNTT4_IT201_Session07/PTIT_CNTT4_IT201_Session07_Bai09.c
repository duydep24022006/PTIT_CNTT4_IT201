#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void renderArr (int arr[],int n);
void quikSort(int arr[],int left,int right,int flag);
int* addElement(int *arr, int *size, int value) ;
int main()
{
    int n,*arr,*arrEven=NULL,*arrOdd=NULL,flag,sizeEven=0,sizeOdd=0;
    printf("n = ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("so luong phan tu khong hop le");
        return 0;
    }
    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("before: ");
    renderArr (arr, n);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0) arrEven=addElement(arrEven, &sizeEven,arr[i]) ;
        else            arrOdd=addElement(arrOdd, &sizeOdd,arr[i]) ;
    }

    quikSort(arrEven,0,sizeEven, 1);
    quikSort(arrOdd,0,sizeOdd-1, 0);

    for(int i=0;i<sizeEven;i++) arr[i]=arrEven[i];
    for (int i = 0; i < sizeOdd; i++) arr[sizeEven + i] = arrOdd[i];

    printf(" after: ");
    renderArr (arr, n);

    free(arrOdd);
    free(arrEven);
    free(arr);
    return 0;

}
void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);
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
int* addElement(int *arr, int *size, int value) {

    int *newArr = realloc(arr, (*size + 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return arr;
    }

    newArr[*size] = value;
    (*size)++;
    return newArr;
}