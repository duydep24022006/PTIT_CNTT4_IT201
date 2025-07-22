#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    int Credit;
}Crouse;
typedef struct NodeSingly
{
    Crouse data;
    struct NodeSingly *next;

}NodeSingly;

typedef struct NodeDouble
{
    Crouse data;
    struct NodeDouble *next;
    struct NodeDouble *prev;
}NodeDouble;


NodeSingly* createNodeSingly(Crouse data)
{
    NodeSingly *newNode = (NodeSingly*)malloc(sizeof(NodeSingly));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

NodeDouble* createNodeDouble(Crouse data)
{
    NodeDouble *newNode = (NodeDouble*)malloc(sizeof(NodeDouble));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int printMenu()
{
    printf("        MENU\n");
    printf("1. Them khoa hoc\n");
    printf("2. Hien thi danh sach khoa hoc\n");
    printf("3. Xoa khoa hoc\n");
    printf("4. Cap nhat thong tin khoa hoc\n");
    printf("5. Danh dau khoa hoc da hoan thanh\n");
    printf("6. Sap xep khoa hoc theo so tin chi\n");
    printf("7. Tim kiem khoa hoc theo ten\n");
    printf("8. Thoat truong trinh\n");
    printf("Moi ban chon\n");
}
int main()
{
    int choice;
    do
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Ban da thoat thanh cong!\n");
                break;
            default:
                printf("Khong hop le\n");
        }
    }while (choice != 8);
    return 0;
}