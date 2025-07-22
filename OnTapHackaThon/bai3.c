#include <stdio.h>
#include <stdlib.h>


typedef struct Call
{
    char* phone;
    int time;
}Call;
typedef struct Stack
{
    Call* calls;
    int capacity;
    int top;
}Stack;
typedef struct Queue
{
    Call* calls;
    int capacity;
    int front;
    int rear;
}Queue;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->calls = (Call*)malloc(sizeof(Call) * stack->capacity);
    return stack;
}
Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->calls = (Call*)malloc(sizeof(Call) * queue->capacity);
    return queue;
}
int isFullQueue(Queue* queue)
{
    return queue->rear == queue->capacity - 1;
}

int isFullStack(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmptyQueue(Queue* queue)
{
    return queue->rear < queue->front;
}

int isEmptyStack(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack** stack, Call call)
{
    if (!isFullStack(*stack))
    {
        printf("is FullS tack\n");
        return;
    }
    Stack* newStack = (Stack*)malloc(sizeof(call));
    (*stack)->top++;
    (*stack)->calls[(*stack)->top] = call;
}
void printMenu()
{
    printf("        MENU\n");
    printf("1. CALL\n");
    printf("2. BACK\n");
    printf("3. REDIAL\n");
    printf("4. HISTORY\n");
    printf("5. EXIT\n");
    printf("Lua chon cua ban: ");
}
int main()
{
    int choice;
    do{
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }while(choice != 5);
    return 0;
}