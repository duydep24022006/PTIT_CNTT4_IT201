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
    int k,flag=0;
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


    printf("k = ");
    scanf("%d",&k);
    while(temp!=NULL)
    {

        if(temp->data==k)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1) printf("true");
    else printf("false");

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;

}