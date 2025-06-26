
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int left, int right, int x) ;

int main()
{
    int n,*arr,target,flag;
    printf("n = ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("target = ");
    scanf("%d",&target);
    flag=binarySearch(arr, 0, n-1, target);
    if(flag!=-1) printf("phan tu co trong mang");
    else printf("phan tu khong co trong mang");
    free(arr);
    return 0;
}

int binarySearch(int arr[], int left, int right, int x) {
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binarySearch(arr, left, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, right, x);
}