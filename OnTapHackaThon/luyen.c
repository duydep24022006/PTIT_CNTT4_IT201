#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Stack
{
    int id;
    char name[50];
    int priority;
    char dealine[20];
}Stack;
typedef struct NodeSingly
{
    Stack *stack;
    struct NodeSingly *next;
}NodeSingly;
typedef struct NodeDoubly
{
    Stack *stack;
    struct NodeDoubly *next;
    struct NodeDoubly *prev;

}NodeDoubly;

NodeSingly* createNodeSingly(Stack *stack)
{
    NodeSingly *newNodeSingly = (NodeSingly*)malloc(sizeof(NodeSingly));
    newNodeSingly->stack = stack;
    newNodeSingly->next = NULL;
    return newNodeSingly;
}
NodeDoubly* createNodeDoubly(Stack *stack)
{
    NodeDoubly* newNodeDoubly = (NodeDoubly*)malloc(sizeof(NodeDoubly));
    newNodeDoubly->stack = stack;
    newNodeDoubly->next = NULL;
    newNodeDoubly->prev = NULL;
    return newNodeDoubly;
}
void removeSingly(NodeSingly** headSingly,NodeDoubly** headDoubly,int id)
{
    if (*headSingly == NULL)
    {
        printf("Khong co nhiem vu nao\n");
        return;
    }
    NodeSingly *temp = *headSingly;
    NodeSingly *prev = NULL;
    while (temp != NULL && temp->stack->id!=id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Khong tim thay nhiem vu co Id: %d\n",id);
        return;
    }
    NodeDoubly *newNodeDoubly = createNodeDoubly(temp->stack);
    if (*headDoubly == NULL)
    {
        *headDoubly = newNodeDoubly;
    }else
    {
        newNodeDoubly ->next =*headDoubly;
        (*headDoubly)->prev = newNodeDoubly;
        *headDoubly = newNodeDoubly;
    }
    if (prev == NULL)
    {
        *headSingly=temp->next;
    }else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("nhiem vu da hoan thanh\n");
}

void printMenu()
{
    printf("        MENU\n");
    printf("1. Them nhiem vu.\n");
    printf("2. Hien thi danh sach nhiem vu.\n");
    printf("3. Xoa nhiem vu.\n");
    printf("4. Cap nhat thong tin nhiem vu.\n");
    printf("5. Danh dau nhiem vu da hoan thanh.\n");
    printf("6. Sap xep nhiem vu.\n");
    printf("7. Tim kiem nhiem vu\n");
    printf("8. Thoat chuong trinh.\n");
    printf("Lua chon cua ban: ");
}
void inserNodeSingly(NodeSingly **head, Stack *stack)
{
    NodeSingly *newNodeSingly = createNodeSingly(stack);
    if (*head == NULL)
    {
        *head = newNodeSingly;
        newNodeSingly->next = NULL;
        printf("Them nhiem vu thanh cong.\n");
        return;
    }
    NodeSingly *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNodeSingly;
    newNodeSingly->next = NULL;
    printf("Them nhiem vu thanh cong.\n");
}
void printfNode(NodeSingly *head)
{
    if (head == NULL)
    {
        printf("khong co nhiem vu nao!\n");
        return;
    }
    NodeSingly *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        printf("Nhiem vu thu: %d\n",count++);
        printf("ma: %d\n",temp->stack->id);
        printf("Tieu de: %s\n",temp->stack->name);
        printf("Muc do uu tien: %d\n",temp->stack->priority);
        printf("Thoi gian hoan thanh: %s\n",temp->stack->dealine);
        printf("\n");
        temp = temp->next;
    }
}
void removeNodeSingly(NodeSingly **head, int id)
{
    if (*head == NULL)
    {
        printf("khong co nhiem vu nao!\n");
        return;
    }
    NodeSingly *temp = *head;
    NodeSingly *prev = NULL;
    while (temp != NULL &&  temp->stack->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong tim thay ID!\n");
        return;
    }
    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;
    free(temp->stack);
    free(temp);
    printf("xoa thanh cong nhiem vi co ID :%d\n",id);
}
void editNodeSingly(NodeSingly **head, int id)
{
    if (*head == NULL)
    {
        printf("khong co nhiem vu nao!\n");
        return;
    }
    NodeSingly *temp = *head;
    while (temp != NULL &&  temp->stack->id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong tim thay ID!\n");
        return;
    }
    printf("Tieu de nhiem vu: ");
    getchar();
    fgets(temp->stack->name,sizeof(temp->stack->name),stdin);
    temp->stack->name[strcspn(temp->stack->name,"\n")] = '\0';
    printf("Muc do uu tien cua nhiem vu: ");
    scanf("%d",&temp->stack->priority);
    getchar();
    printf("thoi gian hoan thanh nhiem vu: ");
    fgets(temp->stack->dealine,sizeof(temp->stack->dealine),stdin);
    temp->stack->dealine[strcspn(temp->stack->dealine,"\n")] = '\0';

}
void bubbleSort(NodeSingly *head)
{
    if (head == NULL||head->next == NULL)
    {
        return;
    }
    int swapped;
    NodeSingly *ptr;
    Stack *tempStack;
    do
    {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->stack->priority > ptr->next->stack->priority)
            {
                tempStack = ptr->stack;
                ptr->stack = ptr->next->stack;
                ptr->next->stack = tempStack;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    }while (swapped);
    printf("Da xap xep thanh cong!\n");
}
void searchAtName(NodeSingly *head,const char *name)
{
    if (head == NULL)
    {
        printf("khong co nhiem vu nao!\n");
        return;
    }
    NodeSingly *temp = head;
    while (temp != NULL && strcmp(temp->stack->name,name)!=0)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong tim thay: %s\n",name);
        return;
    }
    printf("ma: %d\n",temp->stack->id);
    printf("Tieu de: %s\n",temp->stack->name);
    printf("Muc do uu tien: %d\n",temp->stack->priority);
    printf("Thoi gian hoan thanh: %s\n",temp->stack->dealine);

}


void freeNodeSingly(NodeSingly **head)
{
    if (*head == NULL)
    {
        return;
    }
    NodeSingly *temp = *head;
    while (temp != NULL)
    {
        NodeSingly *temp2 = temp;
        free(temp->stack);
        free(temp2);
        temp = temp->next;
    }
    *head = NULL;
}
void freeNodeDoubly(NodeDoubly **head)
{
    if (*head == NULL)
    {
        return;
    }
    NodeDoubly *temp = *head;
    while (temp != NULL)
    {
        NodeDoubly *temp2 = temp;
        free(temp->stack);
        free(temp2);
        temp = temp->next;
    }
    *head = NULL;
}
int main()
{
    int choice;
    NodeSingly *headSingly = NULL;
    NodeDoubly *headDoubly = NULL;
    do
    {
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Stack* stack=(Stack*)malloc(sizeof(Stack));
                printf("Ma nhiem vu: ");
                scanf("%d",&stack->id);
                getchar();
                printf("Tieu de nhiem vu: ");
                fgets(stack->name,sizeof(stack->name),stdin);
                stack->name[strcspn(stack->name,"\n")] = '\0';

                printf("Muc do uu tien cua nhiem vu: ");
                scanf("%d",&stack->priority);
                getchar();

                printf("thoi gian hoan thanh nhiem vu: ");
                fgets(stack->dealine,sizeof(stack->dealine),stdin);
                stack->dealine[strcspn(stack->dealine,"\n")] = '\0';

                inserNodeSingly(&headSingly, stack);
                break;
            case 2:
                printfNode(headSingly);
                break;
            case 3:
                int id;
                printf("Ma nhiem vu can tim: ");
                scanf("%d",&id);
                removeNodeSingly(&headSingly, id);
                break;
            case 4:
                printf("Ma nhiem vu can sua: ");
                scanf("%d",&id);
                editNodeSingly(&headSingly, id);
                break;
            case 5:
                printf("Ma nhiem vu can sua: ");
                scanf("%d",&id);
                removeSingly(&headSingly,&headDoubly,id);
                break;
            case 6:
                bubbleSort(headSingly);
                break;
            case 7:
                char name[100];
                printf("Tieu de nhiem vu: ");
                getchar();
                fgets(name,sizeof(name),stdin);
                name[strcspn(name,"\n")] = '\0';
                searchAtName(headSingly, name);
                break;
            case 8:
                freeNodeSingly(&headSingly);
                freeNodeDoubly(&headDoubly);
                printf("thoat chuong trinh thanh cong");
                break;
            default:
                printf("loi cu phap\n");
        }
    }while (choice!=8);
    return 0;
}