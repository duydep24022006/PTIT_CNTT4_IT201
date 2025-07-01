#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int n,int number);
void merge(int arr[],int left,int mid,int right);
void mergeSort(int arr[],int left, int right);


int main()
{
    int n ,*arr,k;
    printf("n = ");
    scanf("%d",&n);
    if(n<=0||n>1000) return 0;
    arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("k = ");
    scanf("%d",&k);
    mergeSort(arr,0, n-1);
    int resuch= binarySearch( arr, n,k);
    if (resuch!=-1) printf("vi tri thu %d",resuch);
    else printf("khong ton tai phan tu");
    free(arr);
    return 0;
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
void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid+1;

    int *L,*R;
    L=(int*)malloc(n1*sizeof(int));
    R=(int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++) L[i]=arr[left+i];
    for(int j=0;j<n2;j++) R[j]=arr[mid+1+j];
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
void mergeSort(int arr[],int left, int right)
{
    if(left>=right) return;
    int mid=left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}