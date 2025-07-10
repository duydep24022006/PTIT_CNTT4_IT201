#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct Stack
{
    Node *top;
}Stack;

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
int isEmpty(Stack *stack)
{
    return 0;
}
int isFull(Stack *myStack)
{
    if (myStack->top == NULL) return 1;
    return 0;
}
void push(Stack *stack, int value)
{
    Node *newNode = createNode(value);
    newNode->next = stack->top;
    if (stack->top != NULL)
    {
        stack->top->prev = newNode;
    }
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    if (stack->top != NULL)
    {
        stack->top->prev = NULL;
    }

    free(temp);
    return value;
}

void freeStack(Stack *myStack)
{
    if (myStack->top != NULL) return;

    while (myStack->top != NULL)
    {
        pop(myStack);
    }
    free(myStack);
}

int peek(Stack *myStack)
{
    if (myStack->top == NULL) return -1;
    return myStack->top->value;
}

void printStack(Stack *myStack)
{
    Node *temp = myStack->top;

    if (isEmpty(myStack)) return;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Stack *myStack = createStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    freeStack(myStack);
    return 0;
}