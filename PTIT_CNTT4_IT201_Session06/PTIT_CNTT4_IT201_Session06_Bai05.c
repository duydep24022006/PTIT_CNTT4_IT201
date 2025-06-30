#include <stdio.h>
#include <stdlib.h>


int minAndMax(int arr[], int n,int *max,int *min);
int main()
{
    int n, *arr,min,max;
    printf("n = ");
    scanf("%d", &n);
    if (n<=0) return 0;
    arr = (int *)malloc(n*sizeof(int));
    if (arr == NULL) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    min = arr[0];
    max = arr[0];
    minAndMax(arr,n-1,&max, &min);
    printf("min = %d,max = %d\n",min,max);
    free(arr);
    return 0;

}
int minAndMax(int arr[], int n,int *max,int *min)
{
    if (n<=0) return 0;
    if (arr[n] < *min) *min = arr[n];
    if (arr[n] > *max) *max = arr[n];

    return minAndMax(arr, n-1, max, min);
}

