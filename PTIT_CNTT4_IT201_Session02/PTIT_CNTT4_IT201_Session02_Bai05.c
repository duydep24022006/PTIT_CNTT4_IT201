#include <stdio.h>
#include <stdlib.h>

int input(int *arr,int n);
int deleteArr(int *arr,int n,int index);
void output(int *arr,int n);


int main()
{
    int n,deleteIndex;
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

    printf("vi tri can xoa: ");
    scanf("%d",&deleteIndex);
    if (deleteIndex>n-1)
    {
        printf("khong hop le\n");
    }else
    {
        deleteArr(arr,n,deleteIndex);
        output(arr,n);
    }





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

int deleteArr(int *arr,int n,int index)
{
    for(int i=index;i<n-1;i++)
    {
       arr[i]=arr[i+1];
    }
    return n - 1;
}

void output(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}