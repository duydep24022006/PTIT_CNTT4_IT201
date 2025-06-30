#include <stdio.h>
#include <stdlib.h>

void renderArr (int arr[],int n);
void quikSort(int arr[],int left,int right);

int main()
{
    int n,*arr;
    printf("n = ");
    scanf("%d", &n);
    if (n<=0||n>1000)
    {
        printf("so luong phan tu khong hop le");
        return 0;
    }
    arr= (int *)malloc(n*sizeof(int));
    if (arr == NULL) return 0;

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("before: ");
    renderArr (arr, n);
    printf("\n");

    quikSort(arr,0,n-1);

    printf(" after: ");

    renderArr (arr, n);
    free(arr);
    return 0;

}

void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);

}

void quikSort(int arr[],int left,int right)
{
   if (left>=right) return;
    int pivot = arr[(left+right)/2];
    int i=left, j=right;
    while (i<j)
    {
        while (arr[i]<pivot) i++;
        while (arr[j]>pivot) j--;
        if (i<=j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

            i++;
            j--;
        }
    }
    quikSort(arr, left, j);
    quikSort(arr, i, right);
}
