#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
struct Node *top = NULL;

int push()
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter a value: ");
    scanf("%d", &tmp->data);

    tmp->next = NULL;

    if (top == NULL)
    {
        start = tmp;
        top = tmp;
    }
    else
    {
        top->next = tmp;
        top = top->next;
    }
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underloaded");
    }
    else if (start->next == NULL) // If only one element in list
    {
        // free(start);
        free(top);
        start = NULL;
        top = NULL;
    }

    else // More than One element
    {
        struct Node *curr = top;
        struct Node *prev = start;

        while (prev->next != top)
        {
            prev = prev->next;
        }
        free(curr);
        top = prev;
        top->next = NULL;
    }
}

int printStack()
{
    struct Node *cur = start;

    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
}

int main()
{
    printf("\n****Stack (Array)***");
    int j;
    while (j != 4)
    {
        printf("\nEnter\n   1. push     2. pop      3. Print       4. Exit\n");
        scanf("%d", &j);

        if (j == 1)
        {
            push();
        }
        if (j == 2)
        {
            pop();
        }
        if (j == 3)
        {
            printStack();
        }
    }
    return 0;
}