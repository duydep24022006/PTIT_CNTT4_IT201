#include <stdio.h>
#include <stdlib.h>

int input(int *arr,int n);
int output(int *arr,int n);

int main()
{
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

int output(int *arr,int n)
{

    int max=arr[n-1];
    int *arr2;
    arr2 = (int *)malloc(n * sizeof(int));
    int count=0;
    if (arr2 == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return 1;
    }
    for(int i=n-1;i>=0;--i)
    {
        if (i==n-1||max<arr[i])
        {
            max=arr[i];
            arr2[count]=max;
            count++;
        }
    }
    for(int i=count-1;i>=0;i--)
    {
        printf("%d ",arr2[i]);
    }
    free(arr2);
    return 0;
}