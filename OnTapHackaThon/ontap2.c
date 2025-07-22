#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[100];
    struct Node* next;
}Node;
typedef struct Course
{
    char id[50];
    char name[50];
    int Credit;
}Course;

typedef struct NodeSingly
{
    Course course;
    struct NodeSingly* next;
}NodeSingly;
typedef struct NodeDoubly
{
    Course course;
    struct NodeDoubly* next;
    struct NodeDoubly* prev;
}NodeDoubly;
typedef struct Queue
{
    Node* data;
    Node* rear;
    Node* front;
}Queue;

NodeSingly* createNodeSingly(Course course)
{
    NodeSingly* newNode = (NodeSingly*)malloc(sizeof(NodeSingly));
    newNode->course = course;
    newNode->next=NULL;
    return newNode;
}
NodeDoubly* createNodeDoubly(Course course)
{
    NodeDoubly* newNode = (NodeDoubly*)malloc(sizeof(NodeDoubly));
    newNode->course = course;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
Queue* createQueue()
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = 0;
    return newQueue;
}
void enqueue(Queue** queue,const char* name)
{
    Queue *newQueue = createQueue(name);
    if((*queue)->rear == NULL)
    {
        (*queue)->front =(*queue)->rear= newQueue;
    }else
    {
        (*queue)->rear->next=newQueue;
        (*queue)->rear=newQueue;
    }
}
void dequeue(Queue** queue)
{
    if ()
}


void printMenu()
{
    printf("        MENU\n");
    printf("1. Quan ly danh sach mon hoc da dang ki\n");
    printf("2. Tim kiem mon hoc theo ma mon\n");
    printf("3. Sap xep danh sach mon hoc theo ten\n");
    printf("4. Tinh tong so tin chi\n");
    printf("5. Chuyen mon hoc sang danh sach hoan thanh\n");
    printf("6. Hoan tac thao tac theo mon gan nhat\n");
    printf("7. Quan ly danh sach sinh vien cho su ly dang ki mon hoc\n");
    printf("8. Hien thi mon hoc\n");
    printf("9. thoat truong trinh\n");
    printf("Moi ban chon: ");
}
void insertNodeSingly(NodeSingly** head,Course course)
{
    if (*head==NULL)
    {
        *head = createNodeSingly(course);
        (*head)->next=NULL;
        printf("da them thanh cong\n");
        return;
    }

    NodeSingly* temp=*head;
    int flag=1;
    while(temp!=NULL)
    {
        if (strcmp(temp->course.id, course.id) == 0)
        {
            flag=0;
            break;
        }
        if (temp->next==NULL) break;
        temp=temp->next;
    }
    if (flag==0)
    {
        printf("Da ton tai!\n");
        return;
    }
    temp->next=createNodeSingly(course);
    temp->next->next=NULL;
    printf("da them thanh cong\n");
}
void searchId(NodeSingly* head,const char* id)
{
    if (head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    NodeSingly* temp=head;
    while(temp->next!=NULL)
    {
        if (temp->course.id==id) break ;
    }
    if (temp==NULL)
    {
        printf("Khong tim thay mon hoc\n");
        return;
    }
    printf("Ma mon hoc: %s\n",temp->course.id);
    printf("ten mon hoc:%s",temp->course.name);
    printf("so tin chi: %d\n",temp->course.Credit);

}
void bubbleSort(NodeSingly* head) {
    if (head == NULL) return;
    int swapped;
    NodeSingly* ptr;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (strcmp(ptr->course.name, ptr->next->course.name) > 0) {
                Course temp = ptr->course;
                ptr->course = ptr->next->course;
                ptr->next->course = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}
void sumCredit(NodeSingly* head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    NodeSingly* temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum+=temp->course.Credit;
        temp = temp->next;
    }
    printf("Tong so tin chi ban da dang ki: %d\n",sum);
}
void moveToCompletedList(NodeSingly** headSingly,NodeDoubly** headDoubly,const char* id)
{
    if (headSingly==NULL)
    {
        printf("list is empty\n");
        return;
    }
    NodeSingly* temp=*headSingly;
    Course tempCourse;
    NodeSingly* prev=NULL;
    while(temp!=NULL)
    {
        if (strcmp(temp->course.id,id)==0)
        {
            tempCourse=temp->course;
            if (prev == NULL) {
                *headSingly = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev=temp;
        temp = temp->next;
    }

    if (temp==NULL)
    {
        printf("Khong tim thay mon hoc\n");
        return;
    }
    NodeDoubly* newNode=createNodeDoubly(tempCourse);
    if (*headDoubly==NULL)
    {
         *headDoubly=newNode;
    }else
    {
        NodeDoubly* temp2=*headDoubly;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=newNode;
        newNode->prev=temp2;
    }
    printf("Ma mon hoc %s da hoan thanh\n",tempCourse.id);
}
void remoreAtTail(NodeSingly** head)
{
    if (*head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    NodeSingly* temp=*head;
    if(temp->next==NULL)
    {
        free(temp);
        *head=NULL;
        printf("Hoan tac thanh cong\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    free(temp);
    temp=NULL;
    printf("Hoan tac thanh cong\n");
}
void displayList(NodeSingly* head)
{
    if (head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    NodeSingly* temp=head;
    int count=1;
    while (temp!=NULL)
    {
        printf("Mon hoc thu %d: \n",count++);
        printf("Ma mon hoc: %s\n",temp->course.id);
        printf("ten mon hoc:%s",temp->course.name);
        printf("so tin chi: %d\n",temp->course.Credit);
        printf("\n");
        temp=temp->next;
    }

}
void freeList(NodeSingly* head) {
    NodeSingly* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;
    char inputId[50];
    NodeSingly* head=NULL;
    NodeDoubly* headDoubly=NULL;
    do
    {
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Course course;

                printf("Moi ban nhap ma mon hoc: ");
                scanf("%s",course.id);
                getchar();
                printf("Moi ban nhap ten cua mon hoc: ");
                fgets(course.name,50,stdin);
                course.name[strlen(course.name)]='\0';
                printf("Moi ban nhap so tin chi cua mon hoc: ");
                scanf("%d",&course.Credit);
                insertNodeSingly(&head,course);
                break;
            case 2:

                printf("moi ban nhap ma mon hoc: ");
                scanf("%s",inputId);
                searchId(head,inputId);
                break;
            case 3:
                bubbleSort(head);
                break;
            case 4:
                sumCredit(head);
                break;
            case 5:
                printf("moi ban nhap ma mon hoc: ");
                scanf("%s",inputId);
                moveToCompletedList(&head,&headDoubly, inputId);
                break;
            case 6:
                remoreAtTail(&head);
                break;
            case 7:
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                freeList(head);
                freeList(headDoubly);
                printf("cam on!\n");
                break;
            default:
                printf("Loi cu phap!\n");
        }

    }while (choice!=9);
    return 0;
}