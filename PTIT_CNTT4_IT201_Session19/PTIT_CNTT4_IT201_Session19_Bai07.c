#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("Memory allocation failed for node.\n");
        return 0;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void addValue(Node* root, int value) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}
void inorder(Node* root)
{
    if(root == NULL)
    {

        return;
    }
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);

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
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int key=7;
    addValue(root,key);
    printf("Preorder: ");
    inorder(root);
    freeNode(root);
    return 0;
}