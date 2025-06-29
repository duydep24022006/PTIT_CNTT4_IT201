#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n,int arr[]);

int main()
{
    int n,*arr;

    printf("n = ");
    scanf("%d",&n);
    if (n<0)
    {
        printf("Input khong hop le");
    }
    arr=(int*)malloc(n*sizeof(int));
    fibonacci(n,arr);
    for(int i=n;i>0;i--) printf("%d ",arr[i]);
    free(arr);
    return 0;
}

int fibonacci(int n,int arr[])
{
    if (n==0) return arr[0]=0;
    if (n==1) return arr[1]=1;
    return arr[n]=fibonacci(n-1,arr)+fibonacci(n-2,arr);
}