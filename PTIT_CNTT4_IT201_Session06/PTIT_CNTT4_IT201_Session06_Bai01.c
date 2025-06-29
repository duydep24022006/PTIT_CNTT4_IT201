#include <stdio.h>

void toBinary(int number);

int main()
{
    int number;
    printf("number = ");
    scanf("%d", &number);
    if (number<0) return 0;
    toBinary(number);

    return 0;
}

void toBinary(int number)
{
    if (number==0) return;
    toBinary(number/2);
    printf("%d", number%2);
}