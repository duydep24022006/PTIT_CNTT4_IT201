#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Queue
{
    Node** data;
    int front;
    int rear;
    int capacity;
}Queue;
Node * createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Queue* createQueue(int capacity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) return NULL;
    newQueue->data = NULL;
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->capacity = capacity;
    return newQueue;
}
Node* deleteTreeNode(Node* root, int key)
{
    Queue* queue = createQueue(100);
    enQueue(queue,root);

    Node* target=NULL;
    Node* lastNode=NULL;
    Node* lastParent=NULL;
    while (queue->rear != queue->front)
    {
        Node* currentNode = deQueue(queue);
        if (currentNode->data == key)
        {
            target = currentNode;
        }
        if (currentNode->left != NULL)
        {
            enQueue();
        }
    }

}



void freeNode(Node* root)
{
    if(root == NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}
int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("number: 3\n");

    levelorder(root,3);
    freeNode(root);
    return 0;
}