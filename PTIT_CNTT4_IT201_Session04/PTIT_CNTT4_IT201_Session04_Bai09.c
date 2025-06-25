
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target);
int main()
{
    int n,*arr,target,flag;
    printf("n = ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("target = ");
    scanf("%d",&target);
    flag=binarySearch(arr,n, target);
    if(flag!=-1) printf("phan tu co trong mang");
    else printf("phan tu khong co trong mang");
    free(arr);
    return 0;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}