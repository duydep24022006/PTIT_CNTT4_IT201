#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
typedef struct Queue
{
    Node *data[MAX];
    int front,rear;

}Queue;


Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed for Node");
        return 0;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void initQueue(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int isQueueEmpty(Queue* queue)
{
    return  queue->rear == queue->front;
}
int isQueueFull(Queue* queue)
{
    return  (queue->rear+1)%MAX == queue->front;
}

void enQueue(Queue* queue, Node* node)
{
    if(isQueueFull(queue))
    {
        printf("Queue is full");
        return;
    }
    queue->data[queue->rear] = node;
    queue->rear = (queue->rear + 1)%MAX;
}

Node* deQueue(Queue* queue)
{
    if(isQueueEmpty(queue))
    {
        printf("Queue is empty");
        return;
    }
    Node* temp = queue->data[queue->front];
    queue->front=(queue->front+1)%MAX;
    return temp;

}
void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelorder(Node* root)
{
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while(!isQueueEmpty(&q))
    {
        Node* temp = deQueue(&q);
        printf("%d ", temp->data);
        if(temp->left != NULL)
        {
            enQueue(&q, temp->left);
        }
        if(temp->right != NULL)
        {
            enQueue(&q, temp->right);
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
int main(){
    Node* root =createNode(1);
    Node* tr2 =createNode(2);
    Node* tr3 =createNode(3);
    Node* tr4 =createNode(4);
    Node* tr5 =createNode(5);
    root->left = tr2;
    root->right = tr3;
    tr2->left = tr4;
    tr2->right = tr5;
    printf("preorder : ");
    preorder(root);
    printf("\n");
    printf("inorder : ");
    inorder(root);
    printf("\n");
    printf("postorder : ");
    postorder(root);
    printf("\n");
    printf("levelorder : ");
    levelorder(root);
    freeNode(root);
    return 0;
}