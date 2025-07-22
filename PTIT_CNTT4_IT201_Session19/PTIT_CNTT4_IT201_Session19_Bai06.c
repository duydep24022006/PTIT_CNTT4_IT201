#include <stdio.h>
#include <stdlib.h>

#define Max_QUEUE 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed for node.\n");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

typedef struct Queue {
    Node* item[Max_QUEUE];
    int front;
    int rear;
} Queue;

void createQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

int isFull(Queue* queue) {
    return queue->rear >= Max_QUEUE;
}

void enQueue(Queue* queue, Node* node) {
    if (!isFull(queue)) {
        queue->item[queue->rear++] = node;
    }
}

Node* deQueue(Queue* queue) {
    if (!isQueueEmpty(queue)) {
        return queue->item[queue->front++];
    }
    return NULL;
}

int findValueBFS(Node* root, int key) {
    if (root == NULL) return 0;

    Queue q;
    createQueue(&q);
    enQueue(&q, root);

    while (!isQueueEmpty(&q)) {
        Node* current = deQueue(&q);

        if (current->data == key)
            return 1;

        if (current->left)
            enQueue(&q, current->left);
        if (current->right)
            enQueue(&q, current->right);
    }

    return 0;
}

void freeNode(Node* root) {
    if (root == NULL) return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int key;
    printf("Gia tri can tim: ");
    scanf("%d", &key);

    if (findValueBFS(root, key)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    freeNode(root);
    return 0;
}
