#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    char name[50];
    int age;
} user;


void toLowerStr(char *dest, const char *src) {
    for (int i = 0; src[i]; i++) {
        dest[i] = tolower((unsigned char)src[i]);
    }
    dest[strlen(src)] = '\0';
}

int main() {
    int flag = -1;
    char str[50];
    user *list[5];


    for (int i = 0; i < 5; i++) {
        list[i] = malloc(sizeof(user));

        printf("Sinh vien thu %d\n", i + 1);
        list[i]->id = i;

        printf("Moi ban nhap ten: ");
        fgets(list[i]->name, sizeof(list[i]->name), stdin);
        list[i]->name[strcspn(list[i]->name, "\n")] = '\0';

        printf("Moi ban nhap tuoi: ");
        scanf("%d", &list[i]->age);
        getchar();
    }

    printf("\nMoi ban nhap ten cua sinh vien can tim (co the nhap mot phan): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char target[50], temp[50];
    toLowerStr(target, str);

    for (int i = 0; i < 5; i++) {
        toLowerStr(temp, list[i]->name);
        if (strstr(temp, target) != NULL) {
            flag = 1;
            printf("{id=%d, name=%s, age=%d}\n", list[i]->id, list[i]->name, list[i]->age);
        }
    }

    if (flag == -1) {
        printf("Khong tim thay sinh vien nao phu hop.\n");
    }


    for (int i = 0; i < 5; i++) {
        free(list[i]);
    }

    return 0;
}
