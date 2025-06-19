#include <stdio.h>
#include <stdlib.h>

int input(int *arr,int n);
int addArr(int *arr,int *n,int pos,int value);
void output(int *arr,int n);


int main()
{
    int n,pos,value;
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

    printf("position: ");
    scanf("%d",&pos);
    printf("value: ");
    scanf("%d",&value);
    if (pos<=0||pos>n)
    {
        printf("khong hop le\n");
    }else
    {
        addArr(arr,&n,pos,value);
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

int addArr(int *arr,int *n,int pos,int value)
{
    for(int i=*n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];

    }
     arr[pos]=value;

    return (*n)++;
}


void output(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}