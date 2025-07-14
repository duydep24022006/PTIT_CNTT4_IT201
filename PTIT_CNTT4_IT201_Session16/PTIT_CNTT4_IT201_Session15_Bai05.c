#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int data;
    struct Node* next;
}Node;
typedef struct
{
    Node* front;
    Node* rear;
}Queue;
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void enQueue(Queue* queue, int data)
{
    Node* newNode = createNode(data);
    if(queue->rear == NULL)
    {
        queue->front=queue->rear = newNode;
    }else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }


}
int isEmpty(Queue* queue)
{
    return queue->rear == NULL;
}

void printqueue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->front;

    printf("front->");
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("rear->%d->NULL\n", queue->rear->data);

}

void freeQueue(Queue* queue)
{
    if(isEmpty(queue)) return;
    Node* temp = queue->front;
    while(temp != NULL)
    {
        Node* temp1 = temp->next;
        free(temp);
        temp = temp1;
    }
}

int main(){
    Queue* queue = createQueue();
    printqueue(queue);
    enQueue(queue, 10);
    printqueue(queue);
    freeQueue(queue);
    return 0;

}