#include <stdio.h>

int toSum(int n);

int main()
{
    int number,res;
    printf("number = ");
    scanf("%d",&number);
    if (number<0) return 0;
    res=toSum(number);
    printf("%d",res);

    return 0;
}

int toSum(int n)
{
    if (n<10) return n;
    return toSum(n/10)+(n%10);
}