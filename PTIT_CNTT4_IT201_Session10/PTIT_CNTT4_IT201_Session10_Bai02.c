#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed !");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void printfList(Node* head)
{
    while(head != NULL)
    {
        printf("\nNode: %d ", head->value);
        head = head->next;
    }
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
    Node* head=createNode(1);
    Node* n1=createNode(2);
    Node* n2=createNode(3);
    Node* n3=createNode(4);
    Node* n4=createNode(5);

    head->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;

    printfList(head);
    freeList(head);
}