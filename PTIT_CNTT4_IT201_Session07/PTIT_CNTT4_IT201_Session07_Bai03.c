#include <stdio.h>
#include <stdlib.h>

void renderArr (int arr[],int n);
void insertionSort( int arr[],int n);

int main()
{
    int n,*arr;
    printf("n = ");
    scanf("%d", &n);
    if (n<=0) return 0;
    arr= (int *)malloc(n*sizeof(int));
    if (arr == NULL) return 0;

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("before: ");
    renderArr (arr, n);
    printf("\n");

    insertionSort( arr, n);

    printf(" after: ");

    renderArr (arr, n);
    free(arr);
    return 0;

}

void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);

}

void insertionSort( int arr[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
