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



void levelorder(Node* root,int key)
{
    if (root == NULL) return;
    int countLeft = 0;
    int countRight = 0;
    Node* queue[100];
    int front=0, rear=0;
    queue[rear++] = root;
    while (front<rear)
    {
        Node* current=queue[front++];
        if (current->data==key)
        {
            printf("Node level: 0");
            return;
        }
        if (key==current->left->data)
        {
            printf("Node level: %d",++countLeft);
            return;
        }
        if (current->left!=NULL)
        {
            queue[rear++]=current->left;
            countLeft++;
        }
        if (key==current->right->data)
        {
            printf("Node level:%d",++countRight);
            return;
        }
        if (current->right!=NULL)
        {
            queue[rear++]=current->right;
            countRight++;
        }
    }
    printf("khong ton tai\n");
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