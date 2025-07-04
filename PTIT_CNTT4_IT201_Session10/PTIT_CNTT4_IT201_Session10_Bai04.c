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


void deleteAtValue(Node** head, Node** tail) {
    if (*head == NULL) {
        return;
    }
    if (*head==*tail)
    {
        free(*head);
        *head=*tail=NULL;
        return;
    }
    Node*temp=*head;
    while(temp->next!= *tail)
    {
        temp=temp->next;
    }
    free(*tail);
    *tail=temp;
    (*tail)->next=NULL;
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

    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(4);
    Node* n5 = createNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Node* head=n1;
    Node* tail=n5;

    deleteLast(&head, &tail);
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