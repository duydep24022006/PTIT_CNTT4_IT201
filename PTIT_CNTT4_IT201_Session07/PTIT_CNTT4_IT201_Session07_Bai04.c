#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void renderArr (char str[],int n);
void insertionSort( char str[],int n);

int main()
{
    char str[50];
    printf("str = ");
    scanf("%s", &str);
    if (isspace(str[0]))
    {
        printf("chuoi khong hop le");
        return 0;
    }

    printf("before: ");
    renderArr (str, strlen(str));
    printf("\n");

    insertionSort( str, strlen(str));

    printf(" after: ");
    renderArr (str, strlen(str));

    return 0;

}

void renderArr (char str[],int n)
{
    for (int i = 0; i < n; i++) printf("%c",str[i]);

}

void insertionSort( char str[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key)
        {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}
