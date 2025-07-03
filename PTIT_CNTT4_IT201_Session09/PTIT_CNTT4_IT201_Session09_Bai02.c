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
int main()
{
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
    Node* temp=head;


    while(temp!=NULL)
    {
        printf("Node %d: %d \n",temp->data,temp->data);
        temp=temp->next;
    }
    printf("\n");

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;

}