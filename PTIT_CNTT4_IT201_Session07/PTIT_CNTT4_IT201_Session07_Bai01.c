#include <stdio.h>
#include <stdlib.h>

void renderArr (int arr[],int n);
void bubbleSort( int arr[],int n);

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

    bubbleSort( arr, n);

    printf(" after: ");

    renderArr (arr, n);
    free(arr);
    return 0;

}

void renderArr (int arr[],int n)
{
    for (int i = 0; i < n; i++) printf("%d ",arr[i]);

}

void bubbleSort( int arr[],int n)
{
    int flag=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;
            }

        }
        if (flag!=1)
        {
                break;
        }
    }
}
