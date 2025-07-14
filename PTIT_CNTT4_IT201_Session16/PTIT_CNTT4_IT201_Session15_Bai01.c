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
int main()
{
    Queue* queue = createQueue();
    free (queue);
    return 0;
}