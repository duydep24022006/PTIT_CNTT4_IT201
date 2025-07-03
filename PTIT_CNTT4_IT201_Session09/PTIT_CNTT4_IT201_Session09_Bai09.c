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

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;    // 1. Giữ node tiếp theo998
        curr->next = prev;    // 2. Đảo chiều con trỏ
        prev = curr;          // 3. Cập nhật prev
        curr = next;          // 4. Di chuyển tới node tiếp theo
    }

    *head = prev; // cập nhật node đầu mới sau khi đảo xong
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


    reverseList(&head);
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
