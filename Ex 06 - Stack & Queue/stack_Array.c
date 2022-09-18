#include <stdio.h>
#include <stdlib.h>

int top = 0;
// int const size = 5;
#define size 5
int stack[size];

int push()
{
    int value;
    printf("Enter a number: ");
    scanf("%d", &value);

    if (top == size)
    {
        printf("\n**Stack Overflow**\n");
    }
    else {
        stack[top] = value;
        top++;
    }
}

int pop()
{
    if (top == 0)
    {
        printf("\n**Stack Underflow**\n");
    }
    else
    {
        top--;
        int a = stack[top];
        stack[top] = 0;
        printf("\nPopped Value: %d\n", a);
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
    printf("\n***********Stack (Array)**********");
    int j;
    while (j != 4)
    {
        printf("\nEnter\n   1. Push     2. Pop      3. Print       4. Exit\n");
        scanf("%d", &j);

        if (j == 1){
            push();
        }
        if (j == 2){
            pop();
        }
        if (j == 3){
            printStack();
        }
    }
    return 0;
}
