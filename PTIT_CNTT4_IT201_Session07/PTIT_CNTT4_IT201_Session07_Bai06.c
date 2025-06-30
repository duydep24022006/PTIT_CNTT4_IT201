#include <stdio.h>
#include <stdlib.h>

void renderArr (int arr[],int n);
void mergeSort(int arr[],int left,int right);
void merge(int arr[],int left,int mid,int right);


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

    mergeSort(arr,0,n-1);

    printf(" after: ");

    renderArr (arr, n);
    free(arr);
    return 0;

}

void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);

}

void mergeSort(int arr[],int left,int right)
{
    if (left>=right) return;

    int mid=left+ (right-left)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);
}

void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int* L=malloc(n1* sizeof(int));
    int* R=malloc(n2* sizeof(int));

    for (int i = 0; i < n1; i++) L[i]=arr[left+i];
    for (int j = 0; j < n2; j++) R[j]=arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];

    free(L);
    free(R);
}
