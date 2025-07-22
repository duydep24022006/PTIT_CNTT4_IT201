#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node * createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addValue(Node* root, int data)
{
    if (root == NULL) return;

    Node* queue[100];
    int front=0, rear=0;
    queue[rear++] = root;
    while (front<rear)
    {
        Node* current=queue[front++];
        if (current->left==NULL)
        {
            current->left=createNode(data);
            return;
        }else
        {
            queue[rear++]=current->left;
        }
        if (current->right==NULL)
        {
            current->right=createNode(data);
            return;
        }else
        {
            queue[rear++]=current->right;
        }
    }
}

void levelorder(Node* root)
{
    if (root == NULL) return;

    Node* queue[100];
    int front=0, rear=0;
    queue[rear++] = root;
    while (front<rear)
    {
        Node* current=queue[front++];
        printf("%d ", current->data);
        if (current->left!=NULL)
        {
            queue[rear++]=current->left;
        }
        if (current->right!=NULL)
        {
            queue[rear++]=current->right;
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

    printf("Truoc khi them:\n");
    levelorder(root);

    printf("\naddValue: 6\n");
    addValue(root, 6);

    printf("Sau khi them:\n");
    levelorder(root);
    freeNode(root);
    return 0;
}