#include <stdio.h>
#include <stdlib.h>


int input(int *arr,int n);
void targetCount(int *arr,int n,int t);


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
    printf("moi ban nhap vao gia tri can tim kiem: ");
    scanf("%d",&t );

    targetCount(arr,n,t);
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

void targetCount(int *arr,int n,int t)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if (t==arr[i])
        {
            count++;
        }
    }
    printf("%d",count);
}




