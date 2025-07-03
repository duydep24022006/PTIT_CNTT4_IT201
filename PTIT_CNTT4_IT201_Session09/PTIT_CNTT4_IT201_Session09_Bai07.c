#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("error");
        exit(1);
    }
    newNode->data = value;
    newNode->next=NULL;
    return newNode;
}
void insertAtIndex(Node** head,int index,int value){
    Node* newNode=createNode((value));

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

int getLength(Node* head)
{
    if(head==NULL)
        return 0;
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int length,value,index;
    Node* n1 = createNode(10);
    Node* n2 = createNode(20);
    Node* n3 = createNode(30);
    Node* n4 = createNode(40);
    Node* n5 = createNode(50);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Node* head=n1;


    printf("value = ");
    scanf("%d",&value);
    printf("index = ");
    scanf("%d",&index);
    length=getLength(head);
    if(index>length||index<0)
    {
        printf("vi tri khong hop le");
        return 0;
    }
    insertAtIndex(&head,index, value);
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    freeList(head);
    return 0;

}