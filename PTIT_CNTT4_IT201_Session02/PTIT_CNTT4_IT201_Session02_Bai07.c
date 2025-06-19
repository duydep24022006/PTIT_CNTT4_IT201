#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
int input(int *arr,int n);
void findPair(int *arr, int n,int target)
;

int main()
{
    int n,target;
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

    printf("moi ban nhap gia can tinh \n");
    scanf("%d",&target);
    findPair(arr, n,target);

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

void findPair(int *arr, int n,int target)
{
    int hash[2*MAX+1]={0};
    for(int i=0;i<n;i++)
    {
        int complement=target-arr[i];
        if (hash[complement+MAX])
        {
            printf("%d,%d",complement,arr[i]);
            return;
        }
        hash[complement+MAX]=1;

    }
    printf("khong tim thay \n");
}