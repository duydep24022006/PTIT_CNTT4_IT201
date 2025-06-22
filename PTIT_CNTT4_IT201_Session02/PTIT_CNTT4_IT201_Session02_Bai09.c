#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000

typedef struct {
    int value;
    int count;
}Element;

int input(int *arr,int n);
void countOccurrences(int arr[], int n);

int main() {

    int n, *arr;
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
    Element frequency[MAX_VALUE]= {0};

    int countMax=0;
    for (int i = 0; i < n; i++) {
        if ( frequency[arr[i]].count == 0) {
            frequency[arr[i]].value=arr[i];
        }

        frequency[arr[i]].count++;
        if (frequency[arr[i]].count>countMax) countMax = frequency[arr[i]].value;
    }
    printf("Phan tu %d xuat hien %d lan\n", frequency[countMax].value, frequency[countMax].count);
}


