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


void findMiddle(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }

    int length = 0;
    Node* temp = head;

    // Đếm độ dài
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int midIndex = length / 2;

    temp = head;
    for (int i = 0; i < midIndex; i++) {
        temp = temp->next;
    }

    printf("Node %d: %d\n", midIndex + 1, temp->data);
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
    int value;
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

    Node* temp=head;
     while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

    printf("\n");

    findMiddle(head);


    freeList(head);
    return 0;

}