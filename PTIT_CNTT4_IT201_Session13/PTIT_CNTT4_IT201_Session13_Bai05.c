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

int isFull(Stack* stack)
{
    if (stack->top==stack->capacity-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack* stack)
{
    if (stack->top==-1) return 1;

    return 0;
}

int push(Stack* stack, int value)
{
    if (isFull(stack))
    {
        return 0;
    }

    stack->top++;
    stack->arr[stack->top]=value;
    return 1;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    stack->top--;
    return stack->arr[stack->top];
}
int peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;

    }
    return stack->arr[stack->top];

}

void reverse(Stack** stack)
{
    if (isEmpty(*stack)) return;

    for (int i=0;i<(*stack)->top/2;i++)
    {
        int temp=(*stack)->arr[i];
        (*stack)->arr[i]=(*stack)->arr[((*stack)->top)-i];
        (*stack)->arr[((*stack)->top)-i]=temp;
    }
}
int main()
{
    Stack* myStack = createStack(5);

    int value;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &value);
        push(myStack, value);
    }

    printf("stack={ \n elements:[");
    for (int i = 0; i < 5; i++)
    {
        printf("%d,", myStack->arr[i]);
    }
    printf("],");
    printf("\n top=%d,\n", myStack->top);
    printf(" cap: %d\n", myStack->capacity);
    printf("}");
    printf("\n");
    reverse(&myStack);
    printf("stack={ \n elements:[");
    for (int i = 0; i < 5; i++)
    {
        printf("%d,", myStack->arr[i]);
    }
    printf("],");
    printf("\n top=%d,\n", myStack->top);
    printf(" cap: %d\n", myStack->capacity);
    printf("}");

    free(myStack->arr);
    free(myStack);
}