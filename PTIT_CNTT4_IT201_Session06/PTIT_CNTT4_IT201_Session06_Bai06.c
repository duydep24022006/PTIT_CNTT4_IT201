#include <stdio.h>

int countWay(int n,int count);

int main()
{
    int n,result,count=0;
    printf("n = ");
    scanf("%d", &n);

    result= countWay(n,count);
    printf("%d\n", result);
    return 0;
}

int countWay(int n,int count)
{
    if (count > n) return 0;
    if (count ==n) return 1;

    return countWay(n,count+1)+countWay(n,count+2);

}