#include <stdio.h>
#include <stdlib.h>

void renderArr (int arr[],int n);
void selectionSort( int arr[],int n);

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

    selectionSort( arr, n);

    printf(" after: ");

    renderArr (arr, n);
    free(arr);
    return 0;

}

void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);

}

void selectionSort( int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
