#include <stdio.h>
#include <stdlib.h>


#define MAX_VALUE 1000


int input(int *arr,int n);
void countOccurrences(int arr[], int n);

int main() {

    int n;
    int *arr;
    do
    {
        scanf("%d",&n);
        if (n<=0||n>100)
        {
            printf("khong hop le\n");
        };

    }while (n<=0||n>100);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return 1;
    }

    input(arr,n);
    countOccurrences(arr,n);

    free(arr);
    return 0;
}

int input(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void countOccurrences(int arr[], int n) {
    int frequency[MAX_VALUE] = {0};
    int maxValue = arr[0];
    int minValue = arr[0];
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
        if (maxValue < arr[i]) maxValue = arr[i];
        if (minValue > arr[i]) minValue = arr[i];
    }
    for (int i = minValue; i <= maxValue; i++) {
        if (frequency[i] > 0) {
            printf("Phan tu %d xuat hien %d lan\n", i, frequency[i]);
        }
    }
}


