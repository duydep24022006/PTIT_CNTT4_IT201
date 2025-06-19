#include <stdio.h>
#include <stdlib.h>

int input(int *arr,int n);
void output(int *arr,int n);


int main()
{
    int n,t;
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
    output(arr,n);

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

void output(int *arr,int n)
{
    for(int i=n-1;i>=0;--i)
    {
        printf("%d ",arr[i]);
    }
}