#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    int value;
    int count;
}Element;

int input(int *arr,int n);
int findIndex(Element stats[], int size,int value);
void finDuplicates(int arr[], int n) ;



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
    finDuplicates(arr,n);

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

int findIndex(Element stats[], int size,int value) {
    for (int i = 0; i < size; i++) {
        if (stats[i].value == value) {
            return i;
        }

    }
    return -1;
}
void finDuplicates(int arr[], int n) {
    Element stats[MAX];
    Element statsMax[MAX];
    int countMax = 1;
    int size = 0;
    for (int i = 0; i < n; i++) {
        int index = findIndex(stats, size,arr[i]);
        if (index == -1) {
            stats[size].value = arr[i];
            stats[size].count = 1;
            size++;

        }else {
            stats[index].count++;
            if (countMax<stats[index].count) {
                countMax=stats[index].count;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("Gia tri %d xuat hien %d lan\n", stats[i].value, stats[i].count);
    }


}


