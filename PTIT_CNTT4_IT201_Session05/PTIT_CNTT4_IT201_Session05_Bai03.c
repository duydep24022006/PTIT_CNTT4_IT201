#include <stdio.h>


int sumToN(int n);

int main()
{
    int n,sum;
    printf("n = ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("khong hop le\n");
        return 0;
    }
    sum=sumToN(n);
    printf("%d\n", sum);
}

int sumToN(int n)
{
    if (n==0) return 1;

    return n*sumToN(n-1);
}