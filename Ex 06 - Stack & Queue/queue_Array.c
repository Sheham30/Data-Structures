#include <stdio.h>

int front = 0;
int rear = 0;
#define size 5
int stack[size];

int enQueue()
{
    if (stack[rear] != NULL) {
        printf("Queue Overflow");
    }
    else {
        int a;
        printf("Enter a value: ");
        scanf("%d", &a);
        stack[rear] = a;
        // rear++;
        rear = (rear+1) % size;
    }
}

int deQueue()
{
    if (rear == front && stack[front] == NULL) {
        printf("Queue Underflow");
    }
    else {
        int b = stack[front];
        stack[front] = 0;
        front++;
        printf("Removed value: %d", b);
    }
    
}

int printStack()
{
    for (int i=0; i<size; i++)
    {
        printf("%d\t", stack[i]);
    }
}

int main()
{
     printf("\n***********Queue (Array)**********");
    int j;
    while (j != 4)
    {
        printf("\nEnter\n   1. enQueue     2. deQueue      3. Print       4. Exit\n");
        scanf("%d", &j);

        if (j == 1){
            enQueue();
        }
        if (j == 2){
            deQueue();
        }
        if (j == 3){
            printStack();
        }
    }
    return 0;
}
