#include <stdio.h>


int sumToN(int firstNum,int secondNum);


int main()
{
    int firstNum,seconndNum,sum;
    printf("firstNum = ");
    scanf("%d", &firstNum);
    printf("secondNum = ");
    scanf("%d", &seconndNum);

    if (firstNum < 0||seconndNum < 0)
    {
        printf("khong hop le\n");
        return 0;
    }
    sum=sumToN(firstNum,seconndNum);
    printf("%d\n", sum);
}

int sumToN(int firstNum,int secondNum)
{
    if (firstNum==secondNum) return 0;
    return secondNum+sumToN(firstNum+1,secondNum);
}