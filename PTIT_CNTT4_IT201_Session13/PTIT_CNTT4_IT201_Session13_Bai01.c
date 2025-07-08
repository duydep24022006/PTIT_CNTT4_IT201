#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int maxSize)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack==NULL)
    {
        return NULL;
    }

    stack->arr = (int*)malloc(maxSize*sizeof(int));
    if (stack->arr==NULL)
    {
        free(stack);
        return NULL;
    }
    stack->top=-1;
    stack->capacity=maxSize;
    return stack;
}


int main()
{
    Stack* myStack = createStack(5);

    free(myStack->arr);
    free(myStack);
}