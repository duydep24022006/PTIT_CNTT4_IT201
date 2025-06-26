#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isSymmetric(char str[],int left,int right);
void normalizeString(char *src,char *dst);

int main()
{
    char str[100],procrssed[100];
    printf("moi ban nhap vao chuoi gia tri: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';

    normalizeString(str,procrssed);

    if (isSymmetric(procrssed,0,strlen(procrssed)-1))
    {
        printf("Palindrome valid\n");

    }else printf("Palindrome invalid\n");

    return 0;

}

int isSymmetric(char str[],int left,int right)
{
    if (left>right) return 1;
    if (str[left]!=str[right]) return 0;
    return isSymmetric(str,left+1,right-1);
}

void normalizeString(char *src,char *dst)
{
    int j=0;
    for(int i;src[i]!='\0';i++)
    {
        if (isalnum(src[i]))
        {
            dst[j++]= tolower(src[i]);
        }
    }
    dst[j]='\0';
}

