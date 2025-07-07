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
int lengthList(Node* head)
{
    int length=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
void findMidList(Node* head)
{
    if(head==NULL) return;
    if(lengthList(head)==1)
    {
        printf("Node %d: 1",head->data);
    }
    int mid=lengthList(head)/2;
    Node* temp=head;
    int index=1;
    for(int i=0;i<mid;i++)
    {
        temp=temp->next;
        index++;
    }
    if (temp->data%2!=0) printf("Node %d: %d",temp->data,index);
    else printf("Node %d: %d",temp->next->data,index+1);

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

    printfList(head);

    findMidList( head);


    freeList(head);
    return 0;
}
