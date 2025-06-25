#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[50];
    int age;
}user;

int main()
{
    int k;
    user *list[5];
    for(int i=0;i<5;i++)
    {
        list[i] = malloc(sizeof(user));

        printf("sinh vien thu %d\n",i+1);

        list[i]->id=i;
        printf("moi ban nhap ten: ");
        fgets(list[i]->name,sizeof(list[i]->name),stdin);
        list[i]->name[strcspn(list[i]->name, "\n")] = '\0';

        printf("moi ban nhap tuoi: ");
        scanf("%d",&list[i]->age);
        getchar();
    }

    printf("moi ban nhap vi tri sinh vien can tim: ");
    scanf("%d",&k);
    if (k<0||k>4)
    {
        printf("sinh vien khong ton tai");
    }else
    {
        printf("{id:%d,name:%s,age:%d}",list[k]->id,list[k]->name,list[k]->age);

    }
    for(int i=0;i<5;i++)
    {
        free(list[i]);
    }
    return 0;
}