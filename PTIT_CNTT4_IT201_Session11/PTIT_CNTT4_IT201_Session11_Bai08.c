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
void deleteAtIndex(Node** head,int pos)
{

    if (*head==NULL||pos>lengthList(*head)-1) return;
    Node* temp=*head;
    if( pos==0)
    {
        if(temp->next!=NULL)
        {
            (*head)->prev=NULL;
        }
        free(temp);
        return;
    }

    int index=0;

    while(temp!=NULL&&index<pos-1)
    {
        temp=temp->next;
        index++;
    }

    if (temp==NULL) return;

    if (pos==lengthList(*head)-1)
    {
        if(temp->next==NULL)
        {
            free(*head);
            *head=NULL;
        }

        temp->next->prev=NULL;
    }
    Node* nextNode=temp->next;
    Node* prevNode=temp->prev;
    Node* curr=temp;

    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    free(temp);


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

    int index;

    printf("index=");
    scanf("%d",&index);
    deleteAtIndex(&head, index);
    printfList( head);

    freeList(head);
    return 0;
}
