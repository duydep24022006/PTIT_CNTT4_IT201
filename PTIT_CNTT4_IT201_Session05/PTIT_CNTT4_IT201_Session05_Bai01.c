#include <stdio.h>


void renderToN(int n);

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf(" khong hop le\n");
        return 0;
    }
    renderToN(n);
}

void renderToN(int n)
{
    if (n<1) return;

    renderToN(n-1);
    printf("%d ", n);
}