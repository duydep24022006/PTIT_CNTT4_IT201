#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task
{
    int id;
    char title[50];
    int priority;
    char dealine[20];
}Task;
typedef struct NodeSingly
{
    Task* tasks;
    struct NodeSingly* next;
}NodeSingly;
typedef struct NodeDoubly
{
    Task* tasks;
    struct NodeDoubly* next;
    struct NodeDoubly* prev;
}NodeDoubly;

NodeSingly* createNodeSingly(Task *task)
{
    NodeSingly* newNode = (NodeSingly*)malloc(sizeof(NodeSingly));
    newNode->next = NULL;
    newNode->tasks = task;
    return newNode;
}
NodeDoubly* createNodeDoubly(Task *task)
{
    NodeDoubly* newNode = (NodeDoubly*)malloc(sizeof(NodeDoubly));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->tasks = task;
    return newNode;
}
void printMenu()
{
    printf("        MENU\n");
    printf("1. Them nhiem vu\n");
    printf("2. Hien thi danh sach nhiem vu\n");
    printf("3. Xoa nhiem vu\n");
    printf("4. Cap nhat thong tin nhiem vu\n");
    printf("5. Danh dau nhiem vu hoan thanh\n");
    printf("6. Sap xep nhiem vu\n");
    printf("7. Tim kiem nhiem vu\n");
    printf("8. Thoat truong trinh\n");
    printf("Lua chon cua ban: ");
}
void inserNodeSingly(NodeSingly **head, Task *task)
{
    if(*head == NULL)
    {
        *head = createNodeSingly(task);
        printf("Them nhiem vu thanh cong!\n");
        return;
    }
    NodeSingly *newNode = createNodeSingly(task);
    NodeSingly *temp = *head;
    while(temp->next != NULL)
    {
        if (temp->tasks->id==task->id)
        {
            break;
        }
            temp = temp->next;
    }
    if (temp->next != NULL)
    {
        printf("Id da ton tai\n");
    }
    temp->next = newNode;
    newNode->next = NULL;
    printf("Them nhiem vu thanh cong!\n");

}
void printTasks(NodeSingly *head)
{
    if (head==NULL)
    {
        printf("Khong co nhiem vu trong danh sach!\n");
        return;
    }
    NodeSingly *temp = head;
    int count = 1;
    while(temp != NULL)
    {
        printf("Nhiem vu thu: %d\n",count++);
        printf("ma cua nhiem vu:%d \n",temp->tasks->id);
        printf("Ten cua nhiem vu: %s\n",temp->tasks->title);
        printf("Muc do uu tien cua nhiem vu: %d\n",temp->tasks->priority);
        printf("Thoi gian hoan thanh cua nhiem vu: %s\n",temp->tasks->dealine);
        printf("\n");
        temp = temp->next;
    }
}
int main()
{
    int choice;
    NodeSingly *headSingly=NULL;
    NodeDoubly *headDoubly=NULL;
    do
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                Task* task=(Task*)malloc(sizeof(Task));
                printf("Moi ban nhap ma cua nhiem vu: ");
                scanf("%d",&task->id);
                while (getchar() != '\n');
                printf("Moi ban nhap tieu de cua nhiem vu: ");
                fgets(task->title,sizeof(task->title), stdin);
                task->title[strcspn(task->title,"\n")] = '\0';
                printf("Moi ban nhap muc do uu tien cua nhiem vu: ");
                scanf("%d",&task->priority);
                while (getchar() != '\n');
                printf("Moi ban nhap thoi gian hoan thanh cua nhiem vu: ");
                fgets(task->dealine,sizeof(task->dealine), stdin);
                task->dealine[strcspn(task->dealine,"\n")] = '\0';

                inserNodeSingly(&headSingly, task);
                break;
            case 2:
                printTasks(headSingly);
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
                printf("Thoat truong trinh thanh cong!\n");
                break;
            default:
                printf("Loi cu phap!\n");
        }
    }
    while (choice!=8);
    return 0;
}