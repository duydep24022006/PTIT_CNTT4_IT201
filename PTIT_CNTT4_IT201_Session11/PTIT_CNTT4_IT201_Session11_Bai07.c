#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printfList(Node* head)
{
    if(head==NULL) return;

    Node* temp=head;
    while(temp->next!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;

    }
    printf("%d->",temp->data);
    printf("NULL\n");

}

void insertAtIndex(Node** head,int pos,int data)
{
    Node* newNode=createNode(data);

    if (*head==NULL||pos==0)
    {
        newNode->next=*head;
        if(*head!=NULL) (*head)->prev=newNode;
        *head=newNode;
        return;
    }

    Node* temp=*head;
    int index=0;

    while(temp!=NULL&&index<pos-1)
    {
        temp=temp->next;
        index++;
    }


    if (temp==NULL)
    {
        free(newNode);
        return;
    }

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL) temp->next->prev=newNode;

    temp->next=newNode;

}
void freeList(Node* head)
{
    if(head==NULL) return;
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* temp1=temp->next;
        free(temp);
        temp=temp1;
    }

}
int main()
{

    Node* Node1=createNode(1);
    Node* Node2=createNode(2);
    Node* Node3=createNode(3);
    Node* Node4=createNode(4);
    Node* Node5=createNode(5);


    Node1->prev=NULL;
    Node1->next=Node2;
    Node2->prev=Node1;
    Node2->next=Node3;
    Node3->prev=Node2;
    Node3->next=Node4;
    Node4->prev=Node3;
    Node4->next=Node5;
    Node5->prev=Node4;
    Node5->next=NULL;

    Node* head= Node1;
    printfList( head);

    int value,index;
    printf("value=");
    scanf("%d",&value);
    printf("index=");
    scanf("%d",&index);
    insertAtIndex(&head, index, value);
    printfList( head);

    freeList(head);
    return 0;
}
